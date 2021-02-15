#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	solve();
	return 0;
}

void solve() {
	int N, N_origin;
	cin >> N;
	N_origin = N;
	int iter = 1;
	int sum = 0;
	while (N > 0) {
		N -= iter;
		sum += iter;
		iter++;
	}
	sum -= iter-1;
	// iter : �и�+������ ��(������ ���� ����)
	// cout << iter-1<<" "<<sum << endl;

	// iter�� ¦���� �ڿ���(n/1)���� ���� ������
	// iter�� Ȧ���� ���� ����(1/n) ������ ���� ������

	int kth = N_origin - sum;
	// �� �������� �� ��° �������� ����
	//cout << kth << endl;
	if (iter % 2 == 0) {
		cout<<iter-kth<<'/'<<kth<<endl;
	}
	else {
		cout << kth << '/' << iter - kth << endl;
	}

	return;
}

// 1 -> ���� 2
// 2, 3 -> ���� 3
// 4, 5, 6 -> ���� 4