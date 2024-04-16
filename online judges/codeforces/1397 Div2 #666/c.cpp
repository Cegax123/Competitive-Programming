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
    ll a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << 1 << " " << 1 << "\n";
    cout << -a[0] << "\n";

    a[0] = 0;

    if(n >= 2) {
        cout << 2 << " " << n << "\n";
        for(int i = 1; i < n; i++) {
            cout << a[i] * (n-1) << " ";
            a[i] += a[i] * (n-1);
        }
        cout << "\n";
    }
    else cout << "1 1\n0\n";

    cout << 1 << " " << n << "\n";
    for(int i = 0; i < n; i++) {
        cout << -a[i] << " ";
    }
    cout << "\n";
	
    return 0;
}


