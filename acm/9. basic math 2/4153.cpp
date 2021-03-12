#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	vector<int> tri(3);
	while (1) {
		cin >> tri[0] >> tri[1] >> tri[2];
		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0) break;
		sort(tri.begin(), tri.end());
		if (pow(tri[0], 2) + pow(tri[1], 2) == pow(tri[2], 2)) cout << "right\n";
		else cout << "wrong\n";
	}
	

	return;
}