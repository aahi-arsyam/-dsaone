class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size() - 2; i++)
        {
            if(i==0 || (i>0 && nums[i] != nums[i-1])) // if the first element has no duplicates then do the fol0lowing. This handles the duplicates of first number
            {
            int low = i+1, high = nums.size()-1; // set the two pointers
            while(low<high)
            {
                if(nums[i] + nums[low] + nums[high] == 0)
                {
                    vector<int> temp = {nums[i], nums[low], nums[high]};
                    ans.push_back(temp);
                    while(nums[low] == nums[low+1] && low+1 < high) low++; // traversing through the duplicates of 2nd number
                    while(nums[high] == nums[high-1] && low+1 < high) high--;// raversing through the duplicates of 3rd number
                    low++;
                    high--;
                }
                else if(nums[i] + nums[low] + nums[high]  > 0)
                    high--;
                else 
                    low++;
            }
            }
        }
        return ans;
            
    }
};
