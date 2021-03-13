#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int N, board[33][33];
vector<int> answer;

void solve();
int find_max(int row_size, int col_size, int x, int y) {
	int mymax = -1;
	for (int i = x; i < x + row_size; i++) {
		for (int j = y; j < y + col_size; j++) {
			mymax = max(mymax, board[i][j]);
		}
	}
	return mymax;
}
// row_size : ���α���, col_size ; ���α���
// x, y : row / col ��ǥ
void search(int prev_profit, int row_size, int col_size, int x, int y) {
	if (row_size * col_size == 2) {
		int temp = find_max(row_size, col_size, x, y);
		answer.push_back(prev_profit + temp);
		return;
	}

	// ���� ���̰� 1�� �ƴϾ�� Ž������
	if (col_size != 1) {
		int left = find_max(row_size, col_size / 2, x, y);
		search(prev_profit + left, row_size, col_size / 2, x, y + col_size / 2);

		int right = find_max(row_size, col_size / 2, x, y + col_size / 2);
		search(prev_profit + right, row_size, col_size / 2, x, y);
	}

	// ���� ���̰� 1�� �ƴϾ�� Ž������
	if (row_size != 1) {
		int up = find_max(row_size / 2, col_size, x, y);
		search(prev_profit + up, row_size / 2, col_size, x + row_size / 2, y);

		int down = find_max(row_size / 2, col_size, x + row_size / 2, y);
		search(prev_profit + down, row_size / 2, col_size, x, y);
	}

	
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	search(0, N, N, 0, 0);

	cout << *max_element(answer.begin(), answer.end());

	return;
}

/*

���� ������ ����, backtrack(����Ž��)
������ �����µ�, ��Ÿ���� ���� �� ����.
�Ҹ�ð� 35��

*/


/*

sql
��
-- 1����� ���� ID, ��ü �Ⱓ�� ���� ���� ���ž�
-- 1����� ���� ID, ��ü �Ⱓ�� ���� ���� ���ž�
SELECT C.user_id AS "�� ���̵�", SUM(price) AS "���� ���ž�"
FROM customer C JOIN  orderInfo O JOIN library L
WHERE L.book_id = O.book_id AND C.membership = 1 AND C.user_id = O.buyer_id
GROUP BY C.user_id;

*/