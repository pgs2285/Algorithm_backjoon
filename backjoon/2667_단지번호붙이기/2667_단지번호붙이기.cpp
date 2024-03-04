/*
<그림 1>과 같이 정사각형 모양의 지도가 있다. 
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int arr[25][25] = { 0, };
int visited[25][25] = { 0, };

struct coords {
	int x;
	int y;
};

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(coords c, int N)
{
	queue<coords> coord;
	coord.push(c);
	visited[c.y][c.x] = 1;
	int cnt = 1;
	while (!coord.empty())
	{
		coords here = coord.front();
		coord.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = here.x + dx[i];
			int ny = here.y + dy[i];

			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1)
				continue;

			if (arr[ny][nx] && !visited[ny][nx]) {
				coord.push({ nx, ny });
				visited[ny][nx] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int N;
	cin >> N;
	string num;
	vector<int> ans;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = num[j] - '0';
		}

	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0 && arr[i][j] != 0)
			{
				coords c;
				c.x = j;
				c.y = i;
				int cnt = bfs(c, N);
				ans.push_back(cnt);
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int a : ans)
	{
		cout << a << "\n";
	}

}
