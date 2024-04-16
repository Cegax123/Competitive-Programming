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

const int maxn = 1e5 + 5;
const int SQRT = 500;
const int BSZ = 1200;

int n, m;
vi indexes[SQRT];
int lazy[SQRT];
int a[maxn];

bool find_block(int block, int x) {
    x -= lazy[block];
    
    int l = 0, r = indexes[block].size()-1;

    while(l < r) {
        int m = (l+r) >> 1;
        if(a[indexes[block][m]] >= x) r = m;
        else l = m+1;
    }

    return a[indexes[block][l]] == x;
}

bool find(int l, int r, int x) {
    int ind = l;

    while(ind <= r and ind % BSZ) {
        if(a[ind] + lazy[ind / BSZ] == x) return true;
        ind++;
    }

    while(ind + BSZ - 1 <= r) {
        if(find_block(ind/BSZ, x)) return true;
        ind += BSZ;
    }

    while(ind <= r) {
        if(a[ind] + lazy[ind / BSZ] == x) return true;
        ind++;
    }

    return false;
}

void update_block(int l, int r, int x) {
    int block = l / BSZ;

    vi changed, no_changed;

    for(int i : indexes[block]) {
        if(i >= l and i <= r) {
            changed.emplace_back(i);
            a[i] += x;
        }
        else {
            no_changed.emplace_back(i);
        }
    }
    
    merge(all(changed), all(no_changed), indexes[block].begin(), [&](int i, int j) {
            return a[i] < a[j];
            });
}

void update(int l, int r, int x) {
    int ind = l;

    while(ind <= r and ind % BSZ) ind++;

    update_block(l, ind-1, x);

    while(ind + BSZ - 1 <= r) {
        lazy[ind / BSZ] += x;
        ind += BSZ;
    }

    update_block(ind, r, x);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++)
        indexes[i/BSZ].pb(i);

    for(int i = 0; i < SQRT; i++) {
        sort(all(indexes[i]), [&](int i, int j) {
                return a[i] < a[j];
                });
    }
    
    while(m--) {
        char op; cin >> op;
        int l, r, x; cin >> l >> r >> x;
        l--; r--;

        if(op == '?') {
            cout << (find(l, r, x) ? "YES\n" : "NO\n");
        }
        else {
            update(l, r, x);
        }
    }
	
    return 0;
}


