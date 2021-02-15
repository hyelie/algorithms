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
	int x, y;
	cin >> x >> y;
	int len = y - x;

	int cnt = 0;
	int move = 1;
	bool isOdd = true;

	while (len > 0) {
		len -= move;
		if (!isOdd) {
			move++;
			isOdd = true;
		}
		else isOdd = false;
		cnt++;
	}

	cout << cnt<<endl;

	return;
}



/*

 1 : 1
 2 : 11
 3 : 111
 4 : 121
 5 : 1211
 6 : 1221
 7 : 12211
 8 : 12221
 9 : 12321
 10 : 122221

 �̷������� �� ������ 1�� �ø� �� �ְ� �ϰ�

123...n...321
���� n�� ���ڰ� �ȸ´´ٰ� ġ�� �ٸ� ���� ���ڸ� ������ �Ǵ°Ŵ�.
���� ��� 18�̸� 123nn321�ε�, nn�� 33���� ä��� �Ǵ� �Ű�.
31�̸� 12345n54321�ε�, �̷��� 1234 434 4321�̷������� ������ �Ǵ� �Ŵ�.
���� ��� 434�� 55 ������ �ذ� ���� ������ 55�� 54�� 44 �̷������� �ذ��߰�����
10���� �ذ� �Ұ����ϱ� ������ ������ �� ���� �� �־�� �Ѵ�.
�̷��� �ٲپ �ڸ����� ������ �����ϱ�(���� ������ �Ŵϱ�) ����ϸ� �ȴ�.

*/