#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIsPrime(vector<bool>& dp, int maxnum) {
    // �Ҽ��̸� true, �ƴϸ� false
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
    vector<bool> dp(10001, true);
    setIsPrime(dp, 10001);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = n / 2; i >= 2; i--) {
            if (isPrime(dp, i) && isPrime(dp, n - i)) {
                cout << min(i, n - i) << " " << max(i, n - i) << '\n';
                break;
            }
        }
    }

    return;
}