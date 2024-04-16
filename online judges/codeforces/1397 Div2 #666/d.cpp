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

//const int maxa = 101;
//const int maxn = 101;
//int dp[maxa][maxa][maxa][maxa][5];
//const int N = 1, P = 2;

//int find(int a, int b, int c, int d, int banned=-1) {
    //if(banned != -1 and dp[a][b][c][d][banned]) return dp[a][b][c][d][banned];

    //if(banned != 0 and a) {
        //if(find(a-1, b, c, d, 0) == P) {
            //return dp[a][b][c][d][banned] = N;
        //}
    //}
    //if(banned != 1 and b) {
        //if(find(a, b-1, c, d, 1) == P) {
            //return dp[a][b][c][d][banned] = N;
        //}
    //}
    //if(banned != 2 and c) {
        //if(find(a, b, c-1, d, 2) == P) {
            //return dp[a][b][c][d][banned] = N;
        //}
    //}
    //if(banned != 3 and d) {
        //if(find(a, b, c, d-1, 3) == P) {
            //return dp[a][b][c][d][banned] = N;
        //}
    //}
    //return P;
//}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //int lmt = 10;
    //for(int i = 1; i <= lmt; i++) {
        //for(int j = i; j <= lmt; j++) {
            //for(int k = j; k <= lmt; k++) {
                //for(int l = k; l <= lmt; l++) {
                    //if(find(i, j, k, l) == P) {
                        //cout << "P ";
                        ////cout << i << " " << j << " " << k << " " << l << " ";

                        //cout << (i+j+k+l) % 2 << "\n";
                    //}
                    //else {
                        //cout << "N ";
                        //cout << (i+j+k+l) % 2 << "\n";
                    //}
                    ////cout << i << " " << j << " " << k << ": ";
                    ////if(find(i, j, k) == N) cout << "N";
                    ////else cout << "P";
                    ////cout << "\n";
                //}
            //}
        //}
    //}

    string N = "T";
    string P = "HL";

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(n == 1) {
            cout << N << "\n";
            continue;
        }
        else if(n == 2) {
            if(a[0] == a[1]) cout << P << "\n";
            else cout << N << "\n";
            continue;
        }

        sort(all(a));

        int sum = 0;
        for(int i = 0; i < n-1; i++) sum += a[i];

        if(a[n-1] > sum) {
            cout << N << "\n";
            continue;
        }

        sum += a[n-1];

        if(sum%2 == 1) cout << N << "\n";
        else cout << P << "\n";
    }

	
    return 0;
}


