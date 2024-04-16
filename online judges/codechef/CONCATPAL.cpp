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
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;
        if(s.size() > t.size()) swap(s, t);
        n = s.size();
        m = t.size();

        vi cnts(26, 0), cntt(26, 0);

        for(char c : s) cnts[c-'a']++;
        for(char c : t) cntt[c-'a']++;

        bool cmp = 1;
        int cntodd = 0;
        for(int i = 0; i < 26; i++) {
            cntt[i] -= cnts[i];

            if(cntt[i] < 0) cmp = 0;
            if(cntt[i]&1) cntodd++;
        }

        if(cmp == 0) {
            cout << "NO\n";
            continue;
        }

        if((m-n)&1) {
            if(cntodd == 1) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if(cntodd == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }

	
    return 0;
}


