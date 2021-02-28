#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void solve();
void mysearch(int n, string prevskill, vector<string> link, vector<vector<string>> &v, vector<string> &lists) {
	// 연계 불가능하면 종료
	bool isContinue = false;	// false면 불가능.
	vector<string> nextskill;

	for (int i = 0; i < n; i++) {
		if (v[i][0] == prevskill) {
			nextskill.push_back(v[i][1]);
			isContinue = true;
		}
		else continue;
	}

	// 연계 더 가능할때
	if (isContinue == true) {
		int next_skill_num = nextskill.size();
		link.push_back(prevskill);
		for (int i = 0; i < next_skill_num; i++) {
			mysearch(n, nextskill[i], link, v, lists);
		}
		
	}
	// 연계 불가능. 여기까지
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




	
	vector<string> lists;	// 정답 배열

	// 단독 스킬만 찾아서 해야함. 단독 스킬 : v[i][0]에만 있고 v[i][1]에는 없는 것.
	for (auto siter = sset.begin(); siter != sset.end(); siter++) {
		vector<string> link;
		mysearch(n, *siter, link, v, lists);
	}

	// 정답
	for (int i = 0; i < lists.size(); i++) {
		cout << lists[i] << '\n';
	}
	

	return;
}

// backtrack
// 무한 연계 없으니까 검사문 안돌려도될듯