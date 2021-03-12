#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

// 중복조합 : 중복되는 수 뽑아도 되지만 이전에 쓴거 또 쓰면 안되니까 previdx 이용
void backtrack(int depth, int maxD, int prevIdx, vector<int>& num, vector<int>& combination) {
	if (depth == maxD) {
		for (int i = 0; i < combination.size(); i++) {
			cout << combination[i] << ' ';
		}cout << '\n';
		return;
	}

	for (int i = prevIdx; i < num.size(); i++) {
		combination.push_back(num[i]);
		backtrack(depth + 1, maxD, i, num, combination);
		combination.pop_back();

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
		//cin >> num[i];
	}
	//sort(num.begin(), num.end());
	vector<bool> isUsed(N, false);
	vector<int> combination;

	backtrack(0, M, 0, num, combination);

	return;
}