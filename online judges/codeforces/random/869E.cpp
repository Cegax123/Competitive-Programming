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

const int maxq = 1e5 + 5;
const int maxn = 2500 + 5;
const int B = 375;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}

int r[maxq];
int c[maxn][maxn];
int id[maxn][maxn];

void update(int x, int y, int val) {
    for(; x < maxn; x += x & -x)
        for(int j = y; j < maxn; j += j & -j)
            c[x][j] ^= val;
}

int get(int x, int y) {
    int ans = 0;

    for(; x; x -= x & -x)
        for(int j = y; j; j -= j & -j)
            ans ^= c[x][j];

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i < maxq; i++)
        r[i] = random(1, 1e9);

    auto insert = [&](int a, int b, int c, int d, int val) {
        update(a, b, val);
        update(c+1, b, val);
        update(a, d+1, val);
        update(c+1, d+1, val);
    };

    int n, m, q; cin >> n >> m >> q;
    
    insert(1, 1, n, m, r[0]);

    int ind = 1;

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            id[a][b] = ind++;
            insert(a, b, c, d, r[id[a][b]]);
        }
        else if(op == 2) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            insert(a, b, c, d, r[id[a][b]]);
        }
        else {
            int a, b, c, d; cin >> a >> b >> c >> d;
            int h1 = get(a, b), h2 = get(c, d);
            cout << (h1 == h2 ? "Yes\n" : "No\n");
        }
    }

    return 0;
}


