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
	int f, s;
	while (1) {
		cin >> f >> s;
		if (f == 0 && s == 0) break;

		bool factor = (s % f == 0);
		bool multiple = (f % s == 0);

		if (factor) cout << "factor\n";
		else if (multiple) cout << "multiple\n";
		else cout << "neither\n";
	}

	return;
}