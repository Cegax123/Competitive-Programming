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
    vi a(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    int cntL = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) cntL++;
        else break;
    }

    int cntR = 0;
    for(int i = n-2; i >= 0; i--) {
        if(a[i] > a[i+1]) cntR++;
        else break;
    }

    int indL = 0, indR = n-1;
    int turn = 0;

    string names[2] = {"Alice", "Bob"};

    auto is_even = [] (int x) {
        return 1 - (x&1);
    };

    while(true) {
        if(a[indL] > a[indR]) {
            if(is_even(cntL)) {
                cout << names[turn] << "\n";
                return 0;
            }
        }
        if(a[indL] < a[indR]) {
            if(is_even(cntR)) {
                cout << names[turn] << "\n";
                return 0;
            }
        }
        if(a[indL] == a[indR]) {
            if(is_even(cntL) or is_even(cntR)) {
                cout << names[turn] << "\n";
            }
            else
                cout << names[1-turn] << "\n";
            return 0;
        }

        turn = 1-turn;
        if(a[indL] > a[indR]) {
            indR--;
            cntR--;
        }
        else {
            cntL--;
            indL++;
        }
    }
	
    return 0;
}


