#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
// 중복순열 : 중복된 수 뽑아도 됨
void backtrack(int depth, int maxD, vector<int>& num,  vector<int>& permutation) {
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
	// M : 길이
	int N, M;
	cin >> N >> M;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		num[i] = i + 1;
	}
	vector<bool> used(N, false);
	vector<int> permutation;

	backtrack(0, M, num, permutation);





	return;
}