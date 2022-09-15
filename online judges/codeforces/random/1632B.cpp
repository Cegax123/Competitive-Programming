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
        n--;

        int x = 0;

        for(int i = 20; i >= 0; i--) {
            if((n >> i)&1) {
                x = (1 << i);
                break;
            }
        }

        for(int i = 1; i < x; i++)
            cout << i << " ";
        cout << 0 << " ";

        for(int i = x; i <= n; i++)
            cout << i << " ";

        cout << "\n";
    }
	
	
	return 0;
}

