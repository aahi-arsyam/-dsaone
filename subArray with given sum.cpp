//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> res;
        int st = 0, sum = 0;
        for(int e=0; e<n; e++)
        {
            sum += arr[e];
            while(sum > s && st < e)
            {
                sum -= arr[st];
                st++;

            }

            if(sum == s)
            {
                res.push_back(st+1);
                res.push_back(e+1);
                break;
            }
            //else 
               // res.push_back(-1);
        }
        if(res.size() == 0 || s == 0)
            res.push_back(-1);
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
