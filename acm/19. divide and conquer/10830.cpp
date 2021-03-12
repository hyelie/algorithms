#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
				sum += a[i][k] * b[k][j] % 1000;
			}
			u[i][j] = sum % 1000;
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
	
	if (n == 0) {
		return identity;
	}
	if (n == 1) {
		return a * identity;
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
	int N; long long B;
	cin >> N >> B;
	mat input(N, vector<long long>(N));
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	input = mat_pow(input, B);

	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < N; j++) {
			cout<< input[i][j]<<' ';
		}
		cout << '\n';
	}


	return;
}

/* 
문제 조건을 정확하게 보지 않았음.
1000보다 같은 자연수 -> 0이 나와야 함 -> identity와 곱해서 나머지 처리 해주어야 함.
*/