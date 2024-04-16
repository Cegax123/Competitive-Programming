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

pair<ll, ll> find(ll n, ll m) {
    if(n == 1) {
        return {1, 1};
    }

    ll stx[] = {1, 1, 1 + n/2, n};
    ll sty[] = {1, 1 + n/2, 1 + n/2, n/2};

    ll sz = (n / 2) * (n / 2);
    pair<ll, ll> pos;

    if(m <= sz) {
        pos = find(n/2, m);
        swap(pos.first, pos.second);

        return {stx[0] + pos.first - 1, sty[0] + pos.second - 1};
    }

    m -= sz;

    if(m <= sz) {
        pos = find(n/2, m);
        return {stx[1] + pos.first - 1, sty[1] + pos.second - 1};
        
    }

    m -=sz;

    if(m <= sz) {
        pos = find(n/2, m);
        return {stx[2] + pos.first - 1, sty[2] + pos.second - 1};
    }

    m -= sz;

    pos = find(n/2, m);

    //if(n == 8) {
        //cout << pos.first << " " << pos.second << endl;
    //}

    swap(pos.first, pos.second);

    pos.first = -pos.first;
    pos.second = -pos.second;

    //if(n == 8) {
        //cout << pos.first << " " << pos.second << endl;
    //}
    
    return {stx[3]+ pos.first + 1, sty[3] + pos.second + 1};
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m; cin >> n >> m;
    
    pair<ll, ll> pos = find(n, m);

    cout << pos.first << " " << pos.second << "\n";
	
    return 0;
}


