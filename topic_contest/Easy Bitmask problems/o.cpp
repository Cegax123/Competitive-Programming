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
    string cards[n];

    for(int i = 0; i < n; i++)
        cin >> cards[i];

    char colors[] = {'R', 'G', 'B', 'Y', 'W'};
    int ans = 10;

    for(int i = 0; i < (1 << 10); i++) {
        vector<char> curr;
        int tot = 0;
        for(int j = 0; j < 10; j++) {
            if((i >> j)&1) {
                tot++;
                if(j < 5) curr.pb('1' + j);
                else curr.pb(colors[j-5]);
            }
        }

        map<char, set<string>> mp;
        set<string> free_op;

        for(int j = 0; j < n; j++) {
            int qq = 0;
            int cnt = 0;
            for(char x : curr) {
                if(x == cards[j][0]) cnt++;
            }
            if(cnt == 0) mp[cards[j][1]].insert(cards[j]);
            qq += cnt;

            cnt = 0;
            for(char x : curr) {
                if(x == cards[j][1]) cnt++;
            }
            if(cnt == 0) mp[cards[j][0]].insert(cards[j]);
            qq += cnt;

            if(qq == 0) free_op.insert(cards[j]);
        }

        bool res = 1;

        if((int) free_op.size() >= 2) res = 0;

        for(auto e : mp) {
            if((int) e.second.size() >= 2) res = 0;
        }

        if(res) {
            //if(tot == 1) {
                //for(auto e : mp) {
                    //cout << e.first << endl;
                //}
            //}
            ans = min(ans, tot);
        }
    }

    cout << ans << "\n";

	
    return 0;
}


