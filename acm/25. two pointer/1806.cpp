#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

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
	int N, S; cin >> N >> S;
	vector<int> v(N);

	for (int i = 1; i <= N; i++) {
		cin >> v[i-1];
	}

	int minlen = 100002, l = 0, r = 0, sum = 0;
	while (l <= r && r<=N) {
		if (sum >= S) {
			minlen = min(minlen, r - l);
			sum -= v[l];
			l++;
		}
		else {	// sum < S
			if (r == N) break;
			sum += v[r];
			r++;
		}
	}

	minlen = minlen == 100002 ? 0 : minlen;

	cout << minlen;

	return;
}