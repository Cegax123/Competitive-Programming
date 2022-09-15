#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s; cin >> s;
	int cnt[2] = {0, 0};

	for(int i = 0; i < (int) s.size(); i++) {
		if(s[i] == '4') cnt[0]++;
		if(s[i] == '7') cnt[1]++;
	}

	if(cnt[0] == cnt[1] and cnt[0] == 0) {
		cout << "-1\n";
	}
	else {
		if(cnt[0] >= cnt[1]) cout << "4\n";
		else cout << "7\n";
	}

	return 0;
}
