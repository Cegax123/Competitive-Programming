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

const int P = 1, N = 2;
const int maxn = 1e5 + 5;
int dp[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    dp[0] = P;
    for(int i = 1; i <= k; i++) {
        bool found = false;
        for(int j = 0; j < n; j++) {
            if(i - a[j] >= 0 and dp[i-a[j]] == P) found = true;
        }
        dp[i] = (found ? N : P);
    }

    cout << (dp[k] == N ? "First\n" : "Second\n");
	
    return 0;
}


