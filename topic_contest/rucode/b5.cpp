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

const int maxn = 5e4 + 5;
const int B = 256;

int n;
vi indexes[B];
ll sum[B];
int a[maxn];

void update(int pos, int v) {
    int id = pos / B;

    vi tmp;
    for(int y : indexes[id]) if(y != pos)
        tmp.pb(y);

    a[pos] = v;
    indexes[id].clear();

    bool appended = false;

    for(int y : tmp) {
        if(a[pos] <= a[y] and !appended) {
            indexes[id].pb(pos);
            appended = true;
        }
        indexes[id].pb(y);
    }

    if(!appended) indexes[id].pb(pos);
}

ll query(int l, int r) {

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    int q; cin >> q;
    while(q--) {
        char op; cin >> op;
        if(op == 'U') {
            int pos, v; cin >> pos >> v;

        }
    }
	
    return 0;
}


