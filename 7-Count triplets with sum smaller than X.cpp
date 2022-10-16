//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long ans = 0;
	    sort(arr, arr+n);
	    for(int i=0; i<n-1; i++)
	    {
	        int low = i+1, high = n-1;
	        while(low < high)
	        {
	            if((arr[i] + arr[low] + arr[high]) < sum)
	            {
	                ans += (high-low);
	                low++;
	            }
	            else 
	            {
	                high--;
	            }
	        }
	    }
	    return ans;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
