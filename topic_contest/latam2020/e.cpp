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

const int maxn = 1e5+5;
const int LOGN = 20;

int n;
int h[maxn];
int ST[maxn][LOGN];

int f(int a, int b) {return max(a,b);}

void STBuild() {
    for(int i = 1; i <= n; i++) 
        ST[i][0] = h[i]; // Cuidado con los índices. Si 'a' es 0-indexado, entonces: ST[i][0] = a[i-1];

    for(int k = 1; (1 << k) <= n; k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= n; i++)
            ST[i][k] = f(ST[i][k-1], ST[i+dis][k-1]);
    }
}

int STQuery(int L, int R) {
    // Cuidado con los índices: Las querys consideran que el array a consultar está 1-indexado.
    // Por lo que, si tu array es 0-indexado, y quieres consultar para [0, n-1] -> L = 1, R = n
    // Es decir, aumentamos en uno a L y R: L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(ST[L][k], ST[R-dis+1][k]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> h[i];

    STBuild();

    vi ans(n+1, 0);

    for(int i = 1; i <= n; i++) {
        int l = 0, r = n-i;

        while(l < r) {
            int m = (l+r+1) >> 1;
            int R = min(n, i + 2 * m);
            if(STQuery(i, R) == h[i]) l = m;
            else r = m-1;
        }

        if(i+1 <= n) ans[i+1]++;
        if(i+l+1 <= n) ans[i+l+1]--;

        l = 0; r = i-1;

        while(l < r) {
            int m = (l+r+1) >> 1;
            int L = max(1, i - 2 * m);
            if(STQuery(L, i) == h[i]) l = m;
            else r = m-1;
        }

        ans[i]--;
        if(i-l >= 1) ans[i-l]++;
    }

    for(int i = 2; i <= n; i++)
        ans[i] += ans[i-1];

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
	
	return 0;
}

