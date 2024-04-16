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
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        vi pos;
        for(int i = 0; i < n; i++) {
            cnt += s[i] == '1';
            if(s[i] == '1') pos.pb(i);
        }
        if(cnt&1) cout << "-1\n";
        else {
            if(cnt == 2) {
                if(n == 2) cout << "-1\n";
                else if(n == 3) {
                    if(pos[0]+1 == pos[1]) cout << "-1\n";
                    else cout << "1\n";
                }
                else if(n == 4) {
                    if(pos[0]+1 == pos[1]) {
                        if(pos[0] == 1) cout << "3\n";
                        else cout << "2\n";
                    }
                    else {
                        cout << "1\n";
                    }
                }
                else {
                    if(pos[0] + 1 == pos[1]) {
                        cout << "2\n";
                    }
                    else cout << "1\n";
                }
            }
            else cout << cnt/2 << "\n";
        }
    }

	
    return 0;
}


