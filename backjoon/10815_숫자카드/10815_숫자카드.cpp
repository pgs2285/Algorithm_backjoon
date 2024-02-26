/*
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 
둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 
숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 
넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 
이 수는 공백으로 구분되어져 있다. 
이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다
*/
#include <iostream>
#include <queue>
#include <vector>
//#define MAX 500000

//int ownCards[MAX] = { 0, };
//int Find[MAX] = { 0, };

using namespace std;
vector<int> ownCards;
vector<int> Find;
void MergeResult(int left, int mid, int right)
{
	vector<int> tmpVec;
	int leftIdx = left;
	int rightIdx = mid+1;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (ownCards[leftIdx] <= ownCards[rightIdx])
		{
			tmpVec.push_back(ownCards[leftIdx]);
			leftIdx++;
		}
		else
		{
			tmpVec.push_back(ownCards[rightIdx]);
			rightIdx++;
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			tmpVec.push_back(ownCards[rightIdx]);
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			tmpVec.push_back(ownCards[leftIdx]);
			leftIdx++;
		}
	}
	for (int i = 0; i < tmpVec.size(); i++)
	{
		ownCards[left + i] = tmpVec[i];
	}
		
}
void MergeSort(int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);

}

bool FindNumber(int num)
{
	int left = 0;
	int right = ownCards.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (num > ownCards[mid])
		{
			left = mid + 1;
		}
		else {
			right = mid - 1;
			
		}
		if (num == ownCards[mid])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int tmp;
	ownCards.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		ownCards[i] = tmp;
	}
	MergeSort(0, N-1);
	int M;
	cin >> M;
	Find.resize(M);
	for (int j = 0; j < M; j++)
	{
		cin >> tmp;
		Find[j] = tmp;
	}
	for (int i = 0; i < M; i++)
	{
		bool b = FindNumber(Find[i]);
		cout << b << " ";
	}

}


