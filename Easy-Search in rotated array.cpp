//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0, high = n;
	    if(arr[0] <= arr[n])
	        return 0;
	    while(low < high)
	    {
	        int mid = (low+high) / 2;
	        if(arr[mid] >= arr[0])
	            low = mid+1;
	        else 
	            high = mid;
	    }
	    return low;
	}
	
	int bsearch(int a[],int l,int h,int key){
        int low = l;
        int high = h;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(a[mid]==key)
                return mid;
            else if(a[mid]<key)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
	
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
	    
	  /*  while(l<=h)
        {
            int mid = (l+h)/2;
            if(A[mid] == key) return mid;
            if(A[l] <= A[mid])  // left half sorted
            {
                if(key >= A[l] && A[mid] > key)
                    h = mid-1;
                else 
                    l = mid+1;
            }
            else  // right half sorted
            {
                if(key > A[mid] && key <= A[h])
                    l = mid+1;
                else 
                    h = mid-1;
            }
        }
        return -1;
	*/
	    
        int pivot = findKRotation(A, h); // finding the pivot point
        if(key >= A[l] && key <= A[pivot-1])  // if the key lies between low and pivot-1 
            return bsearch(A, l, pivot-1, key);
        else 
            return bsearch(A, pivot, h, key); // if the key lies between pivot and high
        
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends
