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
    int w; cin >> w;

    cout << 3 * 99 + 1 << "\n";
    
    cout << 1000000 << " ";

    for(int i = 1; i <= 99; i++) 
        cout << i << " " << i * 100 << " " << i * 10000 << " ";
   
    return 0;
}


