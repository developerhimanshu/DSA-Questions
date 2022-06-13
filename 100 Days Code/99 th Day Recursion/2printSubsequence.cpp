#include <bits/stdc++.h>
using namespace std;


void subsequences(int ind, vector<int>&ds, int arr[], int n)
{
	if (ind >= n) {
		for (auto x : ds)
			cout << x << " ";
		if (ds.size() == 0)
			cout << "{}";
		cout << endl;

		return;
	}
	//if you want to print the output in reverse order then put the don't pick condition in first
	// subsequences(ind + 1, ds, arr, n); //This won't take the elemnt and print

	//take or pick the particular index into the subseqeunce
	ds.push_back(arr[ind]);
	subsequences(ind + 1, ds, arr, n); //This will take the element and print
	ds.pop_back();

	// not pick, or not take condition, this element is not added to you subsequence
	subsequences(ind + 1, ds, arr, n); //This won't take the elemnt and print
}
int main()
{
	int arr[] = {3, 1, 2};
	int n = 3;
	vector<int>ds;
	subsequences(0, ds, arr, n);

	return 0;
}
