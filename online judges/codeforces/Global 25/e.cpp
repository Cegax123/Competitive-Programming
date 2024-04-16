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
        int n = s.size();
        
        bool cmp = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] != s[n-1-i]) cmp = 0;
        }

        if(!cmp) {
            cout << "YES\n";
            cout << 1 << "\n";
            cout << s << "\n";
            continue;
        }
        
        char c = s[0];

        int pos = -1;
        for(int i = 0; i+1 < n; i++) {
            if(s[i] != c and s[i+1] != c) {
                pos = i;
            }
        }

        if(pos != -1) {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << s.substr(0, pos+1) << " " << s.substr(pos+1, n-(pos+1)) << "\n";
            continue;
        }
        
        int L = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == c) L++;
            else break;
        }

        if(L == n or 2 * L + 1 == n) {
            cout << "NO\n";
            continue;
        }

        int ind = 0;
        vector<pair<int, int>> cnt;

        while(ind < n) {
            if(s[ind] != c) {
                ind++;
                continue;
            }

            int curr = 0;
            while(ind < n and s[ind] == c) {
                ind++;
                curr++;
            }
            cnt.push_back({ind-1, curr});
        }

        pos = -1;
        for(int i = 1; i + 1 < (int) cnt.size(); i++) {
            if(cnt[i].second != L) {
                pos = cnt[i].first;
            }
            else if(cnt[i].second - 1 != L and L != 1) {
                pos = cnt[i].first - 1;
            }
        }

        if(pos != -1) {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << s.substr(0, pos+1) << " " << s.substr(pos+1, n-(pos+1)) << "\n";
            continue;
        }

        for(int i = 4; i < n; i += 2) {
            if(s[i-1] != s[1]) {
                pos = i;
                break;
            }
        }

        if(pos != -1) {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << s.substr(0, pos+1) << " " << s.substr(pos+1, n-(pos+1)) << "\n";
            continue;
        }

        else cout << "NO\n";
    }

	
    return 0;
}


