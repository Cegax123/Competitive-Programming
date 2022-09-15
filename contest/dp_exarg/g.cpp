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

const int maxn = 505;
const int maxk = 105;

ll P[maxn], W[maxn];
int k[maxn];
ll p[maxn][maxk], w[maxn][maxk];

int main() {
    ifstream in("student.in");
    ofstream out("student.out");

	//ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);

	int n; in >> n;

    for(int i = 0; i < n; i++)
        in >> k[i];

    for(int i = 0; i < n; i++) {
        P[i] = 0;
        for(int j = 0; j < k[i]; j++) {
            in >> p[i][j];
            P[i] += p[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        W[i] = 0;
        for(int j = 0; j < k[i]; j++) {
            in >> w[i][j];
            W[i] += w[i][j];
        }
    }

    int ord_blocks[n]; 
    ii ord_tasks[n][maxk];

    iota(ord_blocks, ord_blocks + n, 0);
    
    int ind = 0;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < k[i]; j++) 
            ord_tasks[i][j] = {j, ind++};

    sort(ord_blocks, ord_blocks + n, [&] (const int& a, const int& b) {
            return P[a] * W[b] < P[b] * W[a];
            });

    for(int i = 0; i < n; i++) {
        sort(ord_tasks[i], ord_tasks[i] + k[i], [&] (const ii& a, const ii& b) {
                return p[i][a.first] * w[i][b.first] < p[i][b.first] * w[i][a.first];
                });
    }

    ll ans = 0;
    ll glb = 0;

    for(int i = 0; i < n; i++) {
        int x = ord_blocks[i];

        ans += W[x] * glb;
        glb += P[x];

        ll curr = 0;

        for(int j = 0; j < k[x]; j++) {
            int y = ord_tasks[x][j].first;

            curr += p[x][y];
            ans += curr * w[x][y];
        }
    }

    out << ans << "\n";

    for(int i = 0; i < n; i++) {
        int x = ord_blocks[i];

        for(int j = 0; j < k[x]; j++) {
            out << ord_tasks[x][j].second + 1 << " ";
        }
    }

    return 0;
}


