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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, a, b; cin >> n >> a >> b;

    double e[n+1];
    double pe[n+1];

    for(int i = 0; i <= n; i++)
        e[i] = pe[i] = 0;

    for(int i = 1; i < min(a, n); i++) {
        e[i] = 1.0;
        pe[i] = pe[i-1] + e[i];
    }

    double len = b-a+1;

    for(int i = max(1, a); i <= n; i++) {
        int l = max(0, i-b), r = i-a;

        if(a == 0) r--;

        double q = (l-1 >= 0 ? pe[l-1] : 0.0);

        e[i] = (pe[r]-q + len) / (len);

        if(a == 0) e[i] = (pe[r]-q + len) / (len-1);

        pe[i] = e[i] + pe[i-1];
    }


    cout << setprecision(10) << e[n];
	
    return 0;
}


