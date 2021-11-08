#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long int li;

void get_me_help(int n, int a[], int *x, int *y)
{
	int xxor;
	
	int set_bit;
	
	*x = 0;
	*y = 0;
	
	xxor = a[0];
	
	for(int i = 1; i < n; i++)
	{
		xxor = xxor ^ a[i];
	}
	
	for(int i = 1; i <=n; i++)
	{
		xxor ^= i;
	}
	
	set_bit = xxor & ~(xxor-1);
	
	for(int i = 0; i < n; i++)
	{
		if(set_bit & a[i])
		{
			*x ^= a[i];
		}
		else
		{
			*y ^= a[i];
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(i & set_bit)
		{
			*x ^= i;
		}
		else
		{
			*y ^= i;
		}
	}
}

int main(){
	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	
	int *x = (int *)malloc(sizeof(int));
	int *y = (int *)malloc(sizeof(int));
	
	get_me_help(n, a, x, y);
	
	cout<<"Missing number = "<<*x<<endl<<"Repeating number = "<<*y<<endl;
	return 0;
}

