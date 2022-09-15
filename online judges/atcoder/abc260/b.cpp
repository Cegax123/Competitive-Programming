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

struct X {
    int a, b, id;
};

bool cmp1(const X& a, const X& b) {
    return a.a < b.a or (a.a == b.a and a.id > b.id);
}

bool cmp2(const X& a, const X& b) {
    return a.b < b.b or (a.b == b.b and a.id > b.id);
}

bool cmp3(const X& a, const X& b) {
    return a.a + a.b < b.a + b.b or (a.a + a.b == b.a + b.b and a.id > b.id);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<X> a(n);
    vi ans;

    for(int i = 0; i < n; i++) {
        cin >> a[i].a;
        a[i].id = i;
    }

    for(int i = 0; i < n; i++)
        cin >> a[i].b;

    sort(all(a), cmp1);

    for(int i = 0; i < x; i++) {
        ans.pb(a.back().id + 1);
        a.pop_back();
    }

    sort(all(a), cmp2);

    for(int i = 0; i < y; i++) {
        ans.pb(a.back().id + 1);
        a.pop_back();
    }

    sort(all(a), cmp3);
	
    for(int i = 0; i < z; i++) {
        ans.pb(a.back().id + 1);
        a.pop_back();
    }

    sort(all(ans));

    for(int x : ans)
        cout << x << "\n";

    return 0;
}


