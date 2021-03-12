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

원 중심 두개 사이의 거리 > 반지름의 합 -> 0개(안닿임
원 중심 두개 사이의 거리 == 반지름의 합 -> 1개(교점)
원 중심 두개 사이의 거리 < 반지름의 합
	원 중심 사이 거리 = 큰반지름 - 짧은반지름 -> 1개(교점)
	원 중심 사이 거리 > 큰반지름 - 짧은반지름 -> 2개(교점)
	원 중심 사이 거리 < 큰반지름 - 짧은반지름 -> 0개(교점)

*/