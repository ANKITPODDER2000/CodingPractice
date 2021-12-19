// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/encrypt-the-string-21117/1#
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	string hexa(int n){
		string s = "";
		while(n){
			int val = n % 16;
			n /= 16;
			if(val <= 9) s += to_string(val);
			else s += ('a' + (val - 10));
		}
		// reverse(s.begin() , s.end());
		return s;
	}
  public:
    string encryptString(string S) {
        // code here
        string ans = "";
        for(int i = 0 ; i < S.length() ;){
            char ch = S[i++];
            int count = 1;
            while(S[i] == ch) {
                count++;
                i++;
            }
            ans = ans + ch + hexa(count);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
	#ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
    #endif

    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends