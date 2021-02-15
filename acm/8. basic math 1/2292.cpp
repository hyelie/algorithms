#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1;
		return;
	}

	N--;
	int num = 1;

	while (N>0) {
		N -= 6*num;
		num++;
	}
	cout << num;

	return;
}

// 1 - 1개
// 2 3 4 5 6 7 - 6개
// 8 9 10 11 12 13 14 15 16 17 18 19 - 12개
// 20 ~ 37 - 18개


// 등비수열 합
// a(r^n-1) / r-1
// r = 6, a = 1
// (6^n-1)/5