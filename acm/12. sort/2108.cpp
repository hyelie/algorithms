#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;

	long long sum = 0;
	vector<int> v(8001, 0);
	int temp;
	int modeval = -1;
	int maxval = -4001, minval = 4001;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sum += temp;
		v[temp + 4000]++;
		modeval = max(v[temp + 4000], modeval);
		maxval = max(temp, maxval);
		minval = min(temp, minval);
	}
	// -4000 -> 0
	// 0 -> 4000
	// 4000 -> 8000
	cout << round((float)sum / (float)N) << '\n';
	vector<int> vtemp = v;


		int medianidx, tempN = (N - 1) / 2, i = minval + 4000;
		while (1) {
			if (v[i] == 0) {
				i++;
				continue;
			}
			if (tempN <= 0) {
				medianidx = i;
				break;
			}
			if (v[i] != 0) {
				tempN--;
				v[i]--;
			}
			
			
		}
		if (N % 2 == 0) {
			int mediannxtidx;
			while (1) {
				if (v[i] == 0) {
					i++;
				}
				else {
					mediannxtidx = i;
					break;
				}
			}
			cout << (medianidx + mediannxtidx - 8000) / 2 << '\n';
		}
		else  cout << medianidx - 4000 << '\n';

		v = vtemp;


	int modenum = 0, modefirst = -4001, modesecond = -4001;
	for (int i = 0; i < 8001; i++) {
		if (v[i] == modeval && modefirst == -4001) {
			modenum++;
			modefirst = i-4000;
		}
		else if (v[i] == modeval && modefirst != -4001) {
			modenum++;
			modesecond = i - 4000;
			break;
		}
	}
	if (modenum >= 2) cout << modesecond << '\n';
	else cout << modefirst << '\n';


	cout << maxval - minval << '\n';




	return;
}