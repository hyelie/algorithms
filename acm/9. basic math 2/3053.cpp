#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	double n; cin >> n;
	double area = M_PI * n * n;
	cout << fixed;
	cout.precision(10);
	cout << area << '\n';
	cout << 2 * n * n << '\n';
	
	return;
}