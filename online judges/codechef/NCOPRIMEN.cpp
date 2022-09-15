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
        int cnt = n/3;

        int a[n];

        for(int i = 0; i < n; i++) 
            cin >> a[i];

        for(int i = 0; i < n; i+=3) {
            if(i) a[i-1] = 2*a[i];
            if(i < n) a[i+1] = 2*a[i];
        }

        for(int i = cnt * 3-1; i < n; i++)
            a[i] = 2;

        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
	
	return 0;
}

