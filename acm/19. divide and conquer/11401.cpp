#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();
// ���� �ſ� Ŀ�� �� ������ ���� c�� �־ �������� �����.
long long mypow(int a, int b) {
	if (b == 0) {
		return 1;
	}
	long long temp = mypow(a, b / 2) % MOD;
	temp = temp * temp % MOD;
	if (b % 2 == 0) {
		return temp;
	}
	else {
		return temp * a % MOD;
	}
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, K;
	cin >> N >> K;
	long long KF = 1;
	for (int i = 2; i <= K; i++) {
		KF = KF * i % MOD;
	}
	long long last = mypow(KF, MOD - 2);

	long long first = 1;
	for (int i = N - K + 1; i <= N; i++) {
		first = first * i % MOD;
	}

	cout << first * last % MOD;

	return;
}

/*

�丣���� ������
a^(p-1) = 1 % p, �� �� p�� �Ҽ�
nCr = n! / ((n-r)! * r!)
�׷��� �м������� % ������ ������ ���� -> �� ������ ������.
���� x / y = (x * y^(p-2)) / (y * y^(p-2)) = x * y^(p-2) / 1 mod p

��
n * n-1 * ... * n-k+1 * k!^(p-2) % MOD

https://mapocodingpark.blogspot.com/2020/02/BOJ-11401.html
*/