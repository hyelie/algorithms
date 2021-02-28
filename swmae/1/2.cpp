#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
    std::ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

void solve() {
    int p;  // pc 대수
    int n;  // 예약 손님 수
    int h;  // 운영 시간
    cin >> p >> n >> h;
    vector<vector<int, int>> pcinfo(p, vector<int>(n));
    for (int i = 0; i < p; i++) {
        for(int j = 0; j<)
    }
    for (int i = 0; i < n; i++) {
        cin >> pcinfo[i].first >> pcinfo[i].second;
    }
    sort(pcinfo.begin(), pcinfo.end());

    for (int i = 0; i < n; i++) {
        cout << pcinfo[i].first << pcinfo[i].second << endl;
    }

    vector<vector<int>> sum(p, vector<int>(n));
    for (int i = 0; i < p; i++) {
        sum[i][0] = pcinfo
    }


    return;
}

// greedy? sort?
// 10
// 22222 7 못 풂.