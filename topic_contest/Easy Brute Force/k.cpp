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
    int n, m; cin >> n >> m;
    vector<bool> han(n, false), ham(m, false);

    int cnt = 0;

    int b; cin >> b;

    cnt += b;

    for(int i = 0; i < b; i++) {
        int x; cin >> x;
        han[x] = 1;

    }
	
    cin >> b;
    for(int i = 0; i < b; i++) {
        int x; cin >> x;
        ham[x] = 1;
    }

    cnt += b;

    for(int ind = 0; ind < 1e6; ind++) {
        bool res = han[ind % n] or ham[ind % m];

        

        if(res) {
            cnt += han[ind % n] == false;
            cnt += ham[ind % m] == false;

            han[ind % n] = ham[ind % m] = 1;
        }
    }

    //for(int i = 0; i < n; i++) cout << han[i] << " ";
    //cout << endl;
    //for(int i = 0; i < m; i++) cout << ham[i] << " ";
    //cout << endl;

    if(cnt == n + m) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}


