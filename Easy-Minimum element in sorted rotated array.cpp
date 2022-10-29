//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int low = 0, high = n-1;
        if(arr[0] < arr[n-1]) return arr[0];
        while(low < high)
        {
            int mid = (low+high)/2;
            // just check if the first element if smaller than mid 
            // that means left half is sorted, in that case 
            // we will have to go to the right half
            if(arr[mid] >= arr[0]) 
                low = mid+1;
            // if the left half is not sorted
            // this implies right half is sorted
            // so we check in the left half
            else 
            {
                high = mid;
            }
        }
        return arr[low];
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
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
