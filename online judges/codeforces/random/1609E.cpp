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

struct Node {
	int a, b, c, ab, bc, abc;
	Node() {
		a = b = c = ab = bc = abc = 0;
	}
	Node(char x) {
		a = b = c = ab = bc = abc = 0;
		if(x=='a') a++;
		if(x=='b') b++;
		if(x=='c') c++;
	}
};

Node combine(const Node& n1, const Node& n2) {
	Node res;
	res.a = n1.a + n2.a;
	res.b = n1.b + n2.b;
	res.c = n1.c + n2.c;

	res.ab = min(n1.ab+n2.b, n1.a+n2.ab);
	res.bc = min(n1.bc+n2.c, n1.b+n2.bc);

	res.abc = min({n1.a+n2.abc, n1.ab+n2.bc, n1.abc+n2.c});
	return res;
}

const int maxn = 1e5+5;

Node t[4*maxn];
string s;

void build(int v, int tl, int tr) {
	if(tl == tr) {
		t[v] = Node(s[tl]);
	}
	else {
		int tm = (tl+tr)/2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);

		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

void update(int v, int tl, int tr, int pos) {
	if(tl == tr) {
		t[v] = Node(s[pos]);
	}
	else {
		int tm = (tl+tr)>>1;
		if(pos <= tm) update(2*v, tl, tm, pos);
		else update(2*v+1, tm+1, tr, pos);

		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q; cin >> n >> q;
	cin >> s;

	build(1, 0, n-1);
	for(int l = 0; l < q; l++) {
		int pos; char c; cin >> pos >> c;
		pos--;

		s[pos] = c;

		update(1, 0, n-1, pos);
		cout << t[1].abc << "\n";
	}
	
	
	return 0;
}
