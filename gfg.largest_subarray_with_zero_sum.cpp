class Solution{
	public:
		int largest(vector<int> A, int n)
		{
			int max_len = 0;
			int sum = 0;
			unordered_map<int, int> mp;
			
			for(int i = 0; i < n ; i++)
			{
				sum+=A[i];
				
				if(sum == 0)
				{
					max_len = i + 1;
				}
				else
				{
					if(mp.find(sum)!= mp.end())
					{
						max_len = max(max_len, i - mp[sum]);
					}
					else
					{
						mp[sum] = i;
					}
				}
			}
			
			return max_len;
		}
		
};
