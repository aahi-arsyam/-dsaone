//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        // time: O(root(n))
        /*long long int i = 1;
        while(true)
        {
            if(i*i == x)
                return i;
            if(i*i > x)
                return i-1;
            i++;
        }*/
        // time: O(logn)
        long long low = 1, high = x, ans = -1;
        while(low <= high)
        {
            long long mid = (low+high)/2;
            long long int mSq = mid*mid;
            if(mSq <= x)
            {
                ans = mid;
                low = mid+1;
            }
            else 
                high = mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
