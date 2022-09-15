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
	int t; cin >> t;
    while(t--) {
        string s; cin >> s;
 
        if(s.size() == 1 or s.back() == 'A') {
            cout << "NO\n";
            continue;
        }
 
        vector<char> a;
 
        for(int i = 0; i < (int) s.size(); i++) {
            if(a.empty()) {
                a.pb(s[i]);
            }
            else if(s[i] == 'A') {
                a.pb(s[i]);
            }
            else {
                if(a.back() == 'A') a.pop_back();
                else a.pb(s[i]);
            }
        }
        
        bool cmp = true;
 
        for(char c : a)
            if(c == 'B') cmp = false;
 
        if(cmp) cout << "YES\n";
        else cout << "NO\n";
 
    }
 
	
    return 0;
}
