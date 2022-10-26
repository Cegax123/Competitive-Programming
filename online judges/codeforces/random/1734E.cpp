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
    int b[n];

    for(int i = 0; i < n; i++) 
        cin >> b[i];

    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = (i+1) * (j+1) % n;
        }
    }

    for(int j = 0; j < n; j++) {
        int add = (b[j]-a[j][j]) % n;
        if(add < 0) add += n;

        for(int i = 0; i < n; i++)
            a[i][j] = (a[i][j] + add) % n;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
	
    return 0;
}


