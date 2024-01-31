#include <iostream>
/*

어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에,
그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

조또마떄 구다사이...
N은 10^5개의 숫자면... 일단 다 비교하는건 말이 안된당
30의 배수

8085542 -> 88755420

30,60,90,120,150,180,210,240,270,300...3000,3030...
특별한 규칙이 없는것 처럼 보이지만 , 각 자리 수의 합이 3의배수이고 끝자리가 0으로 끝난다.
10^6자리 수라 어차피 어떤 정수형에도 담지 못하므로 string으로 저장후, 
각 문자열을 정렬하는것은 가능할것이다.

*/

using namespace std;

long long sumFunc(int cntList[])
{
	long long sum = 0;

	for (int i = 0; i < 10; i++)
	{
		sum += i * cntList[i];
	}
	return sum;
}

int main()
{
	string str;
	cin >> str;

	int cntList[10] = { 0, };

	long long sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int num = static_cast<int>(str[i] - 48);
		cntList[num]++;
		
	}
	sum = sumFunc(cntList);
	if (sum % 3  == 0&& cntList[0] != 0)
	{
		for (int i = 9; i >= 0 ;i--)
		{
			for (int j = cntList[i]; j > 0; j--)
			{
				cout << i;
			}
		}
	}
	else
	{
		cout << -1;
	}

}
