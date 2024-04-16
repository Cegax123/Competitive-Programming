#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 26e6;
const int L = 71;
int d[maxn];
bool used[L];

int main() {
    int p[4] = {1, L, L * L, L * L * L};

    int st = 0;
    st = p[3] * 4 + p[2] * 3 + p[1] * 2 + p[0] * 1;

    queue<vector<int>> q;
    q.push({1, 2, 3, 4});

    while(!q.empty()) {
        vector<int> v = q.front(); q.pop();

        int numv = 0;
        for(int j = 0; j < 4; j++) {
            numv += p[j] * v[j];
        }

        for(int p : v) used[p] = 1;
        
        for(int i = 0; i < 4; i++) {
            vector<int> tv = v;
            if(v[i] + 1 < L and !used[v[i]+1]) {
                tv.erase(tv.begin() + i);
                tv.push_back(v[i] + 1);

                sort(tv.begin(), tv.end());
                int num = 0;

                for(int j = 0; j < 4; j++) {
                    num += p[j] * tv[j];
                }

                if(num != st and d[num] == 0) {
                    d[num] = d[numv] + 1;
                    q.push(tv);
                }
            }

            if(v[i]-1 >= 1 and !used[v[i]-1]) {
                tv.erase(tv.begin() + i);
                tv.push_back(v[i] - 1);

                sort(tv.begin(), tv.end());
                int num = 0;

                for(int j = 0; j < 4; j++) {
                    num += p[j] * tv[j];
                }

                if(num != st and d[num] == 0) {
                    d[num] = d[numv] + 1;
                    q.push(tv);
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            for(int j = i+1; j < 4; j++) {
                int p1 = v[i], p2 = v[j];

                int k = 2 * p2 - p1;
                if(k >= 1 and k < L and !used[k]) {
                    vector<int> tv = v;
                    tv.erase(tv.begin()+i);
                    tv.push_back(k);

                    sort(tv.begin(), tv.end());
                    int num = 0;

                    for(int j = 0; j < 4; j++) {
                        num += p[j] * tv[j];
                    }

                    if(num != st and d[num] == 0) {
                        d[num] = d[numv] + 1;
                        q.push(tv);
                    }
                }

                k = 2 * p1 - p2;
                if(k >= 1 and k < L and !used[k]) {
                    vector<int> tv = v;
                    tv.erase(tv.begin()+j);
                    tv.push_back(k);

                    sort(tv.begin(), tv.end());
                    int num = 0;

                    for(int j = 0; j < 4; j++) {
                        num += p[j] * tv[j];
                    }

                    if(num != st and d[num] == 0) {
                        d[num] = d[numv] + 1;
                        q.push(tv);
                    }
                }
            }
        }

        for(int p : v) {
            used[p] = 0;
        }
    }

    int t; cin >> t;
    while(t--) {
        int x = 0;

        for(int i = 0; i < 4; i++) {
            int y; cin >> y;
            x += y * p[i];
        }

        cout << d[x] << "\n";
    }
       
    return 0;
}
