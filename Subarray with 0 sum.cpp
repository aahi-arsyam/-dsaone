//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int presum = 0;
        unordered_set<int> h;
        for(int i=0; i<n; i++)
        {
            // compute prefix sum
            presum += arr[i];
            
            // check if current prefix sum is alredy present in the set then return true
            if(h.find(presum) != h.end())
            {
                return true;
            }
            
            // check if prefix sum becomes 0 then return true
            if(presum == 0)
                return true;
            
            // if neither of the above conditions are true then insert presum in unordered set
            h.insert(presum);
        }
        
        // if all the elements are traversed and there was no subarray for whose sum was zero then 
        // return false
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends
