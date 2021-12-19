// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    bool ans = false;
    void helper(Node* T, Node* S, bool &ok){
        if(T==NULL && S==NULL){
            return;
        }
        if(T==NULL || S==NULL){
            ok = false;
            return;
        }
        if(T->data != S->data){
            ok = false;
            return;
        }
        helper(T->left, S->left, ok);
        helper(T->right, S->right, ok);
    }
    void helper1(Node* T, Node* S) 
    {
        if(T==NULL)
            return ;
        if(T->data == S->data){
            bool ok = true;
            helper(T, S, ok);
            if(ok) ans = true;
        }
        isSubTree(T->left, S);
        isSubTree(T->right, S);
    }
    public:
    bool isSubTree(Node* T, Node* S) 
    {
        helper1(T, S);
        return ans;
    }   
};

// { Driver Code Starts.

int main() {
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
    #endif

    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends