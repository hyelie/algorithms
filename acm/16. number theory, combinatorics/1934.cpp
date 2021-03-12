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

��Ŭ���� ȣ����
�� �ڿ��� a, b���� ū���� a
a%b = n�̶� �Ҷ�
n=0�̸� b�� GCD(�ִ�����)
n != 0�̸� a�ڸ��� b�ְ�, b�ڸ��� n�ְ� �ݺ�

*/