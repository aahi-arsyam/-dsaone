//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        // Your code here
        // int left[n] , right[n];
        // left[0] = arr[0], right[n-1] = arr[n-1];
        // for(int i=1; i<n; i++)
        // {
        //     left[i] = min(left[i-1], arr[i]);
        // }
        // for(int j=n-2; j>=0; j--)
        // {
        //     right[j] = max(right[j+1], arr[j]);
        // }
        // vector<int> res;
        // for(int i=0; i<n; i++)
        // {
        //     //if(left[i] != -1 && right[i] != -1)
        //     //{
        //     if(left[i] < arr[i] && right[i] > arr[i] )
        //     {
        //         res.push_back(left[i]);
        //         res.push_back(arr[i]);
        //         res.push_back(right[i]);
        //         break;
        //     }
        //     //}
        // }
        // return res;
        
        int smaller[n], greater[n];
        vector<int> result;
        smaller[0] = -1;
        int min = 0;
        for(int i=1; i<n; i++)
        {
            if(arr[i] <= arr[min])
            {
                min = i;
                smaller[i] = -1;
            }
            else
                smaller[i] = min;
        }
        greater[n-1] = -1;
        int max = n-1;
        for(int j=n-2; j>=0; j--)
        {
            if(arr[j] >= arr[max])
            {
                max = j;
                greater[j] = -1;
            }
            else
                greater[j] = max;
        }
        
        for(int i=0; i<n; i++)
        {
            if (smaller[i] != -1 && greater[i] != -1) {
                result.push_back(arr[smaller[i]]);
                result.push_back(arr[i]);
                result.push_back(arr[greater[i]]);
                return result;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
