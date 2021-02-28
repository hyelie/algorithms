#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	int n; cin >> n;
	string answer = "";
	// n : max segments

	while (n > 0) {
		if (n % 2 == 1) {
			n -= 3;
			answer.push_back('7');
		}
		else {
			n -= 2;
			answer.push_back('1');
		}
	}

	cout << answer << endl;

	return;
}

/*
숫자 - 개수

개수 2개 : 1
개수 3개 : 7
개수 4개 : 4
개수 5개 : 5
개수 6개 : 9
개수 7개 : 8

segment 다 안쓰고 998244353보다 작은 경우


3이면 7이 나음
4면 11이 나음
5면 71이 나음
6이면 111
7이면 711

*/