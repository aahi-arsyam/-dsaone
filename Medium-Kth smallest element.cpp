//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    int partition(int arr[], int l, int h)
    {
        int p = arr[h];
        int i = l-1;
        for(int j=l; j<h; j++)
        {
            if(arr[j] < p)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[h]);
        return i+1;
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        while(l<=r)
        {
            int p = partition(arr, l, r);
            if(p == k-1)
                return arr[p];
            else if(p > k-1)
                r = p-1;
            else
                l = p+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
