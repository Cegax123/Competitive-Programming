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
        int a[n], d[n];

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> d[i];

        int nxt[n], bef[n];

        for(int i = 0; i < n; i++) nxt[i] = i+1;
        for(int i = n-1; i >= 0; i--) bef[i] = i-1;

        vector<int> poss;
        for(int i = 0; i < n; i++) poss.push_back(i);

        vector<bool> alive(n, 1);

        for(int i = 0; i < n; i++) {
            set<int> newposs;

            vector<int> del;
            int cnt = 0;
            for(int x : poss) {
                assert(alive[x]);
                int damage = (bef[x] >= 0 ? a[bef[x]] : 0) + (nxt[x] < n ? a[nxt[x]] : 0);

                if(d[x] < damage) {
                    alive[x] = 0;
                    del.push_back(x);
                    cnt++;
                }
            }

            for(int x : poss) {
                if(!alive[x] and bef[x] >= 0 and alive[bef[x]]) newposs.insert(bef[x]);
                if(!alive[x] and nxt[x] < n and alive[nxt[x]]) newposs.insert(nxt[x]);
            }

            int ind = 0;
            while(ind < cnt) {
                if(ind+1 >= cnt or bef[del[ind+1]] != del[ind]) {
                    int x = del[ind];

                    if(bef[x] >= 0) nxt[bef[x]] = nxt[x];
                    if(nxt[x] < n) bef[nxt[x]] = bef[x];

                    ind++;
                    continue;
                }

                int r = ind+1;
                while(r < cnt and bef[del[r]] == del[r-1]) {
                    r++;
                }

                r--;

                int L = del[ind], R = del[r];
                if(bef[L] >= 0) nxt[bef[L]] = nxt[R];
                if(nxt[R] < n) bef[nxt[R]] = bef[L];

                ind = r+1;
            }

            poss.clear();
            for(int x : newposs) poss.push_back(x);

            cout << cnt << " ";

            //cout << "====\n";
            //for(int i = 0; i < n; i++) {
                //if(alive[i]) cout << "[" << i << ", " << nxt[i] << "]";
            //}
            //cout << endl;
            //for(int i = 0; i < n; i++) {
                //if(alive[i]) cout << "[" << i << ", " << bef[i] << "]";
            //}
            //cout << "====\n";

        }
        cout << "\n";
    }

	
    return 0;
}


