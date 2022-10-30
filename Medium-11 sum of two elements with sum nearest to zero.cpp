//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here
            /*sort(arr, arr+n);
            int low = 0, high = n-1;
            int ans1 = INT_MAX, ans2 = INT_MAX, curr_ans = INT_MAX, ans = INT_MAX;
            while(low < high)
            {
                int sum = arr[low]+arr[high];
                if(sum == 0) return sum;
                if(sum < 0) 
                {
                    ans1 = sum;
                    low++;
                }
                else 
                {
                    ans2 = sum;
                    high--;
                }
                if(abs(ans1) < abs(ans2))
                    curr_ans = ans1;
                else 
                    curr_ans = ans2;
                if(abs(curr_ans) < abs(ans))
                    ans = curr_ans;
                else if(abs(curr_ans) == abs(ans))
                    ans = max(curr_ans, ans);
            }
            return ans;*/
            //Sort the given array, try two pointer algorithm to find sum closest to zero.
            // Step1: Maintain two pointer left and right initialized with 0 and n-1.
            // Step2: find sum(arr[left] + arr[right]) and check if absolute sum is < previous absolute sum then update the previous sum
            // Step3: increment left pointer by 1 if sum < 0, otherwise if sum > 0 then decrement right pointer by 1.
            // Step4: Repeat above step until left < right.
            // time O(nlogn)
            sort(arr, arr+n);
            int low = 0, high = n-1;
            int res_sum = INT_MAX;
            while(low < high)
            {
                int sum = arr[low] + arr[high];
                if(abs(sum) < abs(res_sum))
                    res_sum = sum;
                else if(abs(sum) == abs(res_sum))
                    res_sum = max(sum, res_sum);
                
                if(sum > 0)
                    high--;
                else 
                    low++;
            }
            return res_sum;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends
