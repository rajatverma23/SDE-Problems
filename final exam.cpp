#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin>>test;
	
	int ti = 1;
	while(ti <= test)
	{
		vector<lli> vec;
		lli i;
		
		lli n, m;
		cin>>n>>m;
		
		lli ar[n][2];
		lli max = 0;
		
		for(i = 0; i < n; i++)
		{
			cin>>ar[i][0]>>ar[i][1];
			if(max < ar[i][1])
			{
				max = ar[i][1];
			}
		}
		
		lli skill[m];
		vector<lli> v(max+1, 0);
		
		for(i = 0; i < n; i++)
		{
			for(lli j = ar[i][0]; j <= ar[i][1]; j++)
			{
				v[j] = 1;
			}
		}
		
		for(i = 0; i < m; i++)
		{
			cin>>skill[i];
			
			lli left = LLONG_MAX;
			lli right = LLONG_MAX;
			
			for(lli j = skill[i]; j <= max; j++)
			{
				if(v[j] == 1)
				{
					right = j - skill[i];
					break;
				}
			}
			
			for(lli j = skill[i] - 1; j >= 0; j--)
			{
				if(v[j] == 1)
				{
					left = skill[i] - j;
					break;
				}
			}
			
			
			if(left > right)
			{
				vec.push_back(skill[i] + right);
				v[skill[i] + right] = 0;
			}
			else
			{
				vec.push_back(skill[i] - left);
				v[skill[i] - left] = 0;
			}
		}
		
		cout<<"Case #"<<ti<<": ";
		
		vector<lli>::iterator iter = vec.begin();
		
		for(iter; iter != vec.end(); iter++)
		{
			cout<<*iter<<" ";
		}
		cout<<endl;
		
		ti++;
	}
	return 0;
}

