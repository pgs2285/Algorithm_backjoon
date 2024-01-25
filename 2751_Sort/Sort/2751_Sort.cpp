#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;




vector<int> numList;


void Merge(int left, int right)
{
	int mid = (left + right) / 2;
	int leftIdx = left;
	int rightIdx = mid + 1;
	vector<int> result;
	while (leftIdx <= mid && rightIdx <= right)
	{
		if (numList[leftIdx] < numList[rightIdx])
		{
			result.push_back(numList[leftIdx]);
			leftIdx++;
		}
		else
		{
			result.push_back(numList[rightIdx]);
			rightIdx++;
		}
	}

	if (rightIdx >= left)
	{
		for (int i = leftIdx; i <= mid; i++)
		{
			result.push_back(numList[i]);
		}
	}
	else
	{
		for (int i = rightIdx; i <= right; i++)
		{
			result.push_back(numList[i]);
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		numList[left + i] = result[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);

	Merge(left, right);


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	const int i = N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		numList.push_back(num);
	}

	MergeSort(0, N-1);
	for (int i = 0; i < N; i++)
	{
		cout << numList[i] << "\n";
	}
	return 0;
}