//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        
        int count = 0;
        // count number of elements <= k
        for(int i=0; i<n; i++)
        {
            if(arr[i] <= k)
                count++;
        }
        
        int bad_cnt = 0;
        // count number of elements in window size of count that how many numbers are > k
        for(int i=0; i<count; i++)
            if(arr[i] > k)
                bad_cnt++;
        
        int min_cnt = bad_cnt;
        min_cnt = min(bad_cnt, min_cnt);
        int s = 0, e = count;
        for(e; e<n; e++)
        {
            // if the first element of window is > k , decrement bad_cnt
            if(arr[s] > k)
                bad_cnt--;
            s++;
            // if the new element of window is > k, increment bad_cnt
            if(arr[e] > k)
                bad_cnt++;
            min_cnt = min(bad_cnt, min_cnt);
        }
        
        return min_cnt;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends
