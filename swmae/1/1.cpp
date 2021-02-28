#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void solve();
void mysearch(int n, string prevskill, vector<string> link, vector<vector<string>> &v, vector<string> &lists) {
	// ���� �Ұ����ϸ� ����
	bool isContinue = false;	// false�� �Ұ���.
	vector<string> nextskill;

	for (int i = 0; i < n; i++) {
		if (v[i][0] == prevskill) {
			nextskill.push_back(v[i][1]);
			isContinue = true;
		}
		else continue;
	}

	// ���� �� �����Ҷ�
	if (isContinue == true) {
		int next_skill_num = nextskill.size();
		link.push_back(prevskill);
		for (int i = 0; i < next_skill_num; i++) {
			mysearch(n, nextskill[i], link, v, lists);
		}
		
	}
	// ���� �Ұ���. �������
	else {
		link.push_back(prevskill);
		int linksize = link.size();
		if (linksize == 1) return;
		else {
			string temp = link[0];
			for (int i = 1; i < linksize; i++) {
				temp.append(" ");
				temp.append(link[i]);
			}
			lists.push_back(temp);
		}
		return;
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	string s;
	getline(cin, s);
	vector<string> skills;
	int slen = s.length();
	string temp = "";
	for (int i = 0; i < slen; i++) {
		if (s[i] == ' ') {
			skills.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(s[i]);
		}
	}
	skills.push_back(temp);

	

	int n; cin >> n;
	vector<vector<string>> v(n, vector<string>(2));
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	set<string> sset;
	for (int i = 0; i < n; i++) {
		sset.insert(v[i][0]);
	}
	for (int i = 0; i < n; i++) {
		sset.erase(v[i][1]);
	}




	
	vector<string> lists;	// ���� �迭

	// �ܵ� ��ų�� ã�Ƽ� �ؾ���. �ܵ� ��ų : v[i][0]���� �ְ� v[i][1]���� ���� ��.
	for (auto siter = sset.begin(); siter != sset.end(); siter++) {
		vector<string> link;
		mysearch(n, *siter, link, v, lists);
	}

	// ����
	for (int i = 0; i < lists.size(); i++) {
		cout << lists[i] << '\n';
	}
	

	return;
}

// backtrack
// ���� ���� �����ϱ� �˻繮 �ȵ������ɵ�