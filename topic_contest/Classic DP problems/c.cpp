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

const int maxn = 105;

int b[maxn][maxn];
int c[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> b[i][j];

    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            c[i][j] = c[i-1][j] + b[i][j];
        }
    }

    int global = -1e9;

    for(int L = 1; L <= n; L++) {
        for(int R = L; R <= n; R++) {
            int local = c[R][1]-c[L-1][1];
            global = max(global, local);

            for(int j = 2; j <= n; j++) {
                local = max(local + c[R][j] - c[L-1][j], c[R][j] - c[L-1][j]);
                global = max(local, global);
            }
        }
    }

    cout << global << "\n";
	
    return 0;
}


