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
	int n; cin >> n;
	vector<vector<int>> tri(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		tri[i][0] += tri[i - 1][0];
		tri[i][i] += tri[i - 1][i - 1];
		for (int j = 1; j < i; j++) {
			tri[i][j] = tri[i][j] + max(tri[i - 1][j], tri[i - 1][j - 1]);
		}
	}

	cout << *max_element(tri[n - 1].begin(), tri[n - 1].end());

	return;
}