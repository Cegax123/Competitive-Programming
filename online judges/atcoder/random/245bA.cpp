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

    string name1 = "Takahashi", name2 = "Aoki";
	
    int a, b, c, d; cin >> a >> b >> c >> d;

    if(a < c) cout << name1 << "\n";
    else if(c < a) cout << name2 << "\n";
    else {
        if(b <= d) cout << name1 << "\n";
        else cout << name2 << "\n";
    }
	
	return 0;
}

