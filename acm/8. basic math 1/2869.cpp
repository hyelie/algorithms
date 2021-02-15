#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve();
void solve_iter();

int main(void) {
	solve();
	return 0;
}

void solve() {
	int A, B, V;
	cin >> A >> B >> V;

	int day = ceil((double)(V - A) / (double)(A - B)) + 1;
	cout << day;

	return;
}

// V-A만큼 올라가는 데 n일이 걸리면 n+1번째 날에 통과함
// (V-A)/(A-B) + 1 -> 앞항이 소수면 양수취급
// 3/1 + 1 = 4
// 1/4 + 1 = 2
// 999999900 / 1 + 1