#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
void solve_iter();

int main(void) {
	solve();
	return 0;
}

void solve() {
	vector<vector<int>> room(15, vector<int>(15));
	// room[i][j] : iÃþ jÈ£
	for (int j = 1; j < 15; j++) {
		room[0][j] = j;
	}
	// ¾ÆÆÄÆ® °¡µæ Ã¤¿ò
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {

			if (j == 1) room[i][j] = room[i - 1][j];
			else room[i][j] = room[i - 1][j] + room[i][j - 1];
		}
	}

	int N;
	cin >> N;
	while (N--) {
		int k, n;
		cin >> k >> n;
		cout << room[k][n] << endl;
	}

	return;
}

// 0ÃþÀÇ iÈ£ : i¸í(ÃÊ±âÈ­), 1È£ºÎÅÍ Á¸Àç

// 0Ãþ
// 1 2 3 4 5 ...
// 1Ãþ
// 1 3 6 10 15 ...
// 2Ãþ
// 1 4 10 20 35 ...

// room[i][j] = room[i - 1][j] + room[i][j - 1];
// iÃþÀÇ j-1È£ : i-1ÃþÀÇ j-1È£±îÁö ÇÕ
// iÃþÀÇ jÈ£ : i-1ÃþÀÇ jÈ£±îÁö ÇÕ = iÃþÀÇ j-1È£ + i-1ÃþÀÇ jÈ£