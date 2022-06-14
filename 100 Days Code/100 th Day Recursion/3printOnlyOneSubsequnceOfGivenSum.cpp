#include <bits/stdc++.h>
using namespace std;

bool subsequenceGivenSum(int arr[], int i, int sum, vector<int>&ds, int n, int s)
{
	if (i >= n) {
		//condition satisfied
		if (s == sum) {
			for (auto x : ds) {
				cout << x << " ";
			}
			cout << endl;
			return true;
		}
		//condition not satisfied
		else
			return false;
	}
	ds.push_back(arr[i]);
	s += arr[i];
	//pick
	if (subsequenceGivenSum(arr, i + 1, sum, ds, n, s) == true)return true;
	ds.pop_back();
	s -= arr[i];
	//not pick
	if (subsequenceGivenSum(arr, i + 1, sum, ds, n, s) == true)return true;
	return false;
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
