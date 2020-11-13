#include <iostream>
#include <vector>
using namespace std;
int compute_min_refills(int d, int m, vector<int> & stops)
{ int currentrefule = 0;
    int count = 0;
    int n = stops.size();
    while (currentrefule < n)
    {
        int lastrefule = stops[currentrefule];
        while (currentrefule < n && stops[currentrefule + 1] - lastrefule <= m)
            currentrefule++;
        if (currentrefule == lastrefule)
        {
            return -1;
            break;
        }
        if (currentrefule <= n)
            count++;
    }
    return count;
}
int main() 
{int d = 0,m=0,n=0;
    cin >> d;
    cin >> m;
    cin >> n;
    int num;
    vector<int> stops(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        stops.push_back(num);
    }
    stops[n] = d;
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;}