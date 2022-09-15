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
    int h1, w1; cin >> h1 >> w1;
    int A[h1][w1];

    for(int i = 0; i < h1; i++)
        for(int j = 0; j < w1; j++)
            cin >> A[i][j];

    int h2, w2; cin >> h2 >> w2;
    int B[h2][w2];
    
    for(int i = 0; i < h2; i++)
        for(int j = 0; j < w2; j++)
            cin >> B[i][j];

    int cnt[1 << 15];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < (1 << 15); i++) {
        for(int j = 0; j < 15; j++) {
            if((i >> j) & 1)
                cnt[i]++;
        }
    }

    bool ans = 0;
    for(int i = 0; i < (1 << h1); i++) {
        if(cnt[i] != h2) continue;

        vi r;
        for(int a = 0; a < h1; a++)
            if((i >> a)&1)
                r.pb(a);

        for(int j = 0; j < (1 << w1); j++) {
            if(cnt[j] != w2) continue;
            vi c;

            for(int b = 0; b < w1; b++)
                if((j >> b)&1)
                    c.pb(b);

            bool cmp = 1;
            for(int a = 0; a < h2; a++) {
                for(int b = 0; b < w2; b++) {
                    if(B[a][b] != A[r[a]][c[b]]) cmp = 0;
                }
            }

            ans = ans or cmp;
        }
    }

    if(ans) cout << "Yes\n";
    else cout << "No\n";
	
    return 0;
}


