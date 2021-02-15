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
	// iter : 분모+분자의 합(군집을 먼저 구함)
	// cout << iter-1<<" "<<sum << endl;

	// iter가 짝수면 자연수(n/1)부터 낮은 숫자임
	// iter가 홀수면 제일 작은(1/n) 수부터 낮은 숫자임

	int kth = N_origin - sum;
	// 각 군집에서 몇 번째 숫자인지 구함
	//cout << kth << endl;
	if (iter % 2 == 0) {
		cout<<iter-kth<<'/'<<kth<<endl;
	}
	else {
		cout << kth << '/' << iter - kth << endl;
	}

	return;
}

// 1 -> 합이 2
// 2, 3 -> 합이 3
// 4, 5, 6 -> 합이 4