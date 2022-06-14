#include <bits/stdc++.h>
using namespace std;

int subsequenceGivenSum(int arr[], int i, int sum, int n, int s)
{
	if (i >= n) {
		//condition satisfied
		if (s == sum) {
			return 1;
		}
		//condition not satisfied
		else
			return 0;
	}

	s += arr[i];
	//pick
	int left = subsequenceGivenSum(arr, i + 1, sum,  n, s);

	s -= arr[i];
	//not pick
	int right = subsequenceGivenSum(arr, i + 1, sum, n, s);
	return left + right;
}
int main()
{
	int arr[] = {1, 2, 1};
	int n = 3;
	int sum = 2;
	cout << subsequenceGivenSum(arr, 0, sum, n, 0);

	return 0;
}
