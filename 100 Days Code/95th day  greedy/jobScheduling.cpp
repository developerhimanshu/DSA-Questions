//We are given deadlines of a task and the profit using these deadlines
#include <bits/stdc++.h>
using namespace std;
struct Job {
public:
	char id;
	int deadline;
	int profit;

};

static bool cmp(Job j1, Job j2) {
	return (j1.profit > j2.profit);
}



void printJobScheduling(Job j[], int n) {
	sort(j, j + n,  cmp);
	vector<bool>lookup(n + 1, false);
	vector<int>result(n);
	for (int i = 0; i < n; i++) {
		for (int k = min(n, j[i].deadline) - 1; k >= 0; k--) {
			if (lookup[k] == false) {
				result[k] = i;
				lookup[k] = true;
				continue;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (lookup[i])
			cout << j[result[i]].id << " ";

}
int main()
{

	Job arr[] = { { 'a', 2, 100 },
		{ 'b', 1, 19 },
		{ 'c', 2, 27 },
		{ 'd', 1, 25 },
		{ 'e', 3, 15 }
	};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
	     "\n";

	// Function call
	printJobScheduling(arr, n);
	return 0;
}
