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

const int x = 5;

int n;
string s;

struct Node {
	int ans[16];
	Node() {
		memset(ans, 0, sizeof(ans));
	}
	Node(char c) {
		memset(ans, 0, sizeof(ans));
		if(c == '2') ans[1 << 3] = 1;
		if(c == '0') ans[1 << 2] = 1;
		if(c == '1') ans[1 << 1] = 1;
		if(c == '6') ans[1 << 0] = 1;
	}
};

Node combine(const Node& a, const Node& b) {
	Node x = Node();

	for(int i = 0; i < 4; i++) 
		x.ans[1 << i] = a.ans[1 << i] + b.ans[1 << i];

	x.ans[12] = min(a.ans[8] + b.ans[12], a.ans[12] + b.ans[4]);
	x.ans[6] = min(a.ans[6] + b.ans[2], a.ans[4] + b.ans[6]);
	x.ans[3] = min(a.ans[3] + b.ans[1], a.ans[2] + b.ans[3]);
	
	x.ans[14] = min({a.ans[8] + b.ans[14], a.ans[12] + b.ans[6], a.ans[14] + b.ans[2]});
	x.ans[7] = min({a.ans[4] + b.ans[7], a.ans[6] + b.ans[3], a.ans[7] + b.ans[1]});

	x.ans[15] = min({a.ans[8]+b.ans[15], a.ans[12]+b.ans[7], a.ans[14]+b.ans[3], a.ans[15]+b.ans[1]});

	return x;
}

const int maxn = 2e5+5;
Node t[4*maxn];

void build(int v, int tl, int tr) {
	if(tl == tr) {
		t[v] = Node(s[tl]);
	}
	else {
		int tm = (tl+tr)>>1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);

		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if(tl > r or tr < l) 
		return Node();
	
	if(tl == l and tr == r) 
		return t[v];
	else {
		int tm = (tl+tr)>>1;
		return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(tm+1, l), r));
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q; cin >> n >> q;
	cin >> s;

	build(1, 0, n-1);

	vector<vi> nxt(n+5, vi(10, -1));

	for(int i = 0; i < n; i++) {
		if(i) nxt[i] = nxt[i-1];
		nxt[i][s[i]-'0'] = i;
	}

	while(q--) {
		int l, r; cin >> l >> r;
		l--; r--;
		
		int p2017, p201, p20, p2;

		p2017 = nxt[r][7];
		p201 = p2017 == -1 ? -1 : nxt[p2017][1];
		p20 = p201 == -1 ? -1 : nxt[p201][0];
		p2 = p20 == -1 ? -1 : nxt[p20][2];

		if(p2 < l) {
			cout << "-1\n";
			continue;
		}

		Node x1 = query(1, 0, n-1, l, p2);
		Node x2 = query(1, 0, n-1, p2, p20);
		Node x3 = query(1, 0, n-1, p20, p201);
		Node x4 = query(1, 0, n-1, p201, r);
	
		int ans = min({x1.ans[15]+x2.ans[1]+x3.ans[1],
					   x1.ans[14]+x2.ans[3]+x3.ans[1],
					   x1.ans[14]+x2.ans[2]+x3.ans[3],
					   x1.ans[12]+x2.ans[7]+x3.ans[1],
					   x1.ans[12]+x2.ans[6]+x3.ans[3]})+x4.ans[1];
		
		cout << ans << "\n";
	}
	
	// hola
	return 0;
}
