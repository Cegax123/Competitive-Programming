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
    int n; cin >> n;

    int a; cin >> a;
    cout << a << " ";

    int last = a;

    for(int i = 1; i < n; i++) {
        cin >> a;

            if(last < a) {
                for(int j = last+1; j <= a-1; j++)
                    cout << j << " ";
            }
            else {
                for(int j = last-1; j >= a+1; j--)
                    cout << j << " ";
            }
        cout << a << " ";
        last = a;
    }

	
    return 0;
}


