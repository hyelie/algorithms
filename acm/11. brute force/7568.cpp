#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;



void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;
	vector<pii> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	// 보는 애 : i
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
		}
		cout << cnt << ' ';
	}


	return;
}

// (x1, y1), (x2, y2)에서
// x1> x2 && y1 >> y2 -> 1이 더 큼.