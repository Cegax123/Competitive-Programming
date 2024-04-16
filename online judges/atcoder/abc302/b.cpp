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
    int h, w; cin >> h >> w;
    string s[h];

    for(int i = 0; i < h; i++)
        cin >> s[i];

    int dirx[] = {1, 1, -1, -1, 1, -1, 0, 0};
    int diry[] = {1, -1, 1, -1, 0, 0, 1, -1};

    auto is_valid = [&](int x, int y) {
        return x >= 0 and x < h and y >= 0 and y < w;
    };

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            for(int d = 0; d < 8; d++) {
                string curr;
                for(int k = 0; k < 5; k++) {
                    int nx = i + dirx[d] * k, ny = j + diry[d] * k;
                    if(is_valid(nx, ny)) curr += s[nx][ny];
                }

                if(curr == "snuke") {
                    for(int k = 0; k < 5; k++) {
                        cout << i + dirx[d] * k + 1 << " " << j + diry[d] * k + 1 << "\n";
                    }
                    return 0;
                }
            }
        }
    }

	
    return 0;
}


