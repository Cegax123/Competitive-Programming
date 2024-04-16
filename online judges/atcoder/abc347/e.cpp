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
    int n, q; cin >> n >> q;
    int x[q];
    vector<int> cnt(n+1, 0);
    vector<int>pos [n+1];
    int curr = 0;

    ll c[q];

    for(int i = 0; i < q; i++) {
        cin >> x[i];
        pos[x[i]].push_back(i);
        if(cnt[x[i]] == 0) {
            cnt[x[i]]++;
            curr++;
        }
        else {
            cnt[x[i]]--;
            curr--;
        }
        c[i] = curr;
        if(i) c[i] += c[i-1];

    }

    vector<ll> ans(n+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < (int) pos[i].size(); j++) {
            if(j % 2 == 0) {
                if(pos[i][j] == pos[i].back()) {
                    ans[i] += c[q-1] - (pos[i][j] == 0 ? 0 : c[pos[i][j]-1]);
                }
                else {
                    ans[i] += c[pos[i][j+1]-1] - (pos[i][j] == 0 ? 0 : c[pos[i][j]-1]);
                }
            }
        }
        cout << ans[i] << " ";
    }
	
    return 0;
}


