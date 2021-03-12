#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

void setIsPrime(vector<bool> &dp, int maxnum) {
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
    vector<bool> dp(1001, true);
    setIsPrime(dp, 1001);

    int n;
    cin >> n;
    cout << isPrime(dp, n) << endl;

    return;
}