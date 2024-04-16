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

const int maxn = 250 + 5;
int a[maxn], pa[maxn];
int t[maxn][maxn];
int opt[maxn][maxn];

int sum(int i, int j) {
    if(i == 0) return pa[j];
    return pa[j] - pa[i-1];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        pa[0] = a[0];
        for(int i = 1; i < n; i++)
            pa[i] = pa[i-1] + a[i];

        for(int i = 0; i < n; i++) {
            t[i][i] = a[i];
            opt[i][i] = i;
        }

        for(int add = 1; add < n; add++) {
            for(int i = 0; i + add < n; i++) {
                int j = i + add;

                t[i][j] = (int) 1e9;

                for(int k = opt[i][j-1]; k <= opt[i+1][j]; k++) {
                    if(t[i][j] > t[i][k-1] + t[k+1][j]) {
                        t[i][j] = t[i][k-1] + t[k+1][j];
                        opt[i][j] = k;
                    }
                }

                t[i][j] += sum(i, j);
            }
        }

        //for(int i = 0; i < n; i++) {
            //for(int j = i; j < n; j++) {
                //cout << i << " " << j << " " << t[i][j] << "\n";
            //}
        //}


        cout << t[0][n-1]-sum(0, n-1) << "\n";
    }


	
    return 0;
}



