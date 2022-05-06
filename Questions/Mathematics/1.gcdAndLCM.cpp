#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
void solve()
{
	int a, b;
	cin >> a >> b;
	int res = gcd(a, b);
	cout << res << endl;
	cout << lcm(a, b) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
