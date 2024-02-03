/*
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.


자리수는 2인 것
12,23,34,45,56,67,78,89,98,87,76,65,54,43,32,21,10 -> 이거의 조합으로 제작가능

->좌우대칭,증가,감소 총 3가지 -> 10^100승까지이므로 DP 사용

자리수는 3인 것
123,234,345,456,567 ...+121,232,등

자리수는 4인 것
1234,2345,3456,4567,5678, 등

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
*/

#include <iostream>
using namespace std;

#define MOD 1000000000

long long cnt[101][10] = { 0, }; // 101자리수 중 

long long stairNums(long long N)
{
	long long nums = 0;

	for (int i = 1; i < 10; i++)
	{
		cnt[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				cnt[i][0] = cnt[i - 1][1] % MOD;
			else if (j == 9)
				cnt[i][9] = cnt[i - 1][8] % MOD;
			else
				cnt[i][j] = (cnt[i - 1][j - 1] + cnt[i - 1][j + 1]) % MOD;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		nums += cnt[N][i] % MOD;
	}
	return nums % MOD;
}

int main()
{
	long long N;
	cin >> N;
	cout << stairNums(N);
}
