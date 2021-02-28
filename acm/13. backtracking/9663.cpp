#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int answer = 0;

void solve();
bool attackable(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first || a.second == b.second || abs(a.first - b.first) == abs(a.second - b.second)) return true;
	else return false;
}
void backtrack(int depth, int Max, vector<pair<int, int>>& v) {
	if (depth == Max) {
		answer++;
		return;
	}

	for (int i = 0; i < Max; i++) {
		bool isAttackable = false;
		for (int j = 0; j < depth; j++) {
			if (attackable(v[j], { depth, i })) {
				isAttackable = true;
				break;
			}
		}
		if (!isAttackable) {
			v[depth] = { depth, i };
			backtrack(depth + 1, Max, v);
		}
	}
}

int main(void) {
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	backtrack(0, N, v);
	cout << answer;

	return;
}

// 1줄에 1개씩
