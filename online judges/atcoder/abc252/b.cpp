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
    int n, k; cin >> n >> k;
    vi a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = *max_element(all(a));
    bool cmp = 0;

    for(int i = 0; i < k; i++) {
        int b; cin >> b;
        b--;

        if(a[b] == x)
            cmp = 1;
    }

    cout << (cmp ? "Yes\n" : "No\n");
   
    return 0;
}


