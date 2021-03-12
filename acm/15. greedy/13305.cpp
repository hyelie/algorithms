#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	vector<int> len(N - 1), price(N);
	for (int i = 0; i < N-1; i++) {
		cin >> len[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	long long curprice = price[0];
	long long pricesum = 0;
	for (int i = 1; i < N; i++) {
		if (curprice >= price[i]) {
			pricesum += curprice * len[i - 1];
			curprice = price[i];
		}
		else {
			long long lensum = len[i - 1];

			while (i < N && curprice < price[i]) {
				i++;
				lensum += len[i - 1];
			}
			pricesum += lensum * curprice;
			curprice = price[i];
		}
	}

	cout << pricesum;
	

	return;
}

// �� ���� �⸧���� > �������� �⸧���� -> �������ñ��� �������� �⸧�� ����
// �� ���� �⸧���� < �������� �⸧���� -> �� ���� �⸧���ݺ��� �� �� �����Ҷ����� �� ���ؼ� �⸧ ����
// EZ