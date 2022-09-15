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
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<bool> vis(n+1, 0);
		vi p(n+1);

		int response;
		int q = 0;
		
		printf("? 1\n");
		printf("\n");
		fflush(stdout);

		q++;

		scanf("%d", &response);

		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;

			vi lst;
			response = -1;
			bool to_cont = false;

			while(true) {
				printf("? %d\n", i);
				printf("\n");
				fflush(stdout);

				scanf("%d", &response);

				q++;

				if(response == 1 and q == 2) {
					p[1] = 1;
					to_cont = true;
					break;
				}

				if(lst.empty() or lst[0] != response) lst.pb(response);
				else break;
			}

			if(to_cont) continue;

			int k = lst.size();
			for(int i = 0; i < k; i++) {
				p[lst[i]] = lst[(i+1)%k];	
				vis[lst[i]] = true;
			}
		}

		printf("! ");
		for(int i = 1; i <= n; i++)
			printf("%d ", p[i]);
		printf("\n");
		printf("\n");

		fflush(stdout);
	}
	
	return 0;
}

