#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();
long long mypow(int a, int b, int c) {
	if (b == 0) {
		return 1;
	}
	long long temp = mypow(a, b / 2, c);
	temp = temp * temp % c;
	if (b % 2 == 0) {
		return temp;
	}
	else {
		return temp * a % c;
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

	cout << mypow(A, B , C);

	return;
}

// °í¼Ó °ö¼À ¾Ë°í¸®Áò
// A**B % C

/*

nÀÌ Â¦¼ö - 2^n = 2^n/2 * 2^n/2
 Â¦¼ö - 2^n = 2^(n/2-1) * 2^(n/2-1) * 2

*/