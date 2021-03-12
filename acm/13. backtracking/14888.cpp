#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int arr[11];
int N, addnum, subnum, mulnum, divnum, maxval = -1000000001, minval = 1000000001;

void solve();
void backtrack(int depth, int result) {
	if (depth == N - 1) {
		maxval = max(maxval, result);
		minval = min(minval, result);
	}

	if (addnum > 0) {
		addnum--;
		backtrack(depth + 1, result + arr[depth + 1]);
		addnum++;
	}
	if (subnum > 0) {
		subnum--;
		backtrack(depth + 1, result - arr[depth + 1]);
		subnum++;
	}
	if (mulnum > 0) {
		mulnum--;
		backtrack(depth + 1, result * arr[depth + 1]);
		mulnum++;
	}
	if (divnum > 0) {
		divnum--;
		backtrack(depth + 1, result / arr[depth + 1]);
		divnum++;
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
		cin >> arr[i];
	}
	cin >> addnum >> subnum >> mulnum >> divnum;

	backtrack(0, arr[0]);

	cout << maxval << '\n' << minval;

	return;
}

// 수의 개수 11개
// 연산자 총 10개
// 모두 다른 연산자라 쳐도 10! = 1천만 이하.