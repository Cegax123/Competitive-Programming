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
    vi deg(n, 0);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        deg[u]++; deg[v]++;
    }

    int cnt1 = 0, cnt2 = 0, cntc = 0;

    for(int i = 0; i < n; i++) {
        if(deg[i] == 1) cnt1++;
        else if(deg[i] == 2) cnt2++;
        else if(deg[i] == n-1) cntc++;
    }

    if(cnt1 == 2 and cnt2 == n-2) {
        cout << "bus topology\n";
        return 0;
    }

    if(cnt2 == n) {
        cout << "ring topology\n";
        return 0;
    }

    if(cnt1 == n-1 and cntc == 1) {
        cout << "star topology\n";
        return 0;
    }

    cout << "unknown topology\n";
	
    return 0;
}


