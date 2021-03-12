#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	vector<pair<int, int>> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int w, h;

	if (v[0].first == v[1].first) w = v[2].first;
	else if (v[0].first == v[2].first) w = v[1].first;
	else w = v[0].first;

	if (v[0].second == v[1].second) h = v[2].second;
	else if (v[0].second == v[2].second) h = v[1].second;
	else h = v[0].second;

	cout << w << ' ' << h;

	return;
}