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
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int r=-1, c=-1;

        cout << "? 1 1" << endl;
        int d1; cin >> d1;
        cout << "? " << n << " 1" << endl;
        int d2; cin >> d2;

        if(d1 + d2 == n-1) {
            r = d1+1;
        }
        else if(d1 == d2) {
            c = d1+1;
        }
        else {
            if(d1 > d2) r = d1+1, c = d2+1;
            else r = n-d2, c = d1+1;
        }

        if(r == -1) {
            cout << "? 1 " << c << endl;
            int d3; cin >> d3;
            r = d3+1;
        }
        else if(c == -1) {
            cout << "? " << r << " 1" << endl;
            int d3; cin >> d3;
            c = d3+1;
        }

        cout << "! " << r << " " << c << endl;
    }


	
    return 0;
}


