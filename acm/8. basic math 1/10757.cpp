#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve();
int cal_char(char a, char b, bool isUp) {
	int alpha = a - '0';
	int beta = b - '0';

	int sum = alpha + beta + (isUp ? 1 : 0);

	if (sum >= 10) return sum - 10;
	else return sum;
}

bool up(char a, char b, bool isUp) {
	int alpha = a - '0';
	int beta = b - '0';
	if ((alpha + beta + (isUp ? 1 : 0)) >= 10) return true;
	else return false;
}

int main(void) {
	solve();
	return 0;
}

void solve() {
	string a, b, result="";
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int short_len = min(a.length(), b.length());

	int i;
	result.push_back(cal_char(a[0], b[0], false) + '0');
	bool isUp = up(a[0], b[0], false);
	for (i = 1; i < short_len; i++) {
		result.push_back(cal_char(a[i], b[i], isUp) + '0');
		isUp = up(a[i], b[i], isUp);
	}
	if (a.length() > b.length()) {
		for (i = short_len; i < a.length(); i++) {
			result.push_back(cal_char(a[i], '0', isUp) + '0');
			isUp = up(a[i], '0', isUp);
		}
	}
	else {
		for (i = short_len; i < b.length(); i++) {
			result.push_back(cal_char(b[i], '0', isUp) + '0');
			isUp = up(b[i], '0', isUp);
		}
	}
	if (isUp) result.push_back('1');

	reverse(result.begin(), result.end());

	cout << result << endl;

	return;
}

// 10보다 '크다' 가 아니라 '크거나 같다'일 때 올림이 올라감. 이를 유의했어야 했음.