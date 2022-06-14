#include <bits/stdc++.h>
using namespace std;

void subsequenceGivenSum(int arr[], int i, int sum, vector<int>&ds, int n, int s)
{
	if (i >= n) {
		if (s == sum) {
			for (auto x : ds) {
				cout << x << " ";
			}
			cout << endl;
		}
		return;
	}
	ds.push_back(arr[i]);
	s += arr[i];
	subsequenceGivenSum(arr, i + 1, sum, ds, n, s);
	ds.pop_back();
	s -= arr[i];
	subsequenceGivenSum(arr, i + 1, sum, ds, n, s);
}
int main()
{
	int arr[] = {1, 2, 1};
	int n = 3;
	int sum = 2;
	vector<int>ds;
	subsequenceGivenSum(arr, 0, sum, ds, n, 0);

	return 0;
}
