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

    int d[n][n];
    memset(d, 0, sizeof(d));

    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        int tmp[k];

        for(int j = 0; j < k; j++) {
            cin >> tmp[j];
            tmp[j]--;
        }


        for(int j = 0; j < k; j++) {
            for(int p = 0; p < k; p++) {
                d[tmp[j]][tmp[p]] = 1;
                d[tmp[p]][tmp[j]] = 1;
            }
        }
    }

    bool cmp = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(d[i][j] == 0) cmp = 0;
        }
    }

    cout << (cmp ? "Yes\n" : "No\n");

	
    return 0;
}


