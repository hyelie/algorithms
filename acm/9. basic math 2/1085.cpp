#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(x, y), min(w-x, h-y)) << '\n';

	return;
}