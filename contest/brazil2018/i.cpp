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
    int n, m; cin >> n >> m;
    int cnt = 0;

    vi on(m+1, 0);

    int x; cin >> x;

    for(int i = 0; i < x; i++) {
        int p; cin >> p;
        on[p] = 1;
        cnt++;
    }

    vector<vi> bulb(n);

    for(int i = 0; i < n; i++) {
        int y; cin >> y;
        for(int j = 0; j < y; j++) {
            int p; cin >> p;
            bulb[i].pb(p);
        }
    }

    bool cmp = 0;

    for(int i = 0; i <= 2 * n; i++) {
        int idx = i % n;
        for(int j = 0; j < (int) bulb[idx].size(); j++) {
            if(on[bulb[idx][j]]) cnt--;
            else cnt++;

            on[bulb[idx][j]] ^= 1;
        }

        if(cnt == 0) {
            cout << i+1 << "\n";
            cmp = 1;
            break;
        }
    }

    if(!cmp) {
        cout << -1 << "\n";
    }
	
    return 0;
}


