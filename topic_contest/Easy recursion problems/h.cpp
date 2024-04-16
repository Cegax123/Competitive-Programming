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

const int maxn = 250;
char b[maxn][maxn];
char c[10][10];
int p[10];
int n, k;

void fill(int stx, int sty, int deep, bool all_black) {
    if(all_black) {
        for(int i = stx; i < stx + p[deep]; i++) {
            for(int j = sty; j < sty + p[deep]; j++) {
                b[i][j] = '*';
            }
        }
    }

    if(deep == 0) return;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int nx = stx + i * p[deep-1], ny = sty + j * p[deep-1];
            bool nxt_black = c[i][j] == '*';
            fill(nx, ny, deep-1, nxt_black);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> n >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            in >> c[i][j];

    p[0] = 1;
    for(int i = 1; i <= k; i++)
        p[i] = p[i-1] * n;

    for(int i = 0; i < p[k]; i++) {
        for(int j = 0; j < p[k]; j++)
            b[i][j] = '.';
    }

    fill(0, 0, k, 0);

    for(int i = 0; i < p[k]; i++) {
        for(int j = 0; j < p[k]; j++)
            out << b[i][j];
        out << "\n";
    }

    in.close();
    out.close();
	
    return 0;
}


