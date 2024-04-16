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
    int p[n+1];
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    int m; cin >> m;

    vector<bool> used(n+1, 0);

    vector<vi> groups(n);
    vi id(n+1, 0);

    int k = 0;
    int y = 0;
    for(int i = 1; i <= n; i++) {
        if(used[i]) continue;

        int x = i;
        
        vi curr;

        while(!used[x]) {
            curr.pb(x);
            used[x] = 1;
            id[x] = k;

            x = p[x];
        }
        y += (int) curr.size()-1;
        groups[k++] = curr;
    }

    vii swaps;
    while(y != m) {
        if(y < m) {
            y++;
            for(int i = 1; i <= n; i++) {
                if(id[i] != id[1]) {
                    int tmp = id[i];
                    swaps.pb({1, i});
                    for(int j = 1; j <= n; j++) {
                        if(id[j] == tmp) id[j] = id[1];
                    }
                    break;
                }
            }
        }
        else {
            y--;
            for(int i = 1; i <= n; i++) {
                if((int) groups[id[i]].size() > 1) {
                    vi tmp = groups[id[i]];
                    int len = tmp.size();

                    groups[id[i]].clear();

                    int pos1 = -1, pos2 = -1;
                    int h = n+1;

                    for(int j = 0; j < len; j++) {
                        if(tmp[j] == i) pos1 = j;
                        else if(tmp[j] < h) {
                            h = tmp[j];
                            pos2 = j;
                        }
                    }

                    swaps.pb({i, h});

                    auto complete = [&](int p1, int p2, int x) {
                        int it = p2 % len;


                        do {
                            it++;
                            it %= len;

                            groups[x].pb(tmp[it]);
                            id[tmp[it]] = x;
                        } while(it != p1);
                    };

                    int added1 = 0;
                    for(int j = 0; j < n; j++) {
                        if(groups[j].empty()) {
                            if(!added1) {
                                complete(pos1, pos2, j);
                                added1 = true;
                            }
                            else {
                                complete(pos2, pos1, j);
                                break;
                            }
                        }
                    }

                    break;
                }
            }
        }
    }

    cout << swaps.size() << "\n";
    for(auto e : swaps) {
        cout << e.first << " " << e.second << " ";
    }
	
    return 0;
}


