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

const int L = 14;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout << "? ";
    for(int i = (1 << (L/2))-1, cnt = 0; cnt < 100; i--, cnt++) {
        cout << i << " ";
    }

    cout << endl;

    int l; cin >> l;
    l = ((l >> (L/2)) << (L/2));

    cout << "? ";
    for(int i = (1 << (L/2))-1, cnt = 0; cnt < 100; i--, cnt++) {
        cout << (i << (L/2)) << " ";
    }

    cout << endl;

    int r; cin >> r;
    r = (r&((1 << (L/2))-1));

    cout << "! " << (l|r) << endl;
	
    return 0;
}


