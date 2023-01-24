//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        // Do the transpose of the matrix
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // swap individual columns that is first row by last row, 2nd row by 2nd last row and so on
        for(int i=0; i<n; i++)
        {
            int low=0, high=n-1;
            while(low<high)
            {
                swap(matrix[low][i], matrix[high][i]);
                low++; high--;
            }
        }
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
