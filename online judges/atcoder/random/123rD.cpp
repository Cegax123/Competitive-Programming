#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    long long t = 0;
    priority_queue<long long> pq;

    for(int i = 0; i < n; i++) {
        t += max(0, a[i] - (i == 0 ? 0 : a[i-1]));

        pq.push(-t);
        pq.push(-t);
        pq.push(a[i]-t);
        pq.push(a[i]-t);

        long long opt = pq.top();

        //ans += abs(a[i]);
        //ans += 2 * (opt + t - max(0, a[i]));

        ans += abs(opt + t);
        ans += abs(a[i] - (opt + t));

        //cout << opt+t << " " << ans << endl;

        pq.pop();
        pq.pop();
    }

    cout << ans << "\n";

    return 0;
}
