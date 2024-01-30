#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(int start, vector<bool>& visited, const vector<vector<int>>& adjList)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int here = q.front();
        q.pop();

        for (int there : adjList[here])
        {
            if (!visited[there])
            {
                q.push(there);
                visited[there] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, A;
    cin >> V >> A;

    vector<vector<int>> adjList(V);
    vector<bool> visited(V, false);

    for (int i = 0; i < A; i++)
    {
        int from, to;
        cin >> from >> to;
        adjList[from - 1].push_back(to - 1);
        adjList[to - 1].push_back(from - 1);
    }

    int cnt = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            BFS(i, visited, adjList);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
