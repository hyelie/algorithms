#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int N;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;
	vector<pii> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	vector<int> result(N, -1);

	// stack, 더 큰 수가 들어옴 -> pop
	stack<pii> s;
	for (int i = 0; i < N;) {
		if (s.empty() || A[i].first <= s.top().first) {
			s.push(A[i]);
			i++;
		}
		// 더 큰 수가 들어옴 -> top에 있는거 pop하고 top에 있는 정보 작성.
		else {
			result[s.top().second] = A[i].first;
			s.pop();
		}
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}


	return;
}