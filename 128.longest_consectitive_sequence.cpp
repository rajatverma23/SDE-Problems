class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> cap;
        int n = nums.size();
        
        for(int i = 0; i < n ; i++)
        {
            cap.insert(nums[i]);
        }
        
        int lon = 0;
        
        for(int i = 0; i < n ; i++)
        {
            if(!cap.count(nums[i] - 1))
            {
                int temp = nums[i];
                int tem = 1;
                
                while(cap.count(temp+1))
                {
                    temp++;
                    tem++;
                }
                
                lon = max(lon, tem);
            }
        }
        
        return lon;
    }
};
