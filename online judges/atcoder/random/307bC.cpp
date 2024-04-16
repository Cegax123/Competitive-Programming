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

bool paste(vector<vi> from, vector<vi>& to, int x, int y) {
    int used = 0;
    int cnt = 0;

    for(int i = 0; i < (int) from.size(); i++) {
        for(int j = 0; j < (int) from[0].size(); j++) {
            cnt += from[i][j];
            int pi = i+x, pj = j+y;

            if(pi >= 0 and pi < (int) to.size() and pj >= 0 and pj < (int) to[0].size()) {
                if(from[i][j]) {
                    used++;
                    to[pi][pj] = 1;
                }
            }
        }
    }

    return used == cnt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ha, wa; cin >> ha >> wa;
    vector<vi> A(ha, vi(wa, 0));

    for(int i = 0; i < ha; i++) {
        for(int j = 0; j < wa; j++) {
            char c; cin >> c;
            if(c == '#') A[i][j] = 1;
        }
    }
    
    int hb, wb; cin >> hb >> wb;
    vector<vi> B(hb, vi(wb, 0));

    for(int i = 0; i < hb; i++) {
        for(int j = 0; j < wb; j++) {
            char c; cin >> c;
            if(c == '#') B[i][j] = 1;
        }
    }

    int hc, wc; cin >> hc >> wc;
    vector<vi> C(hc, vi(wc, 0));

	for(int i = 0; i < hc; i++) {
        for(int j = 0; j < wc; j++) {
            char c; cin >> c;
            if(c == '#') C[i][j] = 1;
        }
    }

    vector<vi> D(hc, vi(wc, 0));

    paste(A, D, 1, 0);

    bool cmp = false;
    for(int i = -15; i <= 15; i++) {
        for(int j = -15; j <= 15; j++) {
            for(int t = -15; t <= 15; t++) {
                for(int k = -15; k <= 15; k++) {
                    vector<vi> D(hc, vi(wc, 0));

                    bool ans1 = paste(A, D, i, j);
                    bool ans2 = paste(B, D, t, k);

                    if(D == C and ans1 and ans2) cmp = true;
                }
            }
        }
    }

    cout << (cmp ? "Yes\n" : "No\n");

    return 0;
}


