/*
다음과 같이 정의된 수열이 있다.

D[1] = A
D[n] = D[n-1]의 각 자리의 숫자를 P번 곱한 수들의 합
예를 들어 A=57, P=2일 때, 수열 D는 
[57, 74(=5^2+7^2=25+49), 65, 61, 37, 58, 89, 145, 42, 20, 4, 16, 37, …]이 된다. 
그 뒤에는 앞서 나온 수들(57부터가 아니라 58부터)이 반복된다.

이와 같은 수열을 계속 구하다 보면 언젠가 이와 같은 반복수열이 된다. 
이때, 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 구하는 프로그램을 작성하시오. 
위의 예에서는 [57, 74, 65, 61]의 네 개의 수가 남게 된다.

첫째 줄에 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 출력한다.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int powEachDigit(int N, int P)
{
	int sum = 0;
	while (N > 0)
	{
		int digit = N % 10;
		N /= 10;
		sum += std::pow(digit, P);
	}
	return sum;
}

int main()
{
	vector<int> adjacants(300001,0);
	vector<int> list;
	int N, P;
	int cnt=0;
	cin >> N >> P;
	
	int powDigit = powEachDigit(N,P);
	list.push_back(powDigit);
	while (adjacants[powDigit] == 0)
	{
		adjacants[powDigit] = 1;		
		powDigit = powEachDigit(powDigit, P);
		list.push_back(powDigit);
	}
	for (int i = 0; i < list.size(); i++)
	{
		cnt++;
		if (list[i] == powDigit)
			break;
	}
	if (N == powDigit)
		cnt = 0;
	cout << cnt;
}