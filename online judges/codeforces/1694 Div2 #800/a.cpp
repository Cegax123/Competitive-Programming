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
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        if(a < b) {
            for(int i = 0; i < a; i++)
                cout << "10";
            for(int i = 0; i < b-a; i++)
                cout << "1";
        }
        else {
            for(int i = 0; i < b; i++)
                cout << "01";
            for(int i = 0; i < a-b; i++)
                cout << "0";
        }
        cout << "\n";
    }


    return 0;
}


