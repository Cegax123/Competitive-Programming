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

    int l = 1, r = n;

    while(l < r) {
        int m = (l+r) >> 1;

        cout << "? " << 1 << " " << n << " " << l << " " << m << endl;
        int t; cin >> t;

        if(t == m-l+1) l = m+1;
        else r = m;
    }

    int Y = l;

    l = 1, r = n;

    while(l < r) {
        int m = (l+r) >> 1;

        cout << "? " << l << " " << m << " " << 1 << " " << n << endl;

        int t; cin >> t;
        
        if(t == m-l+1) l = m+1;
        else r = m;
    }

    int X = l;

    cout << "! " << X << " " << Y << endl;
	
    return 0;
}


