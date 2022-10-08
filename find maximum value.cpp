//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*The function returns an integer
which denotes the max value 
of abs(i - j) * min(arr[i], arr[j]) 
in the array.
*/

/*You are required to complete this method*/
class Solution
{
    public:
    int max_val(int arr[], int n)
    {
        //Your code here
        int maxVal = 0, i=0, j=n-1;
        while(i<j)
        {
            int index = abs(i-j);
            int mini = min(arr[i], arr[j]);
            maxVal = max((index*mini), maxVal);
            if(arr[i] < arr[j])
                i++;
            else 
                j--;
        }
        return maxVal;
    }
};

//{ Driver Code Starts. 

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		Solution ob;
		cout<<ob.max_val(a,n)<<endl;
		
	}
	return 0;
}
// } Driver Code Ends
