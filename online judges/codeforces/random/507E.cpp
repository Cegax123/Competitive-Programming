#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<string> f(int n) {
	if(n == 1) {
		return vector<string>(1, "x");
	}
	vector<string> bef = f(n-1);
	int L = bef.size();
	string spa = string(L, ' ');
	vector<string> ans;

	for(string& line: bef) ans.pb(line+spa+line);
	for(string& line: bef) ans.pb(spa+line+spa);
	for(int i = 0; i < L; i++) ans.pb(ans[i]);

	return ans;
}

int main() {
	int n; cin >> n;

	vector<string> ans = f(n);

	for(string& line: ans) cout << line << "\n";

}