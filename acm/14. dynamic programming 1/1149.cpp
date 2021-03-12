#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	// r, g, b : i번째 집을 r, g, b로 칠했을 때 최소값
	int r = 0, g = 0, b = 0;
	int i1, i2, i3;
	int tempr, tempg, tempb;

	cin >> i1 >> i2 >> i3;
	r = i1; g = i2; b = i3;
	for (int i = 1; i < N; i++) {
		cin >> i1 >> i2 >> i3;
		tempr = min(g + i1, b + i1);
		tempg = min(r + i2, b + i2);
		tempb = min(r + i3, g + i3);
		r = tempr; g = tempg; b = tempb;
	}

	cout << min(min(r, g), b);

	return;
}