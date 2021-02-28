#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 1초. 8! = 40,320

void solve();
// vector[i] : i+1 수를 썼는지 여부.
void backtrack(int M, int depth, vector<bool> &v, string &s) {
	if (M == depth) {
		cout << s<<'\n';
		return;
	}
	
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		if (!v[i]) {
			v[i] = true;
			s.push_back('0' + i+1); s.push_back(' ');
			backtrack(M, depth + 1, v, s);
			v[i] = false;
			s.pop_back(); s.pop_back();
		}
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

	// 1부터 N까지 중 중복 없이 M개
	vector<bool> v(N, false);

	backtrack(M, 0, v, s);

	return;
}