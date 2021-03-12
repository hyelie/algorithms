#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	string s; cin >> s;
	vector<bool> oper; // oper[i] : true : +, false : -
	vector<int> nums;
	string temps;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			oper.push_back(false);
		}
		else if (s[i] == '+') {
			oper.push_back(true);
		}
		else {
			temps = "";
			while (!(s[i] == '-' || s[i] == '+') && i<s.length()) {
				temps.push_back(s[i]);
				i++;
			}
			i--;
			nums.push_back(stoi(temps));
		}
	}

	int result = nums[0];
	int i = 1;
	while (i < nums.size()) {
		if (!oper[i - 1]) {
			result -= nums[i];
			i++;
			while (i < nums.size() && oper[i - 1]) {
				result -= nums[i];
				i++;
			}
		}
		else {
			result += nums[i];
			i++;
		}
	}
	cout << result;


	return;
}

// -뒤에 (치고, +앞에 )치면 됨.