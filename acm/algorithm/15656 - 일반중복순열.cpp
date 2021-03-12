#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
void backtrack(int depth, int maxD, vector<int>& num, vector<int>& permutation) {
	if (depth == maxD) {
		for (int i = 0; i < permutation.size(); i++) {
			cout << permutation[i] << " ";
		}cout << '\n';
		return;
	}
	for (int i = 0; i < num.size(); i++) {

		permutation.push_back(num[i]);
		backtrack(depth + 1, maxD, num, permutation);
		permutation.pop_back();

	}
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	// M : ±æÀÌ
	int N, M;
	cin >> N >> M;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	vector<bool> used(N, false);
	vector<int> permutation;

	backtrack(0, M, num, permutation);





	return;
}