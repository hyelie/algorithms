#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
int cal_diff(int x, int y, vector<vector<bool>>& input, vector<vector<bool>>& stdd1, vector<vector<bool>>& stdd2) {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (stdd1[i][j] != input[x + i][y + j]) cnt1++;
			if (stdd2[i][j] != input[x + i][y + j]) cnt2++;
		}
	}
	return min(cnt1, cnt2);
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M;
	// v[i][j] = true : white, false : black.
	vector<vector<bool>> eight_white =
	{
		{true, false, true, false, true, false, true, false},
		{false, true, false, true, false, true, false, true},
		{true, false, true, false, true, false, true, false},
		{false, true, false, true, false, true, false, true},
		{true, false, true, false, true, false, true, false},
		{false, true, false, true, false, true, false, true},
		{true, false, true, false, true, false, true, false},
		{false, true, false, true, false, true, false, true}
	};
	vector<vector<bool>> eight_black =
	{
		{false, true, false, true, false, true, false, true},
		{true, false, true, false, true, false, true, false},
		{false, true, false, true, false, true, false, true},
		{true, false, true, false, true, false, true, false},
		{false, true, false, true, false, true, false, true},
		{true, false, true, false, true, false, true, false},
		{false, true, false, true, false, true, false, true},
		{true, false, true, false, true, false, true, false}
	};

	cin >> N >> M;
	vector<vector<bool>> v(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'W') v[i][j] = true;
			else v[i][j] = false;
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << v[i][j] << ' ';
		}cout << endl;
	}*/

	int min_val = 65;

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			min_val = min(min_val, cal_diff(i, j, v, eight_white, eight_black));
		}
	}
	cout << min_val;


	return;
}