//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        
        // time: O(n^2)
        // int count_0 = 0, ans = 0;
        // for(int i=0; i<n; i++)
        // {
        //     count_0 = 0;
        //     int j = i;
        //     for(j; j<n; j++)
        //     {
        //         if(arr[j] == 0)
        //             count_0++;
                    
        //         if(count_0 > m)
        //             break;
                
        //     }
        //     ans = max(ans, j-i);
        // }
        // return ans;
        
        int ans = 0, zero_count = 0, l = 0;
        int e=0;
        while(e<n)
        {
            // If zero count of current window is less than m,
            // widen the window toward right
            if(zero_count <= m)
            {
                if(arr[e] == 0)
                    zero_count++;
                e++;
            }
            
            // If zero count of current window is more than m,
            // reduce the window from left
            if(zero_count > m)
            {
                if(arr[l] == 0)
                    zero_count--;
                l++;
            }
            
            // Update widest window if this window size is more
            if(e-l > ans)
                ans = e-l;
        }
        
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
