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
    int n; cin >> n;
    vector<bool> descarted(n+1, 0);

    int q;
    while(true) {
        int u = -1, v = -1;
        for(int i = 1; i <= n; i++) {
            if(!descarted[i]) {
                if(u == -1) u = i;
                else if(v == -1) v = i;
            }
        }

        if(v == -1) break;

        cout << "? " << u << " " << v << endl;
        cin >> q;

        if(q) descarted[u] = 1;
        else descarted[v] = 1;
    }

    int ingree = 0;
    int outgree = 0;
    int u = -1;

    for(int i = 1; i <= n; i++) {
        if(!descarted[i]) u = i;
    }

    if(u == -1) {
        cout << "! " << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        cout << "? " << i << " " << u << endl;
        int q; cin >> q;
        ingree += q;

        cout << "? " << u << " " << i << endl;
        cin >> q;
        outgree += q;
    }




    if(ingree == n-1 and outgree == 0) cout << "! " << u << endl;
    else cout << "! " << -1 << endl;
	
    return 0;
}


