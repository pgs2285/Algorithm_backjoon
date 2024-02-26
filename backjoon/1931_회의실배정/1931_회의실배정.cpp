#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> time;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int from, to;
        cin >> from >> to;
        time.push_back(make_pair(from, to));
    }

    sort(time.begin(), time.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) 
            return a.first < b.first; 
        return a.second < b.second;
        });

    int cnt = 0;
    int endTime = 0;
    for (int i = 0; i < time.size(); i++)
    {
        if (time[i].first >= endTime)
        {
            endTime = time[i].second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
