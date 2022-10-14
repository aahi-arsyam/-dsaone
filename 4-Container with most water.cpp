//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int len)
{
    // Your code goes here
    long long area = 0, maxArea = 0;
    int i=0, j=len-1;
    while(i<j)
    {
        area = min(arr[i], arr[j]) * (j-i);
        maxArea = max(area, maxArea);
        if(arr[i] < arr[j])
            i++;
        else 
            j--;
    }
    return maxArea;
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends
