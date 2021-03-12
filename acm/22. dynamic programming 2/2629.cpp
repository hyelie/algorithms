#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int weight[31];
int ball[8];
int N;
bool dp[31][40001] = { false, };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	// dp[i][j] : i��° �����߱��� ������� �� j g�� Ȯ���� �� �ִ���
	dp[0][weight[0]] = true;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= 40000; j++) {
			if (dp[i-1][j]) {
				if (j + weight[i] <= 40000) {
					dp[i][j + weight[i]] = true;
				}
				if (abs(j - weight[i]) <= 40000) {
					dp[i][abs(j - weight[i])] = true;
				}
				dp[i][j] = true;
			}
		}
		dp[i][weight[i]] = true;
	}
	
	// dp[i]�� �ϸ� �ȵǴ� ����
	// �� 1¥�� �ö� ����. weight = 1�� true
	// �ٵ� 3¥�� �ö󰣴� ġ�� �׷� weight = 4�� true�� ��
	// weight = 7�� true�� ��
	// �̰� ��������.




	int ballnum; cin >> ballnum;
	for (int i = 0; i < ballnum; i++) {
		cin >> ball[i];
		if (dp[N-1][ball[i]]) {
			cout << "Y ";
		}
		else cout << "N ";
	}




	return;
}

/*

dp[i][j] : i��° �����߱��� ������� �� j g�� Ȯ���� �� �ִ���

��� 3����.
1) i��° �����߸� ������� �ʴ� ���
2) i��° �����߸� �����ʿ� �ø� ������(���� weight���� ������) -> abs ó�� �ʿ�
3) i��° �����߸� ���� �ݴ��� �ø� ������(���� weight���� ���Ұ���)


*/

