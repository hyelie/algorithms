#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIsPrime(vector<bool>& dp, int maxnum) {
    // 소수이면 true, 아니면 false
    dp[0] = dp[1] = false;
    for (int i = 2; i < maxnum; i++) {
        if (dp[i] == false) {
            continue;
        }
        else {
            dp[i] = true;
            for (int j = 2 * i; j < maxnum; j += i) {
                dp[j] = false;
            }
        }
    }
}

bool isPrime(vector<bool>& dp, int n) {
    if (dp[n] == true) return true;
    else return false;
}


void solve();

int main(void) {
    std::ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

void solve() {


    vector<bool> dp(123456 * 2 + 1, true);
    setIsPrime(dp, 123456 * 2 + 1);

	int n;
	cin >> n;

    while (n != 0) {
        int num = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (isPrime(dp, i)) num++;
        }
        cout << num << '\n';
        cin >> n;
    }

}