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
    ll n; cin >> n;
    ll p1 = 1234567, p2 = 123456, p3 = 1234;

    int cnt = 0;
    for(ll a = 0; a <= 1000; a++) {
        for(ll b = 0; b <= 10000; b++) {
            ll c = n - a * p1 - b * p2;

            if(c % p3) continue;
            c /= p3;

            if(c >= 0) cnt++;
        }
    }

    cout << (cnt ? "YES\n" : "NO\n");
	
    return 0;
}


