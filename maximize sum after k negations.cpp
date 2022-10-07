//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        // Your code goes here
        
        sort(arr, arr+n);
        int i=0; 
        long long sum = 0;
        // One solution
        /*while(i<k)
        {
            if(arr[i] < 0)
            {
                arr[i] = -1*arr[i];
                i++;
            }
            if(arr[i] >= 0)
            {
                if((k-i) % 2 == 0)
                {
                    arr[i] = (-1*-1)*arr[i];
                    i += k;
                }
                else{
                    //sort(arr, arr+n);
                    //arr[0] = -1*arr[0];
                    if(arr[i] < arr[i-1])
                        arr[i] = -arr[i];
                    else
                        arr[i-1] = -arr[i-1];
                    i += k;
                }
            }
        }*/
        // Second solution
        while (k > 0) {
            // If we find a 0 or a number greater than 0 in our sorted array, we stop
            if (arr[i] >= 0)
                k = 0;
            else {
                arr[i] = (-1) * arr[i];
                k = k - 1;
            }
            i++;
        }
        for(int y=0; y<n; y++)
        {
            sum += arr[y];   
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends
