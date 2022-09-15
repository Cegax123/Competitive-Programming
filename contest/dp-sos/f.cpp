// SOLVED

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

const int L = 24;

void print_mask(int mask) {
    for(int i = 0; i < L; i++) {
        cout << (mask&1);
        mask >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vi f1(1 << L, 0), f2(1 << L, 0), f3(1 << L, 0);

    // vi sav;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;

        set<int> se;

        for(char c : s) {
            int x = c-'a';
            se.insert(x);
        }

        vi tmp;

        for(int x : se)
            tmp.pb(x);

        int k = tmp.size();

        for(int a = 0; a < k; a++) {
            int x = tmp[a];
            f1[1 << x]++;
        }

        for(int a = 0; a < k; a++) {
            for(int b = a+1; b < k; b++) {
                int x = tmp[a], y = tmp[b];
                f2[(1 << x) | (1 << y)]++;
            }
        }

        for(int a = 0; a < k; a++) {
            for(int b = a+1; b < k; b++) {
                for(int c = b+1; c < k; c++) {
                    int x = tmp[a], y = tmp[b], z = tmp[c];
                    f3[(1 << x) | (1 << y) | (1<< z)]++;
                }
            }
        }

        // int num = 0;
        //
        // for(int x : tmp)
        //     num |= (1 << x);
        //
        // sav.pb(num);
    }

    for(int i = 0; i < L; i++) {
        for(int mask = 0; mask < (1 << L); mask++) {
            if(mask & (1 << i)) {
                f1[mask] += f1[mask ^ (1 << i)];
                f2[mask] += f2[mask ^ (1 << i)];
                f3[mask] += f3[mask ^ (1 << i)];
            }
        }
    }

    int ans = 0;
    for(int mask = 0; mask < (1 << L); mask++) {
        f1[mask] -= f2[mask];
        f1[mask] += f3[mask];

        ans ^= (f1[mask] * f1[mask]);
    }

    // for(int mask = 0; mask < (1 << L); mask++) {
    //     vector<bool> used(n, 0);
    //
    //     for(int j = 0; j < L; j++) {
    //         if(((mask >> j)&1) == 0) continue;
    //         int x = 1 << j;
    //
    //         for(int i = 0; i < n; i++) {
    //             if((x&sav[i]) == x)
    //                 used[i] = 1;
    //         }
    //     }
    //
    //     int cnt = 0;
    //
    //     for(int i = 0; i < n; i++)
    //         cnt += used[i];
    //
    //     if(f1[mask] != cnt) {
    //         print_mask(mask);
    //         cout << " " << f1[mask] << " " << cnt << "\n";
    //     }
    // }

    cout << ans << "\n";
    	
	return 0;
}


