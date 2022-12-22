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
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int nxt[n], bef[n];

    nxt[n-1] = n;

    for(int i = n-2; i >= 0; i--) {
        if(a[i+1]) nxt[i] = i+1;
        else nxt[i] = nxt[i+1];
    }

    bef[0] = -1;

    for(int i = 1; i < n; i++) {
        if(a[i-1]) bef[i] = i-1;
        else bef[i] = bef[i-1];
    }

    int L[n];
    int last1 = -1, last2 = -1, last3 = -1;
    int last12 = -1, last21 = -1;

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            L[i] = 0;
        }
        else if(a[i] == 3) {
            L[i] = bef[i]+1;
            last3 = i;
        }
        else if(a[i] == 1) {
            if(bef[i] == -1) {
                L[i] = 0;
            }
            else if(last3 == -1) {
                L[i] = last1+1;
            } 
            else if(a[bef[i]] == 3) {
                L[i] = bef[i]+1;
            }
            else if(a[nxt[last3]] == 1) {
                L[i] = last1+1;
            }
            else {
                if(last21 >= nxt[last3]) L[i] = last1+1;
                else L[i] = last21+1;
            }

            last1 = i;
            if(bef[i] != -1 and a[bef[i]] == 2) last21 = bef[i];
        }
        else {
            if(bef[i] == -1) {
                L[i] = 0;
            }
            else if(last3 == -1) {
                L[i] = last2+1;
            } 
            else if(a[bef[i]] == 3) {
                L[i] = bef[i]+1;
            }
            else if(a[nxt[last3]] == 2) {
                L[i] = last2+1;
            }
            else {
                if(last12 >= nxt[last3]) L[i] = last2+1;
                else L[i] = last12+1;
            }

            last2 = i;
            if(bef[i] != -1 and a[bef[i]] == 1) last12 = bef[i];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (i-L[i]+1) * 1ll * (n-i);
        cout << L[i] << " ";
    }
    cout << endl;

    cout << ans << "\n";

    int cnt = 0;

    auto f = [&](int i, int j) {
        vi last;

        for(int k = i; k <= j; k++) {
            bool found = false;
            for(int m = 0; m < (int) last.size(); m++) {
                if(last[m]&a[k]) {
                    last[m] = a[k];
                    found = true;
                    break;
                }
            }
            if(!found) {
                last.pb(a[k]);
                if(k == 43) {
                    cnt++;
                    cout << i << " ";
                }
            }
        }

        return last.size();
    };

    ll ans2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ans2 += f(i, j);
        }
    }


    cout << cnt << endl;
    cout << ans2 << "\n";
	
    return 0;
}


