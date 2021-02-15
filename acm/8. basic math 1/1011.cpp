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

 이런식으로 양 끝에서 1만 올릴 수 있게 하고

123...n...321
만약 n이 숫자가 안맞는다고 치면 다른 데서 숫자를 떼오면 되는거다.
예를 들어 18이면 123nn321인데, nn을 33으로 채우면 되는 거고.
31이면 12345n54321인데, 이러면 1234 434 4321이런식으로 떼오면 되는 거다.
만약 가운데 434가 55 안으로 해결 가능 했으면 55나 54나 44 이런식으로 해결했겠지만
10으로 해결 불가능하기 때문에 무조건 한 수가 더 있어야 한다.
이렇게 바꾸어도 자리수는 변하지 않으니까(수를 떼오는 거니까) 계산하면 된다.

*/