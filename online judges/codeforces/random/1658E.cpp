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

int n, k;

ii T(const ii& a) {
    return {a.first + a.second, a.second - a.first};
}

ii Tp(const ii& a) {
    return {(a.first-a.second)/2, (a.first+a.second)/2};
}

int get_id(const ii& pos) {
    return pos.first * n + pos.second;
}

ii get_pos(const int& id) {
    return {id/n, id%n};
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    vii byV;
    deque<ii> byX, byY;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ii p = {i, j};
            ii q = T(p);
            int id = get_id({i, j});

            int c; cin >> c;
            byX.pb({q.first, id});
            byY.pb({q.second, id});
            byV.pb({c, id});
        }
    }

    sort(all(byX));
    sort(all(byY));
    sort(all(byV));
	
    char ans[n+5][n+5];
    vector<bool> used(n*n, 0);

    while(!byV.empty()) {
        if(used[byV.back().second]) {
            byV.pop_back();
            continue;
        }
        
        int id = byV.back().second;
        used[id] = 1;
        ii pos = get_pos(id);
        
        ans[pos.first][pos.second] = 'M';
        byV.pop_back();

        ii q = T(pos);

        while(!byX.empty()) {
            int currId = byX.back().second;
            if(used[currId]) {
                byX.pop_back();
                continue;
            }

            int X = byX.back().first;
            if(abs(X-q.first) > k) {
                used[currId] = 1;
                ii currPos = get_pos(currId);
                ans[currPos.first][currPos.second] = 'G';
            }
            else break;
        }

        while(!byX.empty()) {
            int currId = byX.front().second;
            if(used[currId]) {
                byX.pop_front();
                continue;
            }

            int X = byX.front().first;
            if(abs(X-q.first) > k) {
                used[currId] = 1;
                ii currPos = get_pos(currId);
                ans[currPos.first][currPos.second] = 'G';
            }
            else break;
        }

        while(!byY.empty()) {
            int currId = byY.back().second;
            if(used[currId]) {
                byY.pop_back();
                continue;
            }

            int Y = byY.back().first;
            if(abs(Y-q.second) > k) {
                used[currId] = 1;
                ii currPos = get_pos(currId);
                ans[currPos.first][currPos.second] = 'G';
            }
            else break;
        }

        while(!byY.empty()) {
            int currId = byY.front().second;
            if(used[currId]) {
                byY.pop_front();
                continue;
            }

            int Y = byY.front().first;
            if(abs(Y-q.second) > k) {
                used[currId] = 1;
                ii currPos = get_pos(currId);
                ans[currPos.first][currPos.second] = 'G';
            }
            else break;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
	
    return 0;
}


