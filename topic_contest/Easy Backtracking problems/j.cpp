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

set<vii> poss;
//vector<vii> poss;
int n, k;
set<ii> scurr;
vii curr;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void gen(int pos=0) {
    if(pos == k) {
        //poss.pb(curr);
        vii tmp = curr;
        sort(all(tmp));
        poss.insert(tmp);
        return;
    }

    if(pos == 0) {
        curr.pb({0, 0});
        scurr.insert({0, 0});

        gen(pos+1);

        curr.pop_back();
        scurr.erase({0, 0});
    }
    else {
        set<ii> used;
        vii tmp = curr;

        for(const auto& e : tmp) {
            for(int d = 0; d < 4; d++) {
                ii x;
                x.first = e.first + dx[d], x.second = e.second + dy[d];

                //cout << x.first << " " << x.second << "\n";

                if(x.second < 0 or (x.second == 0 and x.first <= 0)) continue;
                if(scurr.count(x)) continue;
                if(used.count(x)) continue;

                used.insert(x);
                
                scurr.insert(x);
                curr.pb(x);

                gen(pos+1);
                
                scurr.erase(x);
                curr.pop_back();
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    string b[n];

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    gen();

    //for(const auto& v : poss) {
        //for(auto e : v) {
            //cout << e.first << " " << e.second << "\n";
        //}
        //cout << "\n";
    //}

    auto is_valid = [&](int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < n;
    };

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            for(const auto& v : poss) {
                bool cmp = 1;
                for(auto e : v) {
                    int x = i + e.first, y = j + e.second;

                    if(!is_valid(x, y)) cmp = 0;
                    else if(b[x][y] == '#') cmp = 0;
                }
                cnt += cmp;
            }
        }
    }

    cout << cnt << "\n";
	
    return 0;
}


