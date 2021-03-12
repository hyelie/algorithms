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
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int l = 0, r = N - 1, min_val = 2100000000, sum;
	int ansl, ansr;
	while (1) {
		if (l >= r || l < 0 || l >= N || r < 0 || r >= N) {
			break;
		}
		sum = v[l] + v[r];
		if (sum == 0) {
			ansl = l;
			ansr = r;
			break;
		}
		if (abs(sum) < min_val) {
			ansl = l; ansr = r;
			min_val = abs(sum);
		}

		if (sum > 0) {
			r--;
		}
		else if (sum < 0) {
			l++;
		}
	}

	cout << v[ansl] << " " << v[ansr];


	return;
}