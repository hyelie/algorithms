#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M = 0;

vector<int> answer;

void solve();
void mysearch(int prev_profit, int size, int idx, vector<int> &profit) {
	// size가 2라는 말 : 1개만 개발할 수 있다는 말.
	if (size == 2) {
		int max_val = max(profit[idx], profit[idx + 1]);
		answer.push_back(max_val + prev_profit);
		return;
	}
	int left_half_max = *max_element(profit.begin() + idx, profit.begin() + idx + size / 2);
	int right_half_max = *max_element(profit.begin() + idx + size / 2, profit.begin() + idx + size);
	// 왼쪽 개발하고 오른쪽 남은 부분 봄
	mysearch(prev_profit + left_half_max, size / 2, idx + size / 2, profit);
	// 오른쪽 개발하고 왼쪽 남은 부분 봄
	mysearch(prev_profit + right_half_max, size / 2, idx, profit);
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;
	// N, M 계산
	int tempN = N;
	while (tempN != 1) {
		tempN /= 2;
		M++;
	}
	vector<int> profit(N);
	for (int i = 0; i < N; i++) {
		cin >> profit[i];
	}
	mysearch(0, N, 0, profit);

	cout << *max_element(answer.begin(), answer.end());
	


	return;
}

// DFS인데 구현 귀찮네