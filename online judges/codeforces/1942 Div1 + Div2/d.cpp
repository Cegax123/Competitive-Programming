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
        int n, k; cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<int>> best0(n, vector<int>(k, -1e9));
        vector<vector<int>> best1(n, vector<int>(k, -1e9));

        best1[0][0] = a[0][0];
        best0[0][0] = 0;

        for(int i = 1; i < n; i++) {
            priority_queue<ii> pq;

            vector<int> ind(i, 0);
            for(int j = 0; j < i; j++) {
                pq.push({best0[j][ind[j]] + a[j+1][i], j});
                ind[j]++;
            }

            pq.push({a[0][i], -1});

            for(int j = 0; j < k; j++) {
                auto e = pq.top(); pq.pop();
                best1[i][j] = max(e.first, best1[i][j]); 

                int pos = e.second;
                
                if(pos >= 0 and ind[pos] < k) {
                    pq.push({best0[pos][ind[pos]] + a[pos+1][i], pos});
                    ind[pos]++;
                }
            }

            while(!pq.empty()) pq.pop();

            for(int j = 0; j < k; j++) {
                pq.push({best0[i-1][j], -1});
                pq.push({best1[i-1][j], -1});
            }

            for(int j = 0; j < k; j++) {
                auto e = pq.top(); pq.pop();
                best0[i][j] = max(e.first, best0[i][j]);
            }

        }

        priority_queue<int> pq;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                pq.push(best1[i][j]);
            }
        }
        pq.push(0);

        for(int i = 0; i < k; i++) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << "\n";
        
    }

	
    return 0;
}


