#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
	int N; cin >> N;
	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int cur = 1;
	vector<bool> op;		// op[i] == true : +, false : -
	stack<int> s;
	int i = 0;
	int isOK = true;

	// cur : �������� �� ��
	/*while (cur <= input[i]) {
		s.push(cur++);
		op.push_back(true);
	}*/

	// 3���� ����. cur, input[i], s.top()
	for (int i = 0; i < N;) {
		if (s.empty()) {
			if (cur <= input[i]) {
				while (cur <= input[i]) {
					s.push(cur++);
					op.push_back(true);
				}
			}
			// push�� �� ���� ���
			else {
				isOK = false;
				break;
			}
		}

		if (s.top() == input[i]) {
			op.push_back(false);
			s.pop();
			i++;
		}
		else if (s.top() < input[i]) {
			// push�� �� �ִ� ��츸 push
			if (cur <= input[i]) {
				while (cur <= input[i]) {
					s.push(cur++);
					op.push_back(true);
				}
			}
			// push�� �� ���� ���
			else {
				isOK = false;
				break;
			}
		}
		else { // s.top() > input[i]
			op.push_back(false);
			s.pop();
			// pop.
		}
	}


	if (!isOK) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < op.size(); i++) {
			if (op[i]) cout << "+\n";
			else cout << "-\n";
		}
	}
	return;
}