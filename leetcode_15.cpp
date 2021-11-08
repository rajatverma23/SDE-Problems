class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> result;
        
        for(int i = 0 ; i < (n-2); i++)
        {
            if(i == 0 || (i > 0 && nums[i-1] != nums[i]))
            {
                int low = i+1;
                int high = n-1;
                
                int sum = 0 - nums[i];
                
                while(low < high)
                {
                    if((nums[low] + nums[high]) == sum)
                    {
                        vector<int> ins;
                        ins.push_back(nums[i]);
                        ins.push_back(nums[low]);
                        ins.push_back(nums[high]);
                        
                        result.push_back(ins);
                        
                        while(low < high && nums[low] == nums[low+1])
                        {
                            low++;
                        }
                        
                        while(low < high && nums[high] == nums[high-1])
                        {
                            high--;
                        }
                        
                        low++;
                        high--;
                    }
                    else if((nums[low] + nums[high]) > sum)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        
        return result;
    }
};
