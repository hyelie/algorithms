#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N;
int arr[20][20];
int startstat, linkstat, diff_min = 999999999;
bool isStart[20] = { false, };
// isStart가 true면 start팀

void solve();
void backtrack(int depth, int previdx) {
	if (depth == N/2) {
		// N/2 ^2 다 계산해 주어야...
		vector<int> start_mem, link_mem;
		for (int i = 0; i < N; i++) {
			if (isStart[i]) start_mem.push_back(i);
			else link_mem.push_back(i);
		}

		startstat = 0;
		linkstat = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i == j)continue;
				startstat += arr[start_mem[i]][start_mem[j]];
				linkstat += arr[link_mem[i]][link_mem[j]];
			}
		}

		diff_min = min(diff_min, abs(startstat - linkstat));

		return;
	}

	for (int i = previdx; i < N; i++) {
		if (isStart[i] == false) {
			isStart[i] = true;
			backtrack(depth + 1, i);
			isStart[i] = false;
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	backtrack(0, 0);

	cout << diff_min;

	return;
}
// 20C10 = 1억 안됨