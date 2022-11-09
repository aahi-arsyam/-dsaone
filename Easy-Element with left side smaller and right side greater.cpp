//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    int leftMax[n];
    int rightMin[n];
    leftMax[0] = arr[0];
    rightMin[n-1] = arr[n-1];
    
    for(int i=1; i<n; i++)
        leftMax[i] = max(arr[i], leftMax[i-1]);
    
    for(int i=n-2; i>=0; i--)
        rightMin[i] = min(arr[i], rightMin[i+1]);
        
    for(int i=1; i<n-1; i++)
    {
        if(arr[i] >= leftMax[i-1] && arr[i] <= rightMin[i+1])
            return arr[i];
    }
    
    return -1;
}
