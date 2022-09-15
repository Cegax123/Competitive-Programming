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
    int n, w; cin >> n >> w;
    int a[n];

    for(int i = 0; i < n; i++) cin >> a[i];

    set<int> s;

    for(int i = 0; i < n; i++)
        if(a[i] <= w) s.insert(a[i]);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
            if(a[i] + a[j] <= w) s.insert(a[i] + a[j]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(a[i] + a[j] + a[k] <= w) 
                    s.insert(a[i] + a[j] + a[k]);
            }
        }
    }

    cout << s.size() << "\n";
   
    return 0;
}


