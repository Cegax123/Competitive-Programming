#include<bits/stdc++.h>
using namespace::std;

const int N = 1000000 + 5;

int n;
string article;
vector<string> lines;
map<string, int> id;
map<int, int> frec;
map<int, string> sid;
vector<string> values;
set<int> lengths;
set<int> G[N];
int memo[N];
bool vis[N];
int in[N];

string abs(string s) {
	for(auto &c : s) {
		if(c == ' ') continue;
		if(!isalpha(c)) return "";
		if(c > 'Z') c += 'A' - 'a';
	}
	return s;
}

int get_id(string s) {
	if(id.count(abs(s))) return id[abs(s)];
	sid[n] = s;
	id[abs(s)] = n++;
	return id[abs(s)];
}

void read_lines() {
	string s;
	while(getline(cin, s)) {
		lines.emplace_back(s);
	}

    vector<string> ss;
    while(lines.back()[0] != '<') {
        ss.push_back(lines.back());
        lines.pop_back();
    }

    reverse(ss.begin(), ss.end());

	for(string& x : ss) {
		string y;
		for(char c : x) {
			if(c == ',' or c == '.' or c == '?' or c == '!') continue;
			y += c;
		}
		x = y;
	}

	article += ss[0];
	for(int i = 1; i < (int) ss.size(); i++) {
		article += "\n" + ss[i];
	}
}

void add_edge(int u, int v) {
	G[u].emplace(v);
}

void update_elements(vector<pair<string, string>> &elements) {
	string T;
	vector<string> UF, BT, NT;
	for(auto e : elements) {
		if(e.first == "T") T = e.second;
		else if(e.first == "UF") UF.emplace_back(e.second);
		else if(e.first == "BT") BT.emplace_back(e.second);
		else NT.emplace_back(e.second);
	}
	int m = -1;
	for(auto e : UF) {
		if(id.count(abs(e))) {
			m = id[abs(e)];
			break;
		}
	}
	if(~m) id[abs(T)] = m;
	else m = get_id(T);
	for(auto e : UF) {
		id[abs(e)] = m;
	}
	for(auto e : BT) {
		int from = get_id(e);
		int to = get_id(T);
		add_edge(from, to);
	}
	for(auto e : NT) {
		int to = get_id(e);
		int from = get_id(T);
		add_edge(from, to);
	}
}

void update_tokens(string s) {
	int at = 0;
	vector<pair<string, string>> elements;
	while(at < s.size()) {
		while(at < s.size() and s[at] != '<') at++;
		bool closes = false;
		if(at + 1 < s.size() and s[at + 1] == '/') {
			closes = true;
			at += 1;
		}
		string tag_name = "";
		at += 1;
		while(at < s.size() and s[at] != '>') {
			tag_name.push_back(s[at]);
			at += 1;
		}
		at += 1;
		if(tag_name == "Thesaurus") continue;
		if(closes) {
			update_elements(elements);
			elements.clear();
			continue;
		}
		if(tag_name == "TermInfo") continue;
		string content = "";
		while(at < s.size() and s[at] != '<') {
			content.push_back(s[at]);
			at += 1;
		}
		while(at < s.size() and s[at] != '>') at += 1;
		elements.emplace_back(tag_name, content);
		at += 1;
	}
}

void parse_xml() {
	string total = "";
	for(auto s : lines) total += s;
	update_tokens(total);
	for(auto e : id) lengths.emplace(e.first.length());
}

int DP(int u) {
	if(vis[u]) return memo[u];
	vis[u] = true;
	int sum = frec[u];
	for(int v : G[u]) {
		sum += DP(v);
	}
	return memo[u] = sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	read_lines();
	lines.pop_back();
	parse_xml();
	for(int i = 0; i < article.size(); i++) {
		for(auto l : lengths) {
			if(i + l - 1 >= article.size()) break;
			string cur = abs(article.substr(i, l));
			if(cur.empty()) continue;
			if(id.count(cur)) {
				frec[id[cur]] += 1;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int v : G[i]) {
			in[v] = 1;
		}
	}
	vector<pair<int, string>> res;
	for(int i = 0; i < n; i++) {
		if(in[i]) continue;
		res.emplace_back(DP(i), sid[i]);
	}
	sort(res.begin(), res.end(), [&] (pair<int, string> a, pair<int, string> b){
		if(a.first == a.first) return a.second < b.second;
		return a.first > b.first;
	});
	for(auto e : res) {
		cout << e.second << " = " << e.first << endl;
	}
	return 0;
}

