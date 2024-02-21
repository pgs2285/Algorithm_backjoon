/*
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 
우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.
*/
#include <iostream>
#include <vector>
using namespace std;
int paper[2200][2200];
int cntList[3] = { 0, };

bool isSameNum(int start_x,int start_y, int size)
{
	int compare = paper[start_x][start_y];
	for (int i = start_x; i < start_x+size; i++)
	{
		for (int j = start_y; j < start_y+size; j++)
		{
			if (compare != paper[i][j])
				return false;
		}
	}
	cntList[compare + 1]++;
	return true;
}

void sliced(int start_x, int start_y, int range)
{

	if (!isSameNum(start_x, start_y, range))
	{
		int num = range / 3;
		for (int i = start_x; i < start_x+range; i+=(num))
		{
			for (int j = start_y; j < start_y+range; j+=(num))
			{
				sliced(i, j, num);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	

	int num = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			paper[i][j] = num;
		}
	}
	sliced(0, 0, N);

	for (int i = 0; i < 3; i++)
	{
		cout << cntList[i] << "\n";
	}
}

