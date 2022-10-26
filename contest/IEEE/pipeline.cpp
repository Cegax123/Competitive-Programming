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

char pipe[55][55][55];
int id[55][55][55]

int n, m, d;

bool is_valid(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

void flood_fill(int x, int y, int k) {
    id[x][y] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m >> d;

        for(int k = 0; k < d; k++) 
            for(int i = 0; i < n; i++) 
                for(int j = 0; j < m; j++) 
                    cin >> pipe[i][j][k];

        memset(id, 0, sizeof(id));

        int ind = 1;
        for(int k = 0; k < d; k++) {
            
        }
    }
	
    return 0;
}


