//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    // Sort the given array then the problem reduces to finding the difference
    // between minium and maximum in contiguous subarray of size M.
    sort(a.begin(), a.end());
    long long min_diff = a[m-1] - a[0];
    
    long long s = 1;
    for(long long e = m; e<n; e++)
    {
        long long diff = a[e] - a[s];
        min_diff = min(diff, min_diff);
        s++;
    }
    return min_diff;
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
