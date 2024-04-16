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
    const int E = 26;
    int l, c; cin >> l >> c;
    string b[l];

    for(int i = 0; i < l; i++)
        cin >> b[i];

    int n; cin >> n;

    int curr[E];

    auto isValid =[&](int x, int y) {
        return x >= 0 and x < l and y >= 0 and y < c;
    };

    set<int> ss[50][50];

    auto cmp = [&](int x, int y, int dirx, int diry, int k, int tt) {
        vi cnt(E, 0);
        int sum = 0;

        while(isValid(x, y)) {
            cnt[b[x][y]-'A']++;
            sum++;

            if(sum > k) {
                cnt[b[x - k * dirx][y - k * diry]-'A']--;
                sum--;
            }

            bool t = true;
            for(int i = 0; i < E; i++)
                if(cnt[i] != curr[i]) t = false;

            if(t) {
                for(int i = 0; i < k; i++) {
                    ss[x - i * dirx][y - i * diry].insert(tt);
                }
            }

            x = x + dirx;
            y = y + diry;
        }
    };


    for(int tt = 0; tt < n; tt++) {
        string s; cin >> s;
        int k = s.size();

        memset(curr, 0, sizeof(curr));

        for(char c : s) curr[c-'A']++;
        for(int i = 0; i < l; i++) {
            cmp(i, 0, 0, 1, k, tt);
            cmp(i, 0, 1, 1, k, tt);
            cmp(i, 0, -1, 1, k, tt);
        }

        for(int j = 0; j < c; j++) {
            cmp(0, j, 1, 0, k, tt);
            cmp(0, j, 1, 1, k, tt);
            cmp(l-1, j, -1, 1, k, tt);
        }
    }

    int cnt = 0;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            if((int) ss[i][j].size() >= 2) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
	
    return 0;
}


