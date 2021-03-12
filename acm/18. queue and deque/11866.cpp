#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, K;
	cin >> N >> K;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	int tempK;
	cout << "<";
	while (q.size() != 1) {
		tempK = K-1;
		while (tempK--) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front();
	cout << ">";
	return;
}