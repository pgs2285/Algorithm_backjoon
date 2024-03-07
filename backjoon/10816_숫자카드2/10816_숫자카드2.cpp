/*
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 
상근이는 숫자 카드 N개를 가지고 있다.
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.


input
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

output
3 0 0 1 2 0 0 2


*/

#include <iostream>
#include <vector>
using namespace std;

int nums[500000] = { 0, };
int find[500000] = { 0, };

void merge(int start, int mid, int end)
{
    int startIdx = start;
    int midIdx = mid + 1;
    vector<int> tmp;
    while (startIdx <= mid && midIdx <= end)
    {
        if (nums[startIdx] >= nums[midIdx])
        {
            tmp.push_back(nums[midIdx]);
            midIdx++;
        }
        else {
            tmp.push_back(nums[startIdx]);
            startIdx++;
        }
    }

    if (startIdx <= mid)
    {
        while (startIdx <= mid)
        {
            tmp.push_back(nums[startIdx]);
            startIdx++;
        }
    }
    else {
        while (midIdx <= end)
        {
            tmp.push_back(nums[midIdx]);
            midIdx++;
        }
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        nums[start + i] = tmp[i];
    }
}

void MergeSort(int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;

    MergeSort(start, mid);
    MergeSort(mid + 1, end);
    merge(start, mid, end);
}

int lower(int start, int end, int target)
{

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] >= target)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return end;
}

int higher(int start, int end, int target)
{

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] > target)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return end;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }
    MergeSort(0, N-1);
    int M; 
    cin >> M;
    vector<int> result(M);
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        int low = lower(0, N - 1, num);
        int high = higher(0, N - 1, num);
        if (high == N - 1 && nums[N - 1] == num)
            high++;
        result[i] = high - low;
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

}
