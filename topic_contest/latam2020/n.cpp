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

int conv(string& s) {
    int ans = 0;

    for(int i = 1; i < (int) s.size(); i++) {
        if(s[i] == '.') continue;
        ans = ans * 10 + s[i]-'0';
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    int curr = conv(s);

    for(int i = 0; i < n; i++) {
        cin >> s;
        curr += conv(s);

        if(curr%100) ans++;
    }
	
    cout << ans << "\n";
	
	return 0;
}

