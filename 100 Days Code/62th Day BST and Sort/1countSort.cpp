#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int k)
{
	int count[k];
	// for (int i = 0; i < k; ++i)
	// {
	// 	count[i] = 0;
	// }
	memset(count, 0, sizeof(count));
	for (int i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}
	for (int i = 1; i < n; i++)
	{
		count[i] += count[i - 1];
	}
	int output[n];
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}
int main()
{
	int arr[] = {1, 3, 4, 2, 1, 0};
	countSort(arr, 6, 5);
	for (int x : arr)
		cout << x << " ";
	return 0;
}
