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
    const int L = 11;

    ll p10[L+1];

    p10[0] = 1;

    for(int i = 1; i <= L; i++)
        p10[i] = p10[i-1] * 10;

    ll num = 0;
    for(int i = 0; i < L; i++) num = num * 10 + i;

    map<ll, int> dis;
    dis[num] = 0;

    queue<ll> q;
    q.push(num);

    while(!q.empty()) {
        ll v = q.front(); q.pop();

        for(int i = 0; i < L; i++) {
            for(int j = i+1; j < L; j++) {
                ll nv = v;

                ll l = nv / p10[L-1-i];
                ll r = nv % p10[L-1-j];

                ll sub = nv / p10[L-1-j];
                sub %= p10[j-i+1];
                ll rsub = 0;

                int len = j-i+1;

                for(int k = 0; k < len; k++) {
                    rsub = rsub * 10 + (sub % 10);
                    sub /= 10;
                }

                nv = l * p10[L-1-i] + sub * p10[L-1-j] + r;

                if(nv == num or dis[nv]) continue;
                dis[nv] = dis[v] + 1;
            }
        }
    }
    
    int t; cin >> t;
    while(t--) {
    	string a, b; cin >> a >> b;
    	map<char, int> id;
    	
    	for(int i = 0; i < L; i++) id[a[i]] = i;
    	
    	ll num = 0;
    	
    	for(int i = 0; i < L; i++) num = num * 10 + id[b[i]];
    	
    	cout << dis[num] << "\n";
    }
	
    return 0;
}



