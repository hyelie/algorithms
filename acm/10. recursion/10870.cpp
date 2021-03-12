#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int fibo(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibo(n - 1) + fibo(n - 2);
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n;
	cin >> n;

	cout << fibo(n) << endl;

	return;
}