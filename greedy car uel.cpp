#include<iostream>
using namespace std;

long long min_refill(long long a[], long long n, long long m, long long d)
{
	long long currentrefill = 0;
	long long num_refill = 0;
	while (currentrefill <= n)
	{
		int lastrefill = currentrefill;
		while (currentrefill <= n && a[currentrefill + 1] - a[lastrefill] <= m)
			currentrefill = currentrefill + 1;
		if (currentrefill == lastrefill)
		{
			return -1;
			break;
		}
		if (currentrefill <= n)
			num_refill++;
	}  
	return num_refill;
}
int main()
{
	long long d,n,m,put;
	cin >>d>> m >> n;
	long long* a = new long long[n];
	for (int i = 1;i <= n;i++)
	{
		cin >> put;
		a[i] = put;
	}
	a[n + 1] = d;
	a[0] = 0;
	long long total= min_refill(a, n, m,d);
	cout << total;
}