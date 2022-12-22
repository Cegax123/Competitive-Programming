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
        int m; cin >> m;
        string b[2];

        for(int i = 0; i < 2; i++) 
            cin >> b[i];

        auto comp = [&](int r, int c) {
            int posX = r, posY = c;

            bool vis[2][m];
            memset(vis, 0, sizeof(vis));

            while(posY < m) {
                if(b[posX][posY] == 'W') return false;

                vis[posX][posY] = 1;
                int nxtPosX = 1-posX;

                if(b[nxtPosX][posY] == 'W' or vis[nxtPosX][posY]) {
                    posY++;
                }
                else {
                    posX = 1-posX;
                }
            }

            return true;
        };

        if(comp(0, 0) or comp(1, 0)) cout << "YES\n";
        else cout << "NO\n";
    }

	
    return 0;
}


