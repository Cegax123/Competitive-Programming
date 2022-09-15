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
	int n, m; cin >> n >> m;

    int a[n][m];

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int h[n][m], v[n][m];

    for(int i = 0; i < n; i++) {
        h[i][0] = a[i][0];
        for(int j = 1; j < m; j++)
            h[i][j] = h[i][j-1] + a[i][j];
    }

    for(int j = 0; j < m; j++) {
        v[0][j] = a[0][j];
        for(int i = 1; i < n; i++)
            v[i][j] = v[i-1][j] + a[i][j];
    }
	
    int cnt = 0; 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j]) continue;

            if(j and h[i][j-1]) cnt++;
            if(h[i][m-1]-h[i][j]) cnt++;
            if(i and v[i-1][j]) cnt++;
            if(v[n-1][j]-v[i][j]) cnt++;
        }
    }

    cout << cnt << "\n";
	
	return 0;
}

