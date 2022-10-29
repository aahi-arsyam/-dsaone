//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        // add code here.
        int low = 0, high = n-2;
        int res = n-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(a[mid] == b[mid])
                // this will always hold because both the elements are same
                // that means the extra element if after the mid
                low = mid+1;
            else
            {
                // If middle element is different  
                // of the arrays, it means that  
                // the index we are searching for  
                // is either mid, or before mid.  
                // Hence we update right to mid-1.
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}
// } Driver Code Ends
