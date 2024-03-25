#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		nums[i] = num;
	}

	std::sort(nums.begin(), nums.end());
	for (int i : nums)
	{
		cout << i << endl;
	}
}