//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int n) 
    { 
        // Your code here
        int rightMax[n], leftMin[n];
        rightMax[n-1] = A[n-1];
        leftMin[0] = A[0];
        for(int i=1; i<n; i++)
        {
            leftMin[i] = min(leftMin[i-1], A[i]);
        }
        for(int i=n-2; i>=0; i--)
        {
            rightMax[i] = max(rightMax[i+1], A[i]);
        }
        int maxDiff=0;
        int i=0, j=0;
        while(i<n && j<n)
        {
            int diff = 0;
            if(rightMax[j] >= leftMin[i])
            {
                diff = j-i;
                j++;
            }
            else if(leftMin[i] > rightMax[j])
            {
                i++;
            }
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
