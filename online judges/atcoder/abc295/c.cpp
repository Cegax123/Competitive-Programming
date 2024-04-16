#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define all(c) (c).begin(), (c).end()

int main() {
    int n; cin >> n;
    map<int, int> cnt;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    int ans = 0;
    for(auto e : cnt) {
        ans += e.second/2;
    }

    cout << ans << "\n";

    return 0;
}
