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

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a, b; 

        for(int i = 0; i < n; i++) {
            int x = random(0, 1);
            a += (char) '0' + x;
        }

        int p[n+1];
        p[0] = 0;

        for(int i = 1; i <= n; i++) {
            if(a[i-1] == '1') p[i] = p[i-1] + 1;
            else p[i] = p[i-1] - 1;
        }

        for(int j = 1; j <= n; j++) {
            for(int i = 1; i <= n; i++) {
                cout << (p[i] > p[max(0, i-j)]);
            }
            cout << "\n";
        }
    }

	
    return 0;
}


