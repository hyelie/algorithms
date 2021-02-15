#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	int H, W, N;
	cin >> H >> W >> N;

	int unit = (N - 1) / H;
	unit++;
	int floor = N % H;
	if (floor == 0) floor = H;

	cout << floor;
	if (unit < 10) cout << '0';
	cout << unit << endl;


	return;
}



// ���η� ä���
// ���η� ä��� �Ǵ� �ų�
// (N-1) / H + 1-> �� ��° ȣ������ ����
// N % H -> �� ������ ����

// 6 12 10 -> 2ȣ�� / 4��
// 30 50 72 -> 3ȣ�� / 12��
// 6 12 6 -> 601�ε� 001�� ����