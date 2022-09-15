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
    int k; cin >> k;

    const int maxn = 1e3+5;
    char G[maxn][maxn];

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            G[i][j] = 'N';

    vi prev(1, 0);
    int ind = 2;

    for(int i = 2; i <= 31; i++) {
        vi tmp;

        for(int j = 0; j < i; j++)
            tmp.pb(ind++);

        for(int j = 0; j < i-1; j++) {
            G[tmp[j]][prev[j]] = G[prev[j]][tmp[j]] = 'Y';
            G[prev[j]][tmp[i-1]] = G[tmp[i-1]][prev[j]] = 'Y';
        }

        prev = tmp;
    }

    for(int i = 0; i < 30; i++) {
        if((k >> i)&1) {
            G[prev[i+1]][1] = G[1][prev[i+1]] = 'Y';
        }
    }

    cout << ind << "\n";
    for(int i = 0; i < ind; i++) {
        for(int j = 0; j < ind; j++)
            cout << G[i][j];

        cout << "\n";
    }
	
    return 0;
}


