#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

void solve();

bool mycomp(const int& a, const int& b) {
	return a > b;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	string s; cin >> s;
	vector<char> v(s.length());
	for (int i = 0; i < s.length(); i++) {
		v[i] = s[i];
	}
	sort(v.begin(), v.end(), mycomp);
	for (int i = 0; i < s.length(); i++) {
		cout << v[i];
	}

	return;
}