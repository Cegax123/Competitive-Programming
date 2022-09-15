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

const int maxn = 2e5+100;
const int LOGN = 20;

int n;
ll a[maxn], pL[maxn], pR[maxn];

ll ST[maxn][LOGN];
ll sumL[maxn][LOGN], sumR[maxn][LOGN];

ll f(ll a, ll b) {return max(a,b);}

void STBuild() {
    for(int i = 1; i <= n+2; i++) {
        ST[i][0] = a[i-1]; // Cuidado con los índices. Si 'a' es 0-indexado, entonces: ST[i][0] = a[i-1];
        sumL[i][0] = pL[i-1];
        sumR[i][0] = pR[i-1];
    }

    for(int k = 1; (1 << k) <= n+1; k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= n+2; i++) {
            ST[i][k] = f(ST[i][k-1], ST[i+dis][k-1]);
            sumL[i][k] = f(sumL[i][k-1], sumL[i+dis][k-1]);
            sumR[i][k] = f(sumR[i][k-1], sumR[i+dis][k-1]);
        }       
    }
}

ll STQuery(int L, int R) {
    // Cuidado con los índices: Las querys consideran que el array a consultar está 1-indexado.
    // Por lo que, si tu array es 0-indexado, y quieres consultar para [0, n-1] -> L = 1, R = n
    // Es decir, aumentamos en uno a L y R: L++; R++;

    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(ST[L][k], ST[R-dis+1][k]);
}

ll RQuery(int L, int R) {
    // Cuidado con los índices: Las querys consideran que el array a consultar está 1-indexado.
    // Por lo que, si tu array es 0-indexado, y quieres consultar para [0, n-1] -> L = 1, R = n
    // Es decir, aumentamos en uno a L y R: L++; R++;

    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(sumR[L][k], sumR[R-dis+1][k]);
}

ll LQuery(int L, int R) {
    // Cuidado con los índices: Las querys consideran que el array a consultar está 1-indexado.
    // Por lo que, si tu array es 0-indexado, y quieres consultar para [0, n-1] -> L = 1, R = n
    // Es decir, aumentamos en uno a L y R: L++; R++;

    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(sumL[L][k], sumL[R-dis+1][k]);
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = a[n+1] = 1e9+5;

        pL[0] = a[0];

        for(int i = 1; i <= n+1; i++)
            pL[i] = pL[i-1] + a[i];

        pR[n+1] = a[n+1];
        for(int i = n; i >= 0; i--)
            pR[i] = pR[i+1] + a[i];

        STBuild();

        bool cmp = 1;

        for(int i = 1; i <= n; i++) { 
            int l = 0, r = i;

            while(l < r) {
                int m = (l+r+1) >> 1;
                if(STQuery(m, i) > a[i]) l = m;
                else r = m-1;
            }

            int L = l + 1;

            l = i, r = n+1;
            while(l < r) {
                int m = (l+r) >> 1;
                if(STQuery(i, m) > a[i]) r = m;
                else l = m+1;
            }

            int R = r-1;

            if(i+1 <= R) {
                if(!(LQuery(i+1, R) <= pL[i]))
                    cmp = 0;
            }
            if(L <= i-1) {
                if(!(RQuery(L, i-1) <= pR[i]))
                    cmp = 0;
            }
        }

        if(cmp) cout << "YES\n";
        else cout << "NO\n";
    }

	
	
    return 0;
}


