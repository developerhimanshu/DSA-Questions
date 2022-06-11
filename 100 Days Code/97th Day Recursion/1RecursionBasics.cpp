#include <bits/stdc++.h>
using namespace std;

void printNums(int n, int i) {
	if (i > n) {
		return;
	}
	printNums(n, i + 1);
	cout << i << endl; //back-track
}
int main()
{
	int n;
	printNums(5, 0);
	return 0;
}
