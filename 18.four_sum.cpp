class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        
        if(nums.empty())
        {
            return result;
        }
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int tar = target - (nums[i] + nums[j]);
                
                int front = j+1;
                int back = n-1;
                
                while(front < back)
                {
                    int sum = nums[front] + nums[back];
                    
                    if(sum > tar)
                    {
                        back--;
                    }
                    else if(sum < tar)
                    {
                        front++;
                    }
                    else
                    {
                        vector<int> q(4, 0);
                        q[0] = nums[i];
                        q[1] = nums[j];
                        q[2] = nums[front];
                        q[3] = nums[back];
                        
                        result.push_back(q);
                        
                        while(front < back && nums[front] == q[2])
                        {
                            front++;
                        }
                        
                        while(front < back && nums[back] == q[3])
                        {
                            back--;
                        }
                    }
                }
                
                while(j+1 < n && nums[j+1] == nums[j])
                {
                    j++;
                }
            }
            
            while(i+1 < n && nums[i+1] == nums[i])
            {
                i++;
            }
        }
        
        return result;
     }
};
