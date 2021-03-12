#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
bool isPrime[4000001];
// isPrime[i] : true : 숫자 i는 소수

void solve();
void setIsPrime(int maxnum) {
    // 소수이면 true, 아니면 false
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= maxnum; i++) {
        if (isPrime[i] == false) {
            continue;
        }
        else {
            isPrime[i] = true;
            for (int j = 2 * i; j <= maxnum; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
    int N; cin >> N;
    for (int i = 0; i <= N; i++) {
        isPrime[i] = true;
    }
    setIsPrime(N);
    vector<int> p;
    for (int i = 1; i <= N; i++) {
        if (isPrime[i]) p.push_back(i);
    }

    int sum = 0, l = 0, r = 0, cnt = 0;

    while (l <= r && r <= p.size()) {
        if (sum > N) {
            sum -= p[l];
            l++;
        }
        else if (sum == N) {
            cnt++;
            sum -= p[l];
            l++;
        }
        else {  // sum < N
            if (r == p.size()) break;
            sum += p[r];
            r++;
        }
    }
    cout << cnt;


	return;
}