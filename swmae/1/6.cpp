#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M = 0;

vector<int> answer;

void solve();
void mysearch(int prev_profit, int size, int idx, vector<int> &profit) {
	// size�� 2��� �� : 1���� ������ �� �ִٴ� ��.
	if (size == 2) {
		int max_val = max(profit[idx], profit[idx + 1]);
		answer.push_back(max_val + prev_profit);
		return;
	}
	int left_half_max = *max_element(profit.begin() + idx, profit.begin() + idx + size / 2);
	int right_half_max = *max_element(profit.begin() + idx + size / 2, profit.begin() + idx + size);
	// ���� �����ϰ� ������ ���� �κ� ��
	mysearch(prev_profit + left_half_max, size / 2, idx + size / 2, profit);
	// ������ �����ϰ� ���� ���� �κ� ��
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
	// N, M ���
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

// DFS�ε� ���� ������