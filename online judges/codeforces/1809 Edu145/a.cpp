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
        map<char, int> cnt;
        for(char c : s) cnt[c]++;
        vi x;
        for(auto e : cnt) x.pb(e.second);
        sort(all(x));
        if((int) x.size() == 1) {
            cout << -1 << "\n";
        }
        else if((int) x.size() == 2) {
            if(x[0] == 1 and x[1] == 3) cout << 6 << "\n";
            else cout << 4 << "\n";
        }
        else cout << 4 << "\n";
    }

	
    return 0;
}


