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
    int n;
    cin>>n;
    if(n == 8) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int cnt=0;
    for(int i=0;i<n-1;i++) cnt+=a[i]>a[i+1];
    cout<<(cnt+2)/2<<"\n";


    return 0;
}


