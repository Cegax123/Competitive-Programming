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

vector<int> suffix_array(vector<int> &s){
	int n = s.size();
	vector<int> a(n);
	vector<int> mapeo(n);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&] (int i, int j){
		return s[i] < s[j];
	});
	mapeo[a[0]] = 0;
	for(int i = 1; i < n; i++){
		mapeo[a[i]] = mapeo[a[i - 1]] + (s[a[i - 1]] != s[a[i]]);
	}
	int len = 1;
	vector<int> head(n);
	vector<int> new_mapeo(n);
	vector<int> sorted_by_second(n);
	while(len < n){
		for(int i = 0; i < n; i++) sorted_by_second[i] = (a[i] - len + n) % n;
		for(int i = n - 1; i >= 0; i--) head[mapeo[a[i]]] = i;
		for(int i = 0; i < n; i++){
			int x = sorted_by_second[i];
			a[head[mapeo[x]]++] = x;
		}
		new_mapeo[a[0]] = 0;
		for(int i = 1; i < n; i++){
			if(mapeo[a[i - 1]] != mapeo[a[i]]){
				new_mapeo[a[i]] = new_mapeo[a[i - 1]] + 1;
			}
			else{
				int pre = mapeo[(a[i - 1] + len) % n];
				int cur = mapeo[(a[i] + len) % n];
				new_mapeo[a[i]] = new_mapeo[a[i - 1]] + (pre != cur);
			}
		}
		swap(mapeo, new_mapeo);
		len <<= 1;
	}
	return a;
}
 
const int maxv = 300;

bool valid(int x) {
    return 1 <= x and x <= maxv;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    vi s, init;
    int ind = 0;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;

        init.pb(ind);
        ind += k+1;

        while(k--) {
            int x; cin >> x;
            s.pb(x);
        }

		s.pb(maxv + 1);
    }

	s.pb(0);

    vi a = suffix_array(s);
    vi pos(a.size());


    for(int i = 0; i < ind; i++)
        pos[a[i]] = i;

    set<int> aux;
    for(int x : init) {
        aux.insert(pos[x]);
	}

    vector<ll> res;
    while(!aux.empty()) {
        int id = *aux.begin(); aux.erase(aux.begin());
        int suff = a[id];
        
        res.pb(s[suff]);

        suff++;
        if(valid(s[suff])) {
            aux.insert(pos[suff]);
        }
    }

	//for(int x : res)
		//cout << x << " ";

	//cout << endl;

	reverse(all(res));

	const int maxk = 4e5 + 100;
	const ll mod = 1e9 + 7;
	const ll b = 365;
	ll f[maxk];

	f[0] = 1;

	for(int i = 1; i < maxk; i++)
		f[i] = f[i-1] * b % mod;

	ll ans = 0;

	for(int i = 0; i < (int) res.size(); i++) {
		ans += res[i] * f[i+1];
		ans %= mod;
	}
	
	cout << ans << "\n";
	
    return 0;
}


