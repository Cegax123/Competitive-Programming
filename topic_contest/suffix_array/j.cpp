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

int n; // tamaño del string sin el empty character

vi p, lcp;
const int maxn = 1e5+500;
const int LOGN = 20;

int ST[maxn][LOGN];

int f(int a, int b) {return min(a,b);}

void STBuild() {
    for(int i = 1; i <= n; i++) 
        ST[i][0] = lcp[i-1];

    for(int k = 1; (1 << k) <= n; k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= n; i++)
            ST[i][k] = f(ST[i][k-1], ST[i+dis][k-1]);
    }
}

int STQuery(int L, int R) {
    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(ST[L][k], ST[R-dis+1][k]);
}

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
 
vector<int> lcp_array(vector<int> &s, vector<int> &a){
	int n = s.size();
	vector<int> rank(n);
	for(int i = 0; i < n; i++) rank[a[i]] = i;
	int k = 0;
	vector<int> lcp(n - 1);
	for(int i = 0; i < n; i++){
		if(rank[i] + 1 == n){
			k = 0;
			continue;
		}
		int j = a[rank[i] + 1];
		while(i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
		lcp[rank[i]] = k;
		if(k) k--;
	}
	return lcp;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    bool f = 1;

	int t;
	while(cin >> t and t) {
		if(not f) cout << "\n";
		f = 0;

		vector<string> s(t);
		string tot;

		for(int i = 0; i < t; i++) {
			cin >> s[i];
			tot += s[i];
			tot += '#';
		}

		if(t == 1) {
			cout << s[0] << "\n";
			continue;
		}

		vi vs, id;
		int ind = 30;

		for(int i = 0; i < t; i++) {
			for(int j = 0; j < (int) s[i].size(); j++) {
				char c = s[i][j];

				vs.pb(c-'a'+1);
				id.pb(i);
			}
			if(i == t-1) vs.pb(0);
			else vs.pb(ind++);

			id.pb(-1);
		}

		n = vs.size()-1;
		
		p = suffix_array(vs), lcp = lcp_array(vs, p);

		STBuild();

		int curr_diff = 0;
		vi cnt(t, 0);
		int r = 0;

		int ans = 0;
		vi v;

		for(int i = 0; i <= n; i++) {
			while(r <= n and curr_diff <= t/2) {
				if(id[p[r]] != -1) {
					if(cnt[id[p[r]]] == 0) curr_diff++;
					cnt[id[p[r]]]++;
				}
				r++;
			}

			if(i+1 < r and curr_diff > t/2) {
				int curr_ans = STQuery(i, r-2);
				

				if(curr_ans > ans) {
					ans = curr_ans;
					v.clear();
					v.pb(i);
				}

				else if(curr_ans == ans and curr_ans) {
					int prev_pos = v.back();

					if(STQuery(prev_pos, r-2) != curr_ans)
						v.pb(i);
				}
			}

			if(id[p[i]] != -1) {
				cnt[id[p[i]]]--;
				if(cnt[id[p[i]]] == 0) curr_diff--;
			}
		}

		if(ans == 0) {
			cout << "?\n";
			continue;
		}

		for(int i = 0; i < (int) v.size(); i++) {
			int st = p[v[i]];

			for(int j = 0; j < ans; j++) {
				char c = vs[st+j]-1+'a';
				cout << c;
			}

			cout << "\n"; 
		}
	}
	
    return 0;
}
