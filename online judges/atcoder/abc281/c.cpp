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
    ll n, t; cin >> n >> t;
    ll a[n];
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if(i) a[i] += a[i-1];
    }

    t %= sum;
    if(t == 0) t += sum;

    for(int i = 0; i < n; i++) {
        if(t <= a[i]) {
            cout << i+1 << " ";
            if(i == 0) cout << t << "\n";
            else cout << t-a[i-1] << "\n";
            break;
        }
    }
	
    return 0;
}


