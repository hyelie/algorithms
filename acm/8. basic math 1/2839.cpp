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
	int kg;
	cin >> kg;

	int five = kg / 5, three = 0;

	while (five >= 0) {
		if ((kg - five * 5) % 3 == 0) {
			three = (kg - five * 5) / 3;
			break;
		}
		else {
			three++;
			five--;
		}
	}
	
	if (kg != 3*three + 5*five) cout << -1;
	else cout << five + three;


	return;
}

// 3a + 5b = kg가 되게 a와 b를 만들어야 한다.
// 