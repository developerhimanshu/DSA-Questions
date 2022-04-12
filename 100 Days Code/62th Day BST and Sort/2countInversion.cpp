#include <bits/stdc++.h>
using namespace std;
int res = 0;
void countNdMerge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int temp[n1 + n2];
	int i = left;
	int j = mid;
	int k = left;

	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			res = res + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		countNdMerge(arr, left, mid, right);
	}
}

int inversionCount(int arr[], int n)
{
	mergeSort(arr, 0, n - 1);
	int count = res;
	res = 0;
	return count;
}
int main()
{
	int arr[] = {2, 4, 1, 3, 5};
	cout << "The inversion pairs in the array are: " << inversionCount(arr, 5);
	return 0;

}
