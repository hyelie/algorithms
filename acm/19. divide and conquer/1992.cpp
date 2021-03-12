#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int arr[64][64];

void solve();
void DFS(int len, int x, int y, string& s) {
	if (len == 1) {
		s.push_back(arr[x][y]);
		return;
	}
	
	bool isFull = true;
	int start = arr[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (start != arr[i][j]) {
				isFull = false; break;
			}
		}
	}

	if (!isFull) {
		s.push_back('(');
		DFS(len / 2, x, y, s);
		DFS(len / 2, x, y + len / 2, s);
		DFS(len / 2, x + len / 2, y, s);
		DFS(len / 2, x + len / 2, y + len / 2, s);
		s.push_back(')');
	}
	else {
		s.push_back(start);
	}

}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j];
		}
	}
	s = "";
	DFS(N, 0, 0, s);
	cout << s;

	return;
}