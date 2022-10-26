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

const int maxc = 22;
const int maxa = 361;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        int c[maxc][maxa];
        memset(c, 0, sizeof(c));

        set<int> h[maxc];

        for(int i = 0; i < n; i++) {
            char fig; cin >> fig;

            if(fig == 'C') {
                int r, t1, t2; cin >> r >> t1 >> t2;

                if(t1 < t2) {
                    for(int x = t1 + 1; x <= t2; x++)
                        c[r][x] = 1;
                }
                else {
                    for(int x = t1+1; x <= 360; x++) 
                        c[r][x] = 1;
                    for(int x = 1; x <= t2; x++)
                        c[r][x] = 1;
                }
            }
            else {
                int r1, r2, t; cin >> r1 >> r2 >> t;

                for(int i = r1; i <= r2-1; i++)
                    h[i].insert(t);
            }
        }

        for(int i = 1; i <= 360; i++)
            c[0][i] = 2;
        
        for(int i = 0; i <= 20; i++) {
            vi v;
            for(int x : h[i]) v.pb(x);

            int k = v.size();
            
            if(k) {
                if(v[0] == 0) {
                    for(int j = 0; j < k-1; j++) {
                        bool found2 = 0;
                        for(int d = v[j]+1; d <= v[j+1]; d++)
                            if(c[i][d] == 2) found2 = 1;

                        if(found2) {
                            for(int d = v[j]+1; d <= v[j+1]; d++)
                                c[i][d] = 2;
                        }
                    }

                    bool found2 = 0;
                    for(int d = v[k-1]+1; d <= 360; d++)
                        if(c[i][d] == 2) found2 = 1;

                    if(found2) {
                        for(int d = v[k-1]+1; d <= 360; d++)
                            c[i][d] = 2;
                    }
                }
                else {
                    for(int j = 1; j < k-1; j++) {
                        bool found2 = 0;
                        for(int d = v[j]+1; d <= v[j+1]; d++)
                            if(c[i][d] == 2) found2 = 1;

                        if(found2) {
                            for(int d = v[j]+1; d <= v[j+1]; d++)
                                c[i][d] = 2;
                        }
                    }

                    bool found2 = 0;
                    for(int d = 1; d <= v[0]; d++)
                        if(c[i][d] == 2) found2 = 1;

                    for(int d = v[k-1]+1; d <= 360; d++)
                        if(c[i][d] == 2) found2 = 1;

                    if(found2) {
                        for(int d = 1; d <= v[0]; d++)
                            c[i][d] = 2;

                        for(int d = v[k-1]+1; d <= 360; d++)
                            c[i][d] = 2;
                    }
                }
            }

            for(int d = 1; d <= 360; d++) {
                if(c[i+1][d] == 0 and c[i][d] == 2) c[i+1][d] = 2;
            }
        }

        bool found = 0;
        for(int j = 1; j <= 360; j++) {
            if(c[20][j] == 2)
                found = 1;
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    
	
    return 0;
}


