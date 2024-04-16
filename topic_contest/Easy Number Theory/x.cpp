#include <iostream>
#include <vector>
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

const int maxn = 1e6+4;
bool sieve[maxn];
ll phi[maxn];
vi prime;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    phi[1] = 1;

    for(int i = 2; i < maxn; i++) {
        if(!sieve[i]) {
            prime.pb(i);
            phi[i] = i-1;
        }
        for(int j = 0; j < (int) prime.size() and i * prime[j] < maxn; j++) {
            sieve[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }   

    phi[1] = 0;
    
    for(int i = 2; i < maxn; i++)
        phi[i] += phi[i-1];

    int n;
    while(cin >> n and n) {
        cout << phi[n] << "\n";
    }
	
    return 0;
}


