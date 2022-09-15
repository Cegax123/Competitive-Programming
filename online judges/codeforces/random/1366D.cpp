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

const int maxn = 1e7+10;
int sieve[maxn];

void init() {
    memset(sieve, 0, sizeof(sieve));
    sieve[1] = 1;

    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;
        for(int j = 2; i*j < maxn; j++) {
            if(sieve[i*j] == 0) sieve[i*j] = i;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    int n; cin >> n;

    vii b;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        vi div;

        int d = sieve[a];
        while(d != 1) {
            div.pb(d);
            while(a%d==0) a/=d;
            d = sieve[a];
        }

        if((int) div.size() <= 1) 
            b.pb({-1, -1});
        else {
            int x = div[0], y=1;
            for(auto e : div)
                y *= e;
            y /= x;
            b.pb({x, y});
        }
    }

    for(int i = 0; i < n; i++)
        cout << b[i].first << " ";
    cout << "\n";
    for(int i = 0; i < n; i++)
        cout << b[i].second << " ";
		

	return 0;
}

