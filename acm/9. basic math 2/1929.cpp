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
    

    int small, big;
    cin >> small >> big;

    vector<bool> dp(big + 1, true);
    setIsPrime(dp, big + 1);


    for (int i = small; i <= big; i++) {
        if (isPrime(dp, i)) cout << i << '\n';
    }

    return;
}