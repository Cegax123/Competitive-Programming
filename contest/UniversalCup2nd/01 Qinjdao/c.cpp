#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<string, pair<int, int>>> ins(n);

        for(int i = 0; i < n; i++) {
            string op; cin >> op;
            ins[i].first = op;
            if(op == "add") {
                int x; cin >> x;
                ins[i].second.first = x;
            }
            else {
                int v, k; cin >> v >> k;
                k--;
                ins[i].second.first = v;
                ins[i].second.second = k;
            }
        }

        int curr = 0;
        int r = 0;
        bool cmp = false;
        for(int i = 0; i < 500 * n; i++) {
            int nxt = curr+1;

            if(ins[curr].first == "add") {
                r += ins[curr].second.first;
                r %= 256;
            }
            else {
                int v = ins[curr].second.first;
                int k = ins[curr].second.second;
                if(ins[curr].first == "beq") {
                    if(r == v) nxt = k;
                }
                else if(ins[curr].first == "bne") {
                    if(r != v) nxt = k;
                }
                else if(ins[curr].first == "blt") {
                    if(r < v) nxt = k;
                }
                else if(ins[curr].first == "bgt") {
                    if(r > v) nxt = k;
                }
            }

            curr = nxt;
            if(curr >= n) {
                cmp = true;
                break;
            }
        }

        cout << (cmp ? "Yes\n" : "No\n");
    }   


    return 0;
}
