#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	if (n <= 1)
		return n;
	int last = fib(n - 1);
	int slast = fib(n - 2);  //for every function we are doing two recursion calls therfor the time complexity will be 2^n

	return last + slast;
}
int main()
{
	int n;
	cin >> n;
	cout << fib(1);


	return 0;
}
