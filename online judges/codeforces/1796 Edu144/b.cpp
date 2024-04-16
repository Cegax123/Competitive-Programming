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
        string s, u; cin >> s >> u;
        int n = s.size(), k = u.size();
            
        if(s[0] == u[0]) {
            cout << "YES\n";
            cout << s[0] << "*\n";
        }
        else if(s.back() == u.back()) {
            cout << "YES\n";
            cout << "*" << s.back() << "\n";
        }
        else {
            char x='#', y;
            for(char c = 'a'; c <= 'z'; c++) {
                for(char d = 'a'; d <= 'z'; d++) {
                    bool cmp = 0;
                    for(int i = 0; i+1 < n; i++) {
                        if(s[i] == c and s[i+1] == d) cmp = 1;
                    }

                    if(!cmp) continue;
                    cmp = 0;
                    for(int i = 0; i+1 < k; i++) {
                        if(u[i] == c and u[i+1] == d) cmp = 1;
                    }

                    if(cmp) {
                        x = c;
                        y = d;
                    }
                }
            }

            if(x != '#') {
                cout << "YES\n";
                cout << "*" << x << y << "*\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

	
    return 0;
}


