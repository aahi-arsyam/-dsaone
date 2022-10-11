//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> res;
        /*for(int i=0; i<n; i++)
        {
            int index = abs(arr[i]);
            if(arr[index] < 0)
            {
                res.push_back(index);
            }
            arr[index] = -1*arr[index];
        }
        sort(res.begin(), res.end());
        if(res.size() == 0)
            res.push_back(-1);*/
        
        for(int i=0; i<n; i++)
        {
            int index = arr[i] % n;
            arr[index] += n;
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i] / n >= 2)
            {
                res.push_back(i);
            }
        }
        if(res.size() == 0)
            res.push_back(-1);
            
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
