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

const int L = 60;

void print_bit(int x) {
    for(int i = L-1; i >= 0; i--) {
        cout << ((x >> i)&1);
    }
    cout << "\n";
}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
return uniform_int_distribution<long long>(l,r)(rng);
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    //ll n; cin >> n;
    //n = 31;
    ////cout << n << endl;
    ////print_bit(n);

    //cout << endl;
    //int cnt = 0;
    //int ans = 0;

    //for(int i = 1; i < n; i++) {
        //for(int j = 1; j < n; j++) {
            //for(int k = 1; k < n; k++) {
                //if(i + j + k == n and ((i | j | k) == n)) {
                    ////print_bit(i);
                    ////print_bit(j);
                    ////print_bit(k);

                    ////if((i&j) or (i&k) or(j&k)) {
                        ////cout << "HOLA";
                        ////cnt++;
                    ////}
                    //ans++;

                    ////cout << "===\n";
                //}
            //}
        //}
    //}

    //cout << ans << "\n";

    //assert(cnt == 0);

    const ll mod = (ll) 1e9 + 7;

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;

        int cnt = 0;
        for(int i = 0; i < L; i++) {
            cnt += ((n >> i)&1ll);
        }

        if(cnt < 3) {
            cout << 0 << "\n";
            continue;
        }

        //cout << cnt << endl;
        ll ans = 1;

        for(int i = 0; i < cnt; i++) {
            ans = ans * 3 % mod;
        }

        ans = (ans-3) % mod;

        ll del = 1;

        for(int i = 0; i < cnt; i++)
            del = del * 2 % mod;
        del = (del - 2) % mod * 3 % mod;


        ans = (ans-del) % mod;

        if(ans < 0) ans += mod;

        cout << ans << "\n";
    }
	
    return 0;
}


