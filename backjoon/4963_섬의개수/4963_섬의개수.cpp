/*
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.



한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 
지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.

입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. 
w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.


*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coords {
    int x;
    int y;
};

int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };

void bfs(vector<vector<int>> arr, vector<vector<int>>& visited, coords coord)
{
    queue<coords> q;
    visited[coord.x][coord.y] = 1;
    q.push(coord);

    while (!q.empty())
    {
        coords here = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = here.x + dx[i];
            int y = here.y + dy[i];
            if (x < 0 || y < 0 || x > arr.size() - 1 || y > arr[0].size() - 1) continue;

            if (visited[x][y] == 0 && arr[x][y] == 1)
            {
                coords tmp = coords{ x,y };
                visited[x][y] = 1;
                q.push(tmp);
            }
        }
    }
    
}



int main()
{
    vector<int> ans;

    while (true)
    {

        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        vector<vector<int>> arr(M, vector<int>(N, 0));
        vector<vector<int>> visited(M, vector<int>(N, 0));
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                int num;
                cin >> num;
                arr[i][j] = num;
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < visited.size(); i++)
        {
            for (int j = 0; j < visited[i].size(); j++)
            {
                if (visited[i][j] == 0 && arr[i][j] == 1)
                {
                    bfs(arr, visited, coords{ i,j });
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);
    }

    for (int i : ans)
    {
        std::cout << i << "\n";
    }
}

