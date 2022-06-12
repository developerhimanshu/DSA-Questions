#include <iostream>
#include <vector>
using namespace std;

//1. using 2 pointer approach
void rev2ptr(vector<int>&arr, int l, int r) {  //Reverse array using 2 pointer approach
	if (l >= r)return;
	swap(arr[l], arr[r]);
	rev2ptr(arr, l + 1, r - 1);
}

//2.Using 1 pointer recursion

void rev1ptr(vector<int>&arr, int i) {
	int n = arr.size();
	if (i >= n / 2)return;
	swap(arr[i], arr[n - i - 1]);
	rev1ptr(arr, i + 1);
}
int main()
{
	int n;
	cin >> n;
	//calling 2-pointer recursion approach
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	rev2ptr(arr, 0, n - 1);
	for (auto i : arr)
		cout << i << " ";
	cout << endl;

	//Calling 1 pointer recursion approach
	vector<int>brr(n);
	for (int i = 0; i < n; i++)
		cin >> brr[i];
	rev1ptr(brr, 0);
	for (auto i : brr)
		cout << i << " ";
	return 0;
}
