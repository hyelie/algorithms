#include <string>
#include <vector>
#include <iostream>

using namespace std;

void show(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }cout << endl;
    }
}

vector<int> solution(int n) {
    vector<vector<int>> tri(n, vector<int>(n, 0));

    int i = 0, j = 0;

    int num = 1;
    int totalnum = n * (n + 1) / 2;
    // n(n+1)/2

    int mode = 0;
    // mode=0 : 아래 : i++, j그대로
    // mode=1 : 오른쪽 : i그대로, j++
    // mode=2 : 좌상단 : i--, j--
    int len = n;

    while (num != totalnum+1) {
        int templen = len;
        len--;
        switch (mode) {
        case 0:
            while (templen--) {
                tri[i][j] = num;
                num++;
                i++;
                mode = 1;
            }
            i--; j++;
            cout << "mode0" << endl;
            show(tri);
            cout << endl;
            break;
        case 1:
            while (templen--) {
                tri[i][j] = num;
                num++;
                j++;
                mode = 2;
            }
            j--; j--; i--;
            cout << "mode1" << endl;
            show(tri);
            cout << endl;
            break;
        case 2:
            while (templen--) {
                tri[i][j] = num;
                num++;
                i--; j--;
                mode = 0;
            }
            i++; j++; i++;
            cout << "mode2" << endl;
            show(tri);
            cout << endl;
            break;
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) break;
            answer.push_back(tri[i][j]);
        }
    }



    return answer;
}

int main() {
    int n;
    cin >> n;
    solution(n);
    return 0;
}