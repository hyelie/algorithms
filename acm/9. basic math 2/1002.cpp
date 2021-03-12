#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	double sum = (r1 + r2) * (r1 + r2);
	double sub = (r1 - r2) * (r1 - r2);

	if (dist == 0 && sub == 0) cout << "-1\n";
	else if (sub > dist || sum < dist) cout << "0\n";
	else if (sum == dist || sub == dist) cout << "1\n";
	else cout << "2\n";

	


	


	return;
}

/*

�� �߽� �ΰ� ������ �Ÿ� > �������� �� -> 0��(�ȴ���
�� �߽� �ΰ� ������ �Ÿ� == �������� �� -> 1��(����)
�� �߽� �ΰ� ������ �Ÿ� < �������� ��
	�� �߽� ���� �Ÿ� = ū������ - ª�������� -> 1��(����)
	�� �߽� ���� �Ÿ� > ū������ - ª�������� -> 2��(����)
	�� �߽� ���� �Ÿ� < ū������ - ª�������� -> 0��(����)

*/