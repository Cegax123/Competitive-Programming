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

int F(int a, int b, int c, int x) {
    int t = 0;
    int L = 0;

    while(t < x) {
        int p = min(a, x-t);
        L += b * p;
        t += a + c;
    }

    return L;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a, b, c, d, e, f, x; cin >> a >> b >> c >> d >> e >> f >> x;
    int L1 = F(a, b, c, x);
    int L2 = F(d, e, f, x);

    if(L1 > L2) 
        cout << "Takahashi\n";
    else if(L1 == L2)
        cout << "Draw\n";
    else 
        cout << "Aoki\n";
   
    return 0;
}


