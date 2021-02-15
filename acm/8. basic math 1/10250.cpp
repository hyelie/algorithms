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



// 세로로 채우고
// 가로로 채우면 되는 거네
// (N-1) / H + 1-> 몇 번째 호실인지 나옴
// N % H -> 몇 층인지 나옴

// 6 12 10 -> 2호실 / 4층
// 30 50 72 -> 3호실 / 12층
// 6 12 6 -> 601인데 001로 나옴