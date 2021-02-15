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
	int A, B, C;
	cin >> A >> B >> C;

	if (C - B <= 0) cout << -1;
	else {
		cout << A / (C - B) + 1;
	}


	return;
}

// Cx > A + Bx
// (C-B)x > A
// x > A/(C-B)