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
    int pref[n+1];

    pref[0] = 0;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pref[i] = x + pref[i-1];
    }

    int g = *max_element(pref, pref+n+1);

    cout << 100 + g << "\n";
	
    return 0;
}


