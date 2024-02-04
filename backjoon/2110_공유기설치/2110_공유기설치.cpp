/*
�������� �� N���� ������ ���� �ִ�. ������ ���� ��ǥ�� x1, ..., xN�̰�, �� �������� ���� ��ǥ�� ������ ���� ����.

�����̴� ���� ��𼭳� �������̸� ���� ���ؼ� ���� ������ C���� ��ġ�Ϸ��� �Ѵ�. �ִ��� ���� ������ �������̸� ����Ϸ��� �ϱ� ������,
�� ������ �����⸦ �ϳ��� ��ġ�� �� �ְ�, ���� ������ �� ������ ������ �Ÿ��� ������ ũ�� �Ͽ� ��ġ�Ϸ��� �Ѵ�.

C���� �����⸦ N���� ���� ������ ��ġ�ؼ�, ���� ������ �� ������ ������ �Ÿ��� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.


1 2 4 8 9
1,4,9�� ���� �ָ� ��ġ, ���� ������ �� ������ ���� �Ÿ��� = 4-1=3

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
	//�ϴ� ������ ������� �ְ� ����
	std::sort(houseList.begin(), houseList.end());
	//���� �ƴ� �Ÿ��� �������� �ϴ� �̺�Ž��
	int start = 1; // ���� ���� ����
	int end = houseList[houseN - 1] - houseList[0]; // ��������
	int result = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int prev = houseList[0];
		int cnt = 1; // ù���� �޾Ƶΰ� ����
		for (int i = 1; i < houseN; i++)
		{
			if (houseList[i] - prev >= mid) // �츮�� ���� �߰�������, ������ �� ���
			{
				prev = houseList[i]; //���� ��ġ�� ����� ��ġ
				cnt++;//�����
			}
		}

		if (cnt>= routerN)
		{
			start = mid + 1;
			//����Ͱ� �ʹ� ������, mid �� �÷��� �ٿ��� �ϹǷ�, mid+1
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