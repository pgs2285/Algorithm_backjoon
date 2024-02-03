/*
도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.

도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에,
한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.

C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.


1 2 4 8 9
1,4,9가 가장 멀리 설치, 가장 인접한 두 공유기 사이 거리는 = 4-1=3

1 3 6 8 12 19
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int houseN, routerN = 0;
	cin >> houseN >>routerN;
	vector<int> houseList;
	for (int i = 0; i < houseN; i++)
	{
		int house;
		cin >> house;
		houseList.push_back(house);
	}
	//일단 집들이 순서대로 있게 정렬
	std::sort(houseList.begin(), houseList.end());
	//점이 아닌 거리를 기준으로 하는 이분탐색
	int start = 1; // 같은 집이 없니
	int end = houseList[houseN - 1] - houseList[0]; // 마지막점
	int result = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int prev = houseList[0];
		int cnt = 1; // 첫집은 달아두고 시작
		for (int i = 1; i < houseN; i++)
		{
			if (houseList[i] - prev >= mid) // 우리가 구한 중간값보다, 간격이 더 길면
			{
				prev = houseList[i]; //현재 위치에 라우터 설치
				cnt++;//라우터
			}
		}

		if (cnt>= routerN)
		{
			start = mid + 1;
			//라우터가 너무 많으면, mid 를 늘려서 줄여야 하므로, mid+1
			result = max(result, mid);
		}

		else
		{
			end = mid - 1;
		}
	}
	cout << result;
	return 0;
}