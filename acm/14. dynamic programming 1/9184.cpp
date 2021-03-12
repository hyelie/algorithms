#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int w[101][101][101];
bool memo[101][101][101] = { false, };

void solve();

int recurse(int a, int b, int c) {
	if (memo[a + 50][b + 50][c + 50]) {
		return w[a + 50][b + 50][c + 50];
	}
	


	if (a <= 0 || b <= 0 || c <= 0) {
		w[a + 50][b + 50][c + 50] = 1;
		memo[a + 50][b + 50][c + 50] = true;
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		w[a + 50][b + 50][c + 50] = recurse(20, 20, 20);
		memo[a + 50][b + 50][c + 50] = true;
		return recurse(a, b, c);
	}
	if (a < b && b < c) {
		w[a + 50][b + 50][c + 50] = recurse(a, b, c - 1) + recurse(a, b - 1, c - 1) - recurse(a, b - 1, c);
		memo[a + 50][b + 50][c + 50] = true;
		return w[a + 50][b + 50][c + 50];
	}
	else {
		w[a + 50][b + 50][c + 50] = recurse(a - 1, b, c) + recurse(a - 1, b - 1, c) + recurse(a - 1, b, c - 1) - recurse(a - 1, b - 1, c - 1);
		memo[a + 50][b + 50][c + 50] = true;
		return w[a + 50][b + 50][c + 50];
	}
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int a, b, c;

	cin >> a >> b >> c;
	while (!(a == -1 && b == -1 && c == -1)) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, recurse(a, b, c));

		cin >> a >> b >> c;
	}

	return;
}