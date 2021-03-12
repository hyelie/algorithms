#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve();
bool decompose(int N) {
	string s = to_string(N);
	for (int i = 2; i < s.length(); i++) {
		if (s[i] == '6' && s[i - 1] == '6' && s[i - 2] == '6') return true;
	}
	return false;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	int i = 1;
	while (1) {
		if (decompose(i)) {
			N--;
		}
		if (N == 0) {
			cout << i << '\n';
			break;
		}
		i++;
	}

	return;
}