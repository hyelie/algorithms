#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int arr[101];


void solve();
// 최대공약수
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

// 최소공배수
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
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int btwGCD;
	for (int i = 1; i < N; i++) {
		btwGCD = GCD(max(arr[0], arr[i]), min(arr[0], arr[i]));
		cout << arr[0] / btwGCD << '/' << arr[i] / btwGCD << '\n';
	}


	return;
}

/*

앞바퀴 / 뒤바퀴 = 비.
처음 : 4
다음 : 3/8 * 4 = 3/2

*/