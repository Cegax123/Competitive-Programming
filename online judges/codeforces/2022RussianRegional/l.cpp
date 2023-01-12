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

const int WEEK = 7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k; cin >> n >> m >> k;

    vector<vi> days_of_work(n);
    vector<map<int, int> > current_developers(WEEK);
    vector<set<int>> assigned_projects(n);
    

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        for(int j = 0; j < t; j++) {
            string day; cin >> day;
            if(day == "Monday") days_of_work[i].pb(1);
            if(day == "Tuesday") days_of_work[i].pb(2);
            if(day == "Wednesday") days_of_work[i].pb(3);
            if(day == "Thursday") days_of_work[i].pb(4);
            if(day == "Friday") days_of_work[i].pb(5);
            if(day == "Saturday") days_of_work[i].pb(6);
            if(day == "Sunday") days_of_work[i].pb(0);
        }
    }

    set<int> holidays;

    for(int i = 0; i < m; i++) {
        int h; cin >> h;
        holidays.insert(h);
    }

    vector<vi> assigned_developers(k);

    for(int i = 0; i < k; i++) {
        int p; cin >> p;
        for(int j = 0; j < p; j++) {
            int a; cin >> a; a--;
            assigned_developers[i].pb(a);
        }
        reverse(all(assigned_developers[i]));
    }

    auto add_dev = [&](int dev, int project) {
        for(int d : days_of_work[dev])
            current_developers[d][dev]++;
        assigned_projects[dev].insert(project);
    };

    for(int i = 0; i < k; i++) {
        int dev = assigned_developers[i].back();
        add_dev(dev, i);
    }

    int completed_projects = 0;
    int day = 1;

    int ans[k];

    for(; completed_projects < k; day++) {
        if(holidays.count(day)) continue;
        
        vi process_projects;

        for(auto e : current_developers[day % 7]) {
            int dev = e.first;
            process_projects.pb(*(assigned_projects[dev].begin()));
        }

        for(int project : process_projects) {
            int dev = assigned_developers[project].back(); assigned_developers[project].pop_back();
            assigned_projects[dev].erase(project);

            for(int d : days_of_work[dev]) {
                current_developers[d][dev]--;
                if(current_developers[d][dev] == 0) current_developers[d].erase(dev);
            }

            if(assigned_developers[project].empty()) {
                completed_projects++;
                ans[project] = day;
                continue;
            }

            int new_dev = assigned_developers[project].back();
            add_dev(new_dev, project);
        }
    }

    for(int i = 0; i < k; i++)
        cout << ans[i] << " ";

    return 0;
}


