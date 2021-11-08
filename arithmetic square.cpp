#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long int li;

#define MOD 1000000007

void myInit()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test, it;
	it = 1;
	cin>>test;
	
	while(it <= test)
	{
		int count = 0;
		
		lli g[3][3];
		int i ,j;
		
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				if(!(i == 1 && j == 1))
				{
					cin>>g[i][j];
				}
			}
		}
		
		if((g[0][2] - g[0][1]) == (g[0][1] - g[0][0]))
		{
			count++;
		}
		
		if((g[2][2] - g[2][1]) == (g[2][1] - g[2][0]))
		{
			count++;
		}
		
		if((g[2][0] - g[1][0]) == (g[1][0] - g[0][0]))
		{
			count++;
		}
		
		if((g[2][2] - g[1][2]) == (g[1][2] - g[0][2]))
		{
			count++;
		}
		
		lli r = 0, c = 0, ld = 0, rd = 0;
		set<int> s;
		int sniff = 0;
		
//		for middle row
		if((g[1][2] + g[1][0]) % 2 == 0)
		{
			r = (g[1][2] + g[1][0]) / 2;
			s.insert(r);
			sniff++;
		}
		
//		for middle column
		if((g[2][1] + g[0][1]) % 2 == 0)
		{
			c = (g[2][1] + g[0][1]) / 2;
			s.insert(c);
			sniff++;
		}
		
//		for left diagonal
		if((g[2][2] + g[0][0]) % 2 == 0)
		{
			ld = (g[2][2] + g[0][0]) / 2;
			s.insert(ld);
			sniff++;
		}
		
//		for right diagonal
		if((g[2][0] + g[0][2]) % 2 == 0)
		{
			rd = (g[2][0] + g[0][2]) / 2;
			s.insert(rd);
			sniff++;
		}
		
//		cout<<r<<" "<<c<<" "<<ld<<" "<<rd<<endl;
		
		if(sniff == 4)
		{
			if(s.size() == 4)
			{
				count += 1;
			}
			else if(s.size() == 3)
			{
				count += 2;
			}
			else if(s.size() == 2)
			{
				count += 3;
			}
			else if(s.size() == 1)
			{
				count += 4;
			}
		}
		else if(sniff == 3)
		{
			if(s.size() == 3)
			{
				count += 1;
			}
			else if(s.size() == 2)
			{
				count += 2;
			}
			else if(s.size() == 1)
			{
				count += 3;
			}
		}
		else if(sniff == 2)
		{
			if(s.size() == 2)
			{
				count += 1;
			}
			else if(s.size() == 1)
			{
				count += 2;
			}
		}
		else if(sniff == 1)
		{
			if(s.size() == 1)
			{
				count += 1;
			}
		}
		else if(sniff == 0)
		{
			
		}
		
		cout<<"Case #"<<it<<": "<<count<<endl;
		it++;
	}

	return 0;
}

