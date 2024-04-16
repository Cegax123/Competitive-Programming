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
    int d, m, y; cin >> d >> m >> y;
    int x; cin >> x;

    int L = y * 360 + m * 30 + d;

    cin >> d >> m >> y;

    int R = y * 360 + m * 30 + d;

    int diff = R-L;

    x += diff;

    x %= 7;
    if(x == 0) x += 7;

    cout << x << "\n";
	
    return 0;
}


