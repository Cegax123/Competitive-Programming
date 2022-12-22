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
        int b[n][m];

        int tot1 = 0;

        int cnt[n];
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> b[i][j];
                tot1 += (b[i][j] == 1);
                cnt[i] += (b[i][j] == 1);
            }
        }

        if(tot1 % n != 0) {
            cout << "-1\n";
            continue;
        }

        vi give;
        vector<set<int> > lft(m);

        int target = tot1 / n;

        for(int i = 0; i < n; i++) {
            if(cnt[i] > target) {
                give.pb(i);
            }
            else if(cnt[i] < target) {
                for(int j = 0; j < m; j++) {
                    if(b[i][j] == 0) lft[j].insert(i);
                }
            }
        }

        //for(int i =0 ; i < n; i++) cout << cnt[i] << " ";
        //cout << endl;

        vector<vi> op;

        for(int x : give) {
            for(int j = 0; j < m; j++) {
                if(cnt[x] == target) break;
                if(b[x][j] == 1) {
                    vi to_remove;
                    bool found = 0;
                    for(int y : lft[j]) {
                        if(cnt[y] == target) {
                            to_remove.pb(y);
                            continue;
                        }
                        cnt[y]++;
                        to_remove.pb(y);
                        found = 1;
                        op.pb({x+1, y+1, j+1});
                        break;
                    }
                    for(int y : to_remove) lft[j].erase(y);
                    if(found) cnt[x]--;
                }
            }
        }

        bool cmp = 1;

        for(int i = 0; i < n; i++) {
            if(cnt[i] != target) cmp = 0;
        }

        if(!cmp) cout << "-1\n";
        else {
            cout << op.size() << "\n";

            for(int i = 0; i < (int) op.size(); i++) {
                for(int j = 0; j < 3; j++) cout << op[i][j] << " ";
                cout << "\n";
            }
        }
    }

	
    return 0;
}


