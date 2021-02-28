#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve();

// 1�� Ǯ��
// v[i] : ���� ���ڸ� true, �ƴϸ� false
void backtrack(int depth, int M, vector<bool>& v, string&s) {
	if (depth == M) {
		cout << s << '\n';
		return;
	}
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		if (!v[i]) {
			// ��ū�� �߿� ����Ѱ� �������. ���Ǿ����� true
			bool isBigUsed = false;
			for (int j = i + 1; j < vsize; j++) {
				if (v[j]) {
					isBigUsed = true; break;
				}
			}
			if (!isBigUsed) {
				v[i] = true; s.push_back('0' + i + 1); s.push_back(' ');
				backtrack(depth + 1, M, v, s);
				v[i] = false; s.pop_back(); s.pop_back();
			}
		}
	}
}

// 2�� Ǯ��. prev : ������ ����� ����.
void backtrack(int depth, int M, vector<bool>& v, string& s, int prev) {
	if (depth == M) {
		cout << s << '\n';
		return;
	}
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		if (!v[i] && i+1 >= prev) {
			// ��ū�� �߿� ����Ѱ� �������. ���Ǿ����� true
			v[i] = true; s.push_back('0' + i + 1); s.push_back(' ');
			backtrack(depth + 1, M, v, s, i + 1);
			v[i] = false; s.pop_back(); s.pop_back();
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M;
	cin >> N >> M;
	vector<bool> v(N, false);
	string s = "";

	// 1�� Ǯ��
	//backtrack(0, M, v, s);

	// 2�� Ǯ��
	backtrack(0, M, v, s, -1);

	return;
}