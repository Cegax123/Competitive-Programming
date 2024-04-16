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
        int a, b, c; cin >> a >> b >> c;

        vector<int> v;
        for(int i = 0; i < c; i++) v.push_back(0);
        for(int i = 0; i < b; i++) v.push_back(1);
        for(int i = 0; i < a; i++) v.push_back(2);


        queue<pair<int, int>> q;
        q.push({v.back(), 0});
        v.pop_back();

        int h = 0;
        bool cmp = true;

        while(!q.empty()) {
            auto e = q.front(); q.pop();
            int num_son = e.first, height = e.second;

            h = max(h, height);

            if((int) v.size() < num_son) {
                cmp = false;
                break;
            }

            while(num_son) {
                int x = v.back();
                q.push({x, height+1});
                v.pop_back();
                num_son--;
            }
        }

        if(!v.empty()) cmp = false;

        cout << (cmp ? h : -1) << "\n";
    }

	
    return 0;
}


