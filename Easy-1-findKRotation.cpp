//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0, high = n-1;
	    if(arr[0] <= arr[n-1])  // check if array is rotated or not
	        return 0;
	    while(low < high)
	    {
	        int mid = (low+high) / 2;
	        if(arr[mid] >= arr[0]) // since the array if rotated and sorted, that means 
	            low = mid+1;       // first element would always be greater than the last
	        else                   // therefore checking mid against arr[0] gives the idea if the pivot is in right  half or left
	            high = mid;
	    }
	    return low; // low gives the number of rotations (or) index of pivot element
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
