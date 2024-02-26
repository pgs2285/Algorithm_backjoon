/*
1부터 N까지 정수 N개로 이루어진 순열을 나타내는 방법은 여러 가지가 있다. 
예를 들어, 8개의 수로 이루어진 순열 (3, 2, 7, 8, 1, 4, 5, 6)을 배열을 이용해 표현하면



순열을 배열을 이용해

 순열 그래프 (3, 2, 7, 8, 1, 4, 5, 6) 에는 총 3개의 사이클이 있다. 이러한 사이클을 "순열 사이클" 이라고 한다.

N개의 정수로 이루어진 순열이 주어졌을 때, 순열 사이클의 개수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& adjacants, vector<bool>& visited, int here)
{
    queue<int> q;
    q.push(here);
    visited[here] = true;
    while (!q.empty())
    {
        int there = q.front(); q.pop();
        visited[there] = true;
        for (int adj : adjacants[there])
        {
            if(visited[adj] == false)
                q.push(adj);
        }

    }
}

void DFS(vector<vector<int>>& adjacants, vector<bool>& visited, int here)
{
    visited[here] = true;
    for (int i = 0; i < adjacants[here].size(); i++) {
       int there =  adjacants[here][i];
       if (visited[there] == false)
       {
           DFS(adjacants, visited, there);
       }
    }
}

int main()
{
    int N;
    vector<int> ansList;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int M;
        int numCycle = 0;
        cin >> M;
        vector<vector<int>> adjacants(M);
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            adjacants[j].push_back(num - 1);
        }
        vector<bool> visited(M, false);
        for (int j = 0; j < M; j++)
        {
            if (visited[j] == false)
            {
                numCycle++;
                DFS(adjacants, visited, j);
            }
        }
        ansList.push_back(numCycle);
    }
    for (int i = 0; i < ansList.size(); i++)
    {
        cout << ansList[i] << "\n";
    }
}
