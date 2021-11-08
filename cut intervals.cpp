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
		lli count = 0;
		lli n, c;
		cin>>n>>c;
		
		count = n;
		
		lli ar[n][2];
		
		lli i = 0;
		lli max = 0;
		
		for(i; i < n; i++)
		{
			cin>>ar[i][0]>>ar[i][1];
			if(max < ar[i][1])
			{
				max = ar[i][1];
			}
		}
		
		vector<lli> vec(max+1, 0);
		
		for(i = 0; i < n; i++)
		{
			for(lli j = ar[i][0] + 1; j < ar[i][1]; j++)
			{
				vec[j]++;
			}
		}
		
		multimap<lli, lli, greater<lli>> mm;
		
		for(i = 0;i <= max; i++)
		{
			mm.insert(make_pair(vec[i], i));
		}
		
		multimap<lli, lli> :: iterator it;
		
		for(i = 0, it = mm.begin(); ((i < c) && (it != mm.end())); i++, it++)
		{
			count += (it->first);
		}	
		
		cout<<"Case #"<<ti<<": "<<count<<endl;
		ti++;
	}
	return 0;
}

