#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();
// 수가 매우 커질 수 있으니 보통 c를 넣어서 나머지를 출력함.
long long mypow(int a, int b) {
	if (b == 0) {
		return 1;
	}
	long long temp = mypow(a, b / 2);
	temp = temp * temp;
	if (b % 2 == 0) {
		return temp;
	}
	else {
		return temp * a;
	}
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int A, B, C;
	cin >> A >> B >> C;

	cout << mypow(A, B, C);

	return;
}

// 고속 곱셈 알고리즘
// A**B % C

/*

n이 짝수 - 2^n = 2^n/2 * 2^n/2
 짝수 - 2^n = 2^(n/2-1) * 2^(n/2-1) * 2

 O(logn)

*/