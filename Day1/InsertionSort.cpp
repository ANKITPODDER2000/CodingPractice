// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

//https://practice.geeksforgeeks.org/problems/insertion-sort/1/?problemStatus=unsolved&problemType=functional&difficulty[]=0&difficulty[]=1&page=1&sortBy=submissions&query=problemStatusunsolvedproblemTypefunctionaldifficulty[]0difficulty[]1page1sortBysubmissions

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i = 1 ; i < n ; i++){
            int val = arr[i];
            int j = i-1;
            while(j >= 0 && arr[j]>val){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = val;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends