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

void solve() {
    int n; cin >> n;
    vector<string> sp(2 * n-2);

    for(int i = 0; i < 2 * n-2; i++) {
        cin >> sp[i];
    }

    sort(all(sp), [](const string& a, const string& b) {
            return a.size() < b.size();
            });

    string x = sp[2 * n - 2 - 2], y = sp[2 * n - 2 - 1];

    //cout << x << " " << y << endl;

    if(x.substr(1, n-2) != y.substr(0, n-2)) swap(x, y);

    string s = x + y.substr(n-2, 1);

    //string s = "a";
    //cout << s << endl;
    //
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s[n-1-i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc; cin >> tc;
    //int tc; tc = 1;

    while(tc--) {
        solve();
    }

	
    return 0;
}


