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

vector<vi> adj;
vector<bool> vis, isArticulation;
vi tin, low;
int timer;

int n; 

void init() {
    adj.clear(); adj.resize(n);
    vis.clear(); vis.resize(n, 0);
    isArticulation.clear(); isArticulation.resize(n, 0);
    tin.clear(); tin.resize(n, -1);
    low.clear(); low.resize(n, -1);
    timer = 0;
}

void dfs(int v, int p = -1) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;
    int children = 0;

    for(int to : adj[v]) {
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] and p != -1) 
                isArticulation[v] = 1;
            children++;
        }
    }

    if(p == -1 and children > 1)
        isArticulation[v] = 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    while(cin >> n and n) {
        init();

        cin.ignore();

        string s;
        while(getline(cin, s)) {
            stringstream ss(s);
            int node;
            vi temp;

            while(ss >> node) 
                temp.pb(node);

            if(temp[0] == 0) break;

            for(int& x : temp) x--;

            for(int i = 1; i < (int) temp.size(); i++) {
                adj[temp[0]].pb(temp[i]);
                adj[temp[i]].pb(temp[0]);
            }
        }

        dfs(0);

        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(isArticulation[i]) 
                cnt++;

        cout << cnt << "\n";
    }
	
	return 0;
}

