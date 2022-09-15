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

const int maxn = 2005;
const ll INF = (ll) 1e18;
ll dp[maxn][maxn][3];
string A[maxn+1];
ll r[maxn], c[maxn];
int h, w;

void find_cost_row(int i, int j, char col) {
    if(A[i][j] == col) {
        dp[i][j][2] = min({dp[i][j][2], dp[i][j-1][2], dp[i][j-1][1]});
        dp[i][j][1] = min({dp[i][j][1], dp[i][j-1][0] + c[j]});
    }
    else {
        dp[i][j][1] = min({dp[i][j][1], dp[i][j-1][2] + c[j], dp[i][j-1][1] + c[j]});
        dp[i][j][0] = min({dp[i][j][0], dp[i][j-1][0]});
    }
}

void find_cost_col(int i, int j, char col) {
    if(A[i][j] == col) {
        dp[i][j][2] = min({dp[i][j][2], dp[i-1][j][2], dp[i-1][j][0]});
        dp[i][j][0] = min({dp[i][j][0], dp[i-1][j][1] + r[j]});
    }
    else {
        dp[i][j][0] = min({dp[i][j][0], dp[i-1][j][2] + r[j], dp[i-1][j][0] + r[j]});
        dp[i][j][1] = min({dp[i][j][1], dp[i-1][j][1]});
    }
}

ll find_ans(char col) {
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            for(int x = 0; x < 3; x++) 
                dp[i][j][x] = INF;


    if(A[0][0] == col)
        dp[0][0][2] = 0;
    else {
        dp[0][0][0] = r[0];
        dp[0][0][1] = c[0];
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i) find_cost_col(i, j, col);
            if(j) find_cost_row(i, j, col);
        }
    }

    return min({dp[h-1][w-1][0], dp[h-1][w-1][1], dp[h-1][w-1][2]});
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> h >> w;

    for(int i = 0; i < h; i++)
        cin >> r[i];

    for(int i = 0; i < w; i++)
        cin >> c[i];


    for(int i = 0; i < h; i++)
        cin >> A[i];
    
    ll ans = min(find_ans('0'), find_ans('1'));

    cout << ans << "\n";
	
    return 0;
}


