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

const int maxn = 1e6;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    int f[maxn+5];
    memset(f, 0, sizeof(f));

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        f[a] = 1;
    }

    int cnt = 0;
    for(int i = 1; i <= maxn; i++) {
        if(f[i]) continue;
        int g = 0;

        for(int j = 2; i*j <= maxn; j++) {
            if(f[i*j]) g = __gcd(i*j, g);
        }
        if(g == i) cnt++;
    }
	
    cout << cnt << "\n";
	
	return 0;
}

