class Solution{
	public:
		int subarray_xor(vector<int> nums, int m)
		{
			int n = nums.size();
			int count = 0;
			int xr = 0;
			
			unordered_map<int, int> freq;
			
			for(int i = 0; i < n; i++)
			{
				xr = xr^nums[i];
				
				if(xr == m)
				{
					count++;
				}
				
				if(freq.find(xr^m)!= freq.end())
				{
					count+=freq[xr^m];
				}
				else
				{
					freq[xr^m]++;
				}
			}
			
			return count;
		}		
};
