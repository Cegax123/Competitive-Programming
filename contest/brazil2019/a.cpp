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

struct Circle {
    int x, y, s;
};

int dis(int a, int b, int c, int d) {
    return (c-a) * (c-a) + (d-b) * (d-b);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m, n, k; cin >> m >> n >> k;
    vector<Circle> c(k);

    for(int i = 0; i < k; i++) {
        int x, y, s; cin >> x >> y >> s;
        c[i] = {x, y, s};
    }

    vector<bool> vis(k, false);

    bool cmp = true;

    for(int v = 0; v < k; v++) {
        if(!vis[v]) {
            queue<int> q;
            q.push(v);
            vis[v] = true;

            bool lmt = false;
            bool up = 0, down = 0, lft = 0, rght = 0;

            while(!q.empty()) {
                int i = q.front(); q.pop();

                for(int j = 0; j < k; j++) {
                    if(vis[j]) continue;

                    if(dis(c[i].x, c[i].y, c[j].x, c[j].y) <= (c[i].s + c[j].s) * (c[i].s + c[j].s)) {
                        q.push(j);
                        vis[j] = true;
                    }

                }

                if(c[i].x <= c[i].s) up = 1;
                if(c[i].y <= c[i].s) lft = 1;
                if(c[i].x + c[i].s >= m) down = 1;
                if(c[i].y + c[i].s >= n) rght = 1;
            }
            
            if(up and lft) lmt = true;
            if(up and down) lmt = true;
            if(lft and rght) lmt = true;
            if(down and rght) lmt = true;

            if(lmt) {
                cmp = false;
            }
        }
    }

    cout << (cmp ? "S\n" : "N\n");
	
    return 0;
}


