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

const int maxn = 1005;
char e[maxn][maxn];

bool comp(int a, int b, int c) {
    return e[a][b] == e[b][c];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++)
                cin >> e[i][j];

        if(m&1) {
            cout << "YES\n";
            cout << 1 << " ";
            for(int i = 0; i < m; i++)
                cout << (2-(i&1)) << " ";
            cout << "\n";
            continue;
        }
        bool found = 0;
        int x,y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i==j) continue;
                if(e[i][j] == e[j][i]) {
                    found = 1;
                    x = i+1; y = j+1;
                }
            }
        }

        if(found) {
            cout << "YES\n";
            cout << y << " ";
            for(int i = 0; i < m; i++) {
                if(i&1) cout << y << " ";
                else cout << x << " ";
            }
            cout << "\n";
            continue;
        }

        if(n==2) {
            cout << "NO\n";
            continue;
        }

        vi a;

        a.pb(0);
        a.pb(1);
        a.pb(2);

        cout << "YES\n";
        do {
            if(comp(a[0], a[1], a[2])) {
                if(m%4==0) {
                    cout << a[1]+1 << " ";
                    for(int i = 0; i < m/4; i++) {
                        cout << a[2]+1 << " " << a[1]+1 << " " << a[0]+1 << " " << a[1]+1 << " ";
                    }
                    cout << "\n";
                }
                else {
                    cout << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " ";
                    for(int i = 0; i < m/4; i++) {
                        cout << a[1]+1 << " " << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " ";
                    }
                    cout << "\n";
                }
                break;
            }
        } while(next_permutation(all(a)));
    }
	
	
	return 0;
}