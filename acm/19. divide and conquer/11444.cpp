#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef vector<vector<long long>> mat;

void solve();
mat operator*(const mat& a, const mat& b) {
	int size = a.size();

	mat u(size, vector<long long>(size));
	for (long long i = 0; i < size; i++) {
		for (long long j = 0; j < size; j++) {
			long long sum = 0;
			for (long long k = 0; k < size; k++) {
				sum += a[i][k] * b[k][j] % MOD;
			}
			u[i][j] = sum % MOD;
		}
	}

	return u;
}

// a**n
mat mat_pow(mat a, long long n) {
	long long size = a.size();
	mat identity(size, vector<long long>(size, 0));
	for (int i = 0; i < size; i++) {
		identity[i][i] = 1;
	}


	if (n == 1) {
		return a * identity;
	}
	else if (n == 0) {
		return identity;
	}
	mat temp = mat_pow(a, n / 2);
	temp = temp * temp;
	if (n % 2 == 0) {
		return temp;
	}
	else {
		return a * temp;
	}
}


int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	long long N; cin >> N;
	

		mat input(2, vector<long long>(2, 1));
		input[1][1] = 0;

		input = mat_pow(input, N);
		cout << input[1][0];

		// 1번째, 2번째 때문에 이렇게 계산함

	


	return;
}

/*
피보나치
1 1
0 1

mat^n의 [1][0] : n번째 피보나치 수
*/