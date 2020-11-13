#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int maximum(vector<int> & value,vector<int>  &weight )
{
	int max = 0;
     double max_compare = 0;
	
	for (int i = 0;i < value.size();i++)
	{
		 
		if (weight[i] != 0 && (double)value[i] / weight[i] > max_compare)
		{
			max_compare = (double)value[i] / weight[i];
			max = i;
		}
	}
	return max;
}

double maxknapsack(int capacity, vector<int>& value, vector<int>& weight)
{
   	int current_weight = 0;
	double final_value = 0.00000000;

	for(int i=0;i<value.size();i++)
	{
		/*
		if (capacity == 0)
			return final_value;
		int max = maximum(value, weight);
		int a = min(capacity, weight[max]);
	   final_value += a * (double)value[max] / weight[max];
		weight[max] -= a;
		capacity -= a;
		*/int max = maximum(value, weight);
		if (current_weight + weight[max] < capacity)
		{
			current_weight += weight[max] ;
			final_value +=  value[max];
			weight[max] -= current_weight;
		}
		else  // current_weight + weight[max] >= capacity;
		{
			int remaining = capacity - current_weight;
			final_value += value[max] * (double)remaining / weight[max];
			weight[max] -= remaining;
			break;
		}
	}     
	return final_value;
}
int main()
{
	int n, capacity;
	cin >> n >> capacity;
	vector<int> value(n);
	vector<int> weight(n);
	for (int i = 0;i < n;i++)
	{       
		cin >> value[i] >> weight[i];
	}
	cout << setprecision(12)<< maxknapsack(capacity, value, weight);

}


