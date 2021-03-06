#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve();
void backtrack(int depth, int Max, int N, int prev, string &s) {
	if (depth == Max) {
		cout << s << '\n';
		return;
	}

	for (int i = prev; i < N + 1; i++) {
		s.push_back(i + '0'); s.push_back(' ');
		backtrack(depth + 1, Max, N, i, s);
		s.pop_back(); s.pop_back();
	}
}

int main(void) {
	solve();
	return 0;
}

void solve() {
	int N, M;
	cin >> N >> M;
	string s = "";

	backtrack(0, M, N, 1, s);

	return;
}