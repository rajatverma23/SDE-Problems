class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return;
        }
        
        int i = nums.size() - 2;
        int j;
        
        while(i >= 0 && nums[i] >= nums[i+1])
        {
            i--;
        }
        
        if(i >= 0)
        {
            j = nums.size() - 1;
            while(nums[j] <= nums[i])
            {
                j--;
            }
            
            swap(nums, i, j);
        }
        
        i++;
        j = nums.size() - 1;
        
        while(i < j)
        {
            swap(nums, i++, j--);
        }
    }
    
    void swap(vector<int>& num, int i, int j)
    {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
};
