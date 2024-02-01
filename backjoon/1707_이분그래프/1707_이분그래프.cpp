/*
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때,
그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K가 주어진다.
각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V와 간선의 개수 E가 빈 칸을 사이에 두고 순서대로 주어진다.
각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데,
각 줄에 인접한 두 정점의 번호 u, v (u ≠ v)가 빈 칸을 사이에 두고 주어진다.


예시입력
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2

출력
YES
NO
*/
#include <iostream>
#include <vector>
#include <queue>

#define RED 1
#define BLACK 2

using namespace std;

bool BFS_BipartiteCheck(vector<vector<int>>& adjacants, int vertexCnt, int startPoint, vector<int>& visited)
{
    queue<int> q;
    q.push(startPoint);
    visited[startPoint] = RED;

    while (!q.empty())
    {
        int here = q.front();
        q.pop();

        for (int adj : adjacants[here])
        {
            if (visited[adj] == 0) {
                visited[adj] = (visited[here] == RED) ? BLACK : RED;
                q.push(adj);
            }
            else {
                if (visited[adj] == visited[here])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<string> ansList;
    for (int i = 0; i < N; i++)
    {
        int vertexCnt, adjacantCnt;
        cin >> vertexCnt >> adjacantCnt;
        vector<vector<int>> adjacants(vertexCnt);
        vector<int> visited(vertexCnt, 0);

        for (int j = 0; j < adjacantCnt; j++)
        {
            int from, to;
            cin >> from >> to;
            adjacants[from - 1].push_back(to - 1);
            adjacants[to - 1].push_back(from - 1); // 양방향 간선 추가
        }

        bool isBipartite = true;
        for (int k = 0; k < vertexCnt; k++)
        {
            if (visited[k] == 0 && !BFS_BipartiteCheck(adjacants, vertexCnt, k, visited))
            {
                isBipartite = false;
                break;
            }
        }

        if (isBipartite)
            ansList.push_back("YES");
        else
            ansList.push_back("NO");

    }

    for (string s : ansList)
    {
        cout << s << "\n";
    }
    return 0;
}
