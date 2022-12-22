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
        int n; cin >> n;

        auto get_result = [](int n, char a, char b) {
            if(n == 0) return;
            int l = (n-1)/2, r = n/2;

            for(int i = 0; i < l; i++) cout << a;
            cout << b;
            for(int i = 0; i < r; i++) cout << a;
        };

        if(n%2 == 0) get_result(n, 'a', 'b');
        else {
            int l = (n-1)/2, r = l;
            if(l&1) { l++; r--; }

            get_result(l, 'a', 'b');
            cout << 'c';
            get_result(r, 'x', 'y');
        }

        cout << "\n";
    }

	
    return 0;
}


