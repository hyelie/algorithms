#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
// 순열 : 순서 상관 있으니까 사용한 정보 used 이용.
void backtrack(int depth, int maxD, vector<int>& num, vector<bool>& used, vector<int> &permutation) {
	if (depth == maxD) {
		for (int i = 0; i < permutation.size(); i++) {
			cout << permutation[i] << " ";
		}cout << '\n';
		return;
	}
	for (int i = 0; i < num.size(); i++) {
		if (used[i] == false) {
			permutation.push_back(num[i]); used[i] = true;
			backtrack(depth + 1, maxD, num, used, permutation);
			permutation.pop_back(); used[i] = false;
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	// M : 길이
	int N, M;
	cin >> N>>M;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		num[i] = i + 1;
	}
	vector<bool> used(N, false);
	vector<int> permutation;

	backtrack(0, M, num, used, permutation);





	return;
}