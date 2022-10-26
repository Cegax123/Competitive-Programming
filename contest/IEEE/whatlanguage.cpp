#include<bits/stdc++.h>
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

const int maxn = (int) (1e7+5);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, p; cin >> n >> p;

    map<string, int> id;
    int Y[maxn], N[maxn];

    memset(Y, -1, sizeof(Y));

    string la[maxn];

    for(int i = 0; i < n; i++) {
        char op; cin >> op;
        if(op == 'I') {
            int u; cin >> u;
            string t; cin >> t;
            id[t] = u;

            cin >> Y[u] >> N[u];
        }
        else {
            int u; cin >> u;
            cin >> la[u];
        }
    }

    cin.ignore();

    for(int tt = 0; tt < p; tt++) {
        string s;
        getline(cin, s);

        set<int> idx;

        int k = s.size();
        for(int i = 0; i < k; i++) {
            string tmp = ""+s[i];
            if(id[tmp]) idx.insert(i);
        }
    }
   	
    return 0;
}


