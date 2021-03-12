#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<long long, long long>pll;

void solve();
// n!¿¡¼­ 2ÀÇ ½Â¼ö, 5ÀÇ ½Â¼ö °¡Á®¿È
pll decompose(int i) {
	long long maxtwo = 2, twocnt = 0;
	while (i / maxtwo != 0) {
		twocnt += i / maxtwo;
		maxtwo *= 2;
	}

	long long maxfive = 5, fivecnt = 0;
	while (i / maxfive != 0) {
		fivecnt += i / maxfive;
		maxfive *= 5;
	}

	return { twocnt, fivecnt };
}
/*
2 4 6 8 10 12 14 16 18 20 22 24
4 8 12 16 20 24
8 16 24
16

*/

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n, m; cin >> n >> m;
	pll nd = decompose(n), md = decompose(m), nsubmd = decompose(n - m);
	long long two = nd.first - md.first - nsubmd.first;
	long long  five = nd.second - md.second - nsubmd.second;
	cout << min(two, five);

	return;
}

/*

nCr = n! / (r! * (n-r)!)

*/