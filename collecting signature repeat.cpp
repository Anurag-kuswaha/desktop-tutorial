#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Segment {
    
public:
    int start, end;
    
};
bool operator <(const Segment& a, const Segment& b)
{
    return (a.end < b.end);
}
vector<int> optimal_points(vector<Segment>& segments) {
    vector<int> points;
    //write your code here
    sort(segments.begin(), segments.end());  // sorted according to end elements in increasing order.
    int firstpoint = segments[0].end;
    points.push_back(firstpoint);

    for (size_t i = 1; i < segments.size(); ++i) {
        if (firstpoint < segments[i].start ||  firstpoint > segments[i].end ){
            firstpoint = segments[i].end;
            points.push_back(firstpoint);
        }
        
    }return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}