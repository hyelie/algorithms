#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve();

int main(void) {
	solve();
	return 0;
}

bool isComplete(string s) {
    vector<bool> check(s.length(), false);
    for (int i = 0; i < s.length()-1; i++) {
        if (check[i]) continue;
        for (int j = i; j < s.length(); j++) {
            if (s[j] == toupper(s[i]) || s[j] == tolower(s[i])) {
                check[i] = check[j] = true;
            }
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (!check[i]) return false;
    }
    if (s.length() == 1) return false;
    return true;
}

void solve() {
	cout << "hello, world!" << endl;
    string s;
    cin >> s;

    int slen = s.length();
    string longest_str = "";


    for (int i = 0; i < slen; i++) {
        string temp; temp.push_back(s[i]);
        for (int j = i + 1; j < slen; j++) {
            for (int k = 0; k < temp.length(); k++) {
                if (temp[k] == toupper(s[j]) || temp[k] == tolower(s[j]) || isComplete(temp)) {
                    temp.push_back(s[j]);
                    break;
                }
            }
            if (temp.length() == 1) {
                temp = s[j];
            }
        }
        if (temp.length() > longest_str.length()) {
            longest_str = temp;
        }
    }

    if (longest_str.length() == 1) longest_str= "";

    else if (!isComplete(longest_str)) {
        longest_str = longest_str.substr(0, longest_str.length() - 1);
    }

    cout << "그결과는 : "<<longest_str << endl;

	return;
}

