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
    int sum, limit; cin >> sum >> limit;

    const int L = 20;
    int pos[1 << L];

    for(int i = 0; i < L; i++)
        pos[1 << i] = i;
    
    vi a[L];

    for(int i = 1; i <= limit; i++) 
        a[pos[i&(-i)]].pb(i);

    vi ans;
    vi cnt(L, 0);
    for(int i = L-1; i >= 0; i--) {
        cnt[i] += ((sum >> i)&1);

        for(int j = 0; cnt[i] > 0 and j < (int) a[i].size(); j++, cnt[i]--) {
            ans.pb(a[i][j]);
        }

        if(i) cnt[i-1] += 2 * cnt[i];
    }

    if(cnt[0] == 0) {
        cout << ans.size() << "\n";
        for(int x : ans)
            cout << x << " ";
    }
    else cout << -1 << "\n";
	
    return 0;
}


