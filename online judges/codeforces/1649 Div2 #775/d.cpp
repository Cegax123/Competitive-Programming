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
        ll n, c; cin >> n >> c;
        vi cnt(c+1, 0);

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }

        if(cnt[1] == 0) {
            cout << "No\n";
            continue;
        }

        vi pcnt(c+1, 0);

        for(int i = 1; i <= c; i++)
            pcnt[i] = pcnt[i-1] + cnt[i];

        bool cmp = 1;

        for(int i = 2; i <= c; i++) {
            if(cnt[i]) continue;
            for(int j = 1; j * 1ll * i <= c; j++) {
                if(cnt[j] == 0) continue;
                int L = j * i, R = min(c,  j * 1ll * i + j - 1);
                if(pcnt[R] - pcnt[L-1]) {
                    cmp = 0;
                }
            }
        }
        cout << (cmp ? "Yes\n" : "No\n");
    }

	
    return 0;
}


