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
        vector<int> pos;
        for(int i = 0; i < n; i++) {
            char c = s[i];
            cnt += c == '1';
            if(c == '1') pos.push_back(i);
        }

        if(cnt % 2 == 0) {
            if(cnt == 2) {
                if(pos[0]+1 == pos[1]) cout << "NO\n";
                else cout << "YES\n";
            }
            else cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

	
    return 0;
}


