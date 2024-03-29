﻿

/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

		3일때 -> 3으로 나눈다 -> 끝
		4일때 -> 1을 뺀다-> 3으로 나눈다 -> 끝 ( 3일때 사용)
		5일때 -> 1을 뺀다-> 2로 나눈다-> 1을 뺀다 끝 (4일때 사용)
		6일때 -> 3으로 나눈다 -> 2로나눈다 -> 끝 (2일때 (1) 사용)
		7일때 -> 1을 뺀다 -> 3으로 나눈다 -> 2로 나눈다 -> 끝 (6일때 사용)

		....
		20일때 -> 2나누기 -> 2나누기 -> 1빼기 -> 2나누기 -> 1빼기
		solution은 아래부터 최소값을 천천히 구해서 올라가는것. ( 상위는 하위에 구한 값을 그냥 가져오면 됨)
cache에는 1까지 가는 연산이 몇번걸리는지 저장
*/

#include <iostream>
using namespace std;

int cache[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cache[2] = 1;

	int N;
	cin >> N;
	for (int i = 3; i <= N; i++)
	{
		cache[i] = cache[i - 1] + 1; // 일단 1뺀 값부터 시작한다 가정한다

		if (i % 2 == 0)
		{// 2로 나누어 떨어진다면
			cache[i] = min(cache[i / 2] + 1, cache[i]); // 이 두가지 케이스중 이전에 더 작은값으로 접근
		}
		if (i % 3 == 0)
		{ // 3으로 나누어 떨어진다면
			cache[i] = min(cache[i / 3] + 1, cache[i]);
		}
	}
	cout << cache[N];
	
}


