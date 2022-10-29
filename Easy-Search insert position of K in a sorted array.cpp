//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int low = 0, high = N-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            // if mid element is equal to k return mid
            if(Arr[mid] == k)
                return mid;
            // if k is between mid and mid+1 return mid+1
            // else if(k > Arr[mid] && k < Arr[mid+1])
               // return mid+1;
            else if(k < Arr[mid])
                high = mid-1;
            else 
                low = mid+1;
        }
        return high+1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
