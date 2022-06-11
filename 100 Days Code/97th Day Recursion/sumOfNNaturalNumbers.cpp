#include <bits/stdc++.h>
using namespace std;

//Parmeterised Recursion
void sum(int n, int s) {
	if (n < 0) {
		cout << s << endl;
		return;
	}
	sum(n - 1, s + n);
}

//Functional Recursion
int sum(int n) {
	if (n == 0)return 0;
	return n + sum(n - 1);
}
int main()
{
	int n;
	cin >> n;
	cout << "From Parmeterised Recursion: " << sum(n) << endl;
	cout << "From functional Recursion: "; sum(n, 0);
	return 0;
}