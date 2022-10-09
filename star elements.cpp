//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<int> getStarAndSuperStar(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> ans = getStarAndSuperStar(arr, n);
        for (int i=1;i<ans.size();i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        cout << ans[0] << "\n";
    }
    return 0;
}

// } Driver Code Ends


vector<int> getStarAndSuperStar(int arr[], int n) {
    // code here  
    int star = arr[n-1], sum = arr[n-1];
    vector<int> res;
    res.push_back(star);
    for(int i=n-2; i>=0; i--)
    {
        sum += arr[i];
        if(arr[i] > star)
        {
            star = arr[i];
            res.push_back(star);
        }
    }
    int superStar = res[res.size() - 1];
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == superStar)
            count++;
    }
    
    if(count > 1)
        superStar = -1;
    res.push_back(superStar);
    reverse(res.begin(), res.end());
    return res;
}
