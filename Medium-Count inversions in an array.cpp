//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int mergeAndCount(long long arr[], long long l, long long m, long long r)
    {
        long long n1 = m-l+1, n2 = r-m;
        long long a[n1], b[n2];
        for(int i=0; i<n1; i++)
            a[i] = arr[l+i];
            
        for(int j=0; j<n2; j++)
            b[j] = arr[m+j+1];
        
        long long int res = 0,i=0, j=0, k=l;
        while(i<n1 && j<n2)
        {
            if(a[i] <= b[j])
            {
                arr[k] = a[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = b[j];
                k++;
                j++;
                res = res + (n1-i);
            }
        }
        while(i<n1)
            arr[k++] = a[i++];
        while(j<n2)
            arr[k++] = b[j++];
        return res;
        
    }
    
    long long int merge(long long arr[], long long l, long long r)
    {
        long long int res = 0;
        if(r>l)
        {
            long long m = l + (r-l)/2;
            res += merge(arr, l, m);
            res += merge(arr, m+1, r);
            res += mergeAndCount(arr, l, m, r);
        }
        return res;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int res = 0;
        res = merge(arr, 0, N-1);
        
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
