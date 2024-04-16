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
    int t = 1;
    cin >> t;

    auto cmp = [](string x) {
        for(int i = 1; i < (int) x.size(); i++) {
            if(x[i] == x[i-1]) return false;
        }
        return true;
    };

    while(t--) {
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;

        if(cmp(s) and cmp(t)) {
            cout << "YES\n";
            continue;
        }

        bool ans = false;
        for(int i = 1; i < n; i++) {
            string pass = s.substr(i, n-i);
            reverse(all(pass));
            string s1 = s.substr(0, i);
            string s2 = t + pass;

            if(cmp(s1) and cmp(s2)) ans = true;
        }

        for(int i = 1; i < m; i++) {
            string pass = t.substr(i, m-i);
            reverse(all(pass));
            string s1 = t.substr(0, i);
            string s2 = s + pass;

            if(cmp(s1) and cmp(s2)) ans = true;
        }




        cout << (ans ? "YES\n" : "NO\n");
    }
	
    return 0;
}


