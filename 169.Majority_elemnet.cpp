class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int count = 0, candidate = 0;
        
        for(int i = 0 ; i < n; i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
            }
            
            if(candidate  == nums[i])
            {
                count = count + 1;
            }
            else
            {
                count = count - 1;
            }
        }
        
        return candidate;
    }
};
