//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
	// O(n) time and O(n) space solution
        vector<long long int> p;
        
        long long int prod = 1;
        long long left[n], right[n];
        
        if(n == 1)
        {
            p.push_back(1);
            return p;
        }
        
        left[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            left[i] = left[i-1]*nums[i];
        }
        
        right[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            right[i] = right[i+1]*nums[i];
        }
        
        p.push_back(right[1]);
        for(int i=1; i<n-1; i++)
        {
            long long temp = left[i-1] * right[i+1];
            p.push_back(temp);
        }
        p.push_back(left[n-2]);
        
        return p;
	    
	/* O(n) time and O(1) space solution
	vector<long long int> p;
        
        long long int prod = 1;
        long long count = 0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
                count++;
            else 
                prod *= nums[i];
        }
        
        for(int i=0; i<n; i++)
        {
            if(count > 1)
                p.push_back(0);
                
            if(count == 0)
                p.push_back(prod/nums[i]);
            
            else if(count == 1 && nums[i] == 0)
                p.push_back(prod);
            
            else 
                p.push_back(0);
        }
        
        return p;*/
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
