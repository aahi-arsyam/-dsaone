//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
int arrsum = 0, currSum = 0;
for(int i=0; i<N; i++)
{
    arrsum += A[i];
    currSum += i*A[i];
}

int max_sum = currSum;

for(int i=1; i<N; i++)
{
    //currSum -= arrsum - A[i];
    //currSum += (A[i] * (N-1));
    currSum  = currSum - arrsum + A[i-1] * N;
    max_sum = max(currSum, max_sum);
}

return max_sum;

}
