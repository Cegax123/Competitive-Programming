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

        const int E = 26;
        vi pos[E][E];

        for(int i = 0; i < n-1; i++) {
            pos[s[i]-'a'][s[i+1]-'a'].pb(i);
        }

        bool cmp = 0;
        for(int i = 0; i < E; i++) {
            for(int j = 0; j < E; j++) {
                if(pos[i][j].size() <= 1) continue;
                int a = pos[i][j][0], b = pos[i][j].back();
                if(a + 2 <= b) cmp = 1;
            }
        }

        cout << (cmp ? "YES" : "NO") << "\n";
    }

	
    return 0;
}


