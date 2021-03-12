#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

// 조합 : 순서 상관 없음. 그래서 이전에 사용한 idx를 또 쓰면 중복되므로 previdx 이용.
void backtrack(int depth, int maxD, int prevIdx, vector<int>& num, vector<bool>& isUsed, vector<int>& combination) {
	if (depth == maxD) {
		for (int i = 0; i < combination.size(); i++) {
			cout << combination[i] << ' ';
		}cout << '\n';
		return;
	}

	for (int i = prevIdx; i < num.size(); i++) {
		if (isUsed[i] == false) {
			isUsed[i] = true; combination.push_back(num[i]);
			backtrack(depth + 1, maxD, i, num, isUsed, combination);
			isUsed[i] = false; combination.pop_back();
		}
	}


	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M;
	cin >> N >> M;
	// M : 길이
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		num[i] = i + 1;
	}
	vector<bool> isUsed(N, false);
	vector<int> combination;

	backtrack(0, M, 0, num, isUsed, combination);

	return;
}