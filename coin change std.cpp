#include <iostream>
#include<vector>
using namespace std;
int coins(int m, vector<int>& value)
{
	int n = value.size();
	int count = 0;
	int currentvalue = 0;
	for (int i = 0;i < n;i++)
	{
		while (currentvalue <= m - value[i])
		{
			currentvalue = currentvalue + value[i];
			count++;
           
		}
	} 
	if (currentvalue != m)
		return 0;
	return count;
}

int main()
{
	int m,n,put;
	cin >> m;
	cin >> n;
	vector<int> value;
	for (int i = 0;i < n;i++)
	{
		cin >> put;
		value.push_back(put);
	}
	cout << coins(m, value);

}