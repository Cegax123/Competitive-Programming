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

const int maxn = 20;
int n, k;
int a[maxn];
bool banned[maxn];
vi curr;

void backtrack(int pos = 0) {
    if(pos == k) {
        cout << "{";
        for(int i = 0; i < (int) curr.size()-1; i++)
            cout << curr[i] << ",";

        if(!curr.empty()) cout << curr.back();

        cout << "}\n";

        return;
    }

    int st = 0;

    for(int i = 0; i < n; i++)
        if(banned[i]) st = i+1;

    for(int i = st; i < n; i++) {
        if(banned[i]) break;
        banned[i] = 1;
        curr.pb(a[i]);
        
        backtrack(pos+1);
        
        banned[i] = 0;
        curr.pop_back();
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);

        backtrack();
        cout << "---\n";
    }

	
    return 0;
}


