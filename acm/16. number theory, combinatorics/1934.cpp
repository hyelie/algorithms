#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();
int GCD(int a, int b) {
	int n;
	while (1) {
		if (a % b == 0) {
			return b;
		}
		else {
			n = a % b;
			a = b;
			b = n;
		}
	}
}

int LCM(int a, int b) {
	return a * b / GCD(max(a, b), min(a, b));
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int T; cin >> T;
	while (T--) {
		int a, b; cin >> a >> b;
		cout << LCM(max(a, b), min(a, b))<<'\n';
	}

	return;
}

/*

유클리드 호제법
두 자연수 a, b에서 큰쪽이 a
a%b = n이라 할때
n=0이면 b가 GCD(최대공약수)
n != 0이면 a자리에 b넣고, b자리에 n넣고 반복

*/