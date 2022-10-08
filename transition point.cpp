//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
        int low = 0, high = n-1;

    // Perform Binary search
    while (low <= high)
    {
        // Find mid
        int mid = (low+high)/2;

        // update lower_bound if mid contains 0
        if (arr[mid] == 0)
            low = mid+1;

        // If mid contains 1
        else if (arr[mid] == 1)
        {
            // Check if it is the left most 1
            // Return mid, if yes
            if (mid == 0
                    || (mid > 0 && 
                       arr[mid - 1] == 0))
                return mid;

            // Else update upper_bound
            high = mid-1;
        }
    }
    return -1;
}
