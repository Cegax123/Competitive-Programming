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
    ll L[n], R[n];

    int x[n];

    for(int i = 0; i < n; i++)
        cin >> x[i];

    sort(x, x+n);

    ll sumL = 0, sumR = 0;

    for(int i = 0; i < n; i++) {
        L[i] = x[i] - x[0];
        sumL += L[i];
    }

    for(int i = n-1; i >= 0; i--) {
        R[i] = x[n-1] - x[i];
    }

    ll ans = (ll) 1e18;
    ll y = -1;
    for(int i = 0; i < n; i++) {
        ll curr = sumL + sumR - (ll) (n-i) * L[i] - (ll) i * R[i];
        sumL -= L[i];
        sumR += R[i];

        if(curr < ans) {
            ans = curr;
            y = x[i];
        }
    }
    cout << y << "\n";
	
    return 0;
}


