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
    int n, m, k; cin >> n >> m >> k;
    
    map<string, int> day_to_number;
    day_to_number["Monday"] = 1;
    day_to_number["Tuesday"] = 2;
    day_to_number["Wednesday"] = 3;
    day_to_number["Thursday"] = 4;
    day_to_number["Friday"] = 5;
    day_to_number["Saturday"] = 6;
    day_to_number["Sunday"] = 7;

    vector<vi> work_days(n);

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        for(int j = 0; j < t; j++) {
            string day; cin >> day;
            work_days[i].pb(day_to_number[day]);
        }
    }

    vi h(m);
    set<int> sh;

    for(int i = 0; i < m; i++) {
        cin >> h[i];
        sh.insert(h[i]);
    }

    map<int, int> next_possible_day;

    for(int i = m-1; i >= 0; i--) {
        if(sh.count(h[i] + 7)) next_possible_day[h[i]] = next_possible_day[h[i]+7];
        else next_possible_day[h[i]] = h[i] + 7;
    }

    auto get_nxt_work_day = [&] (int worker, int curr_day) {
        int min_day = -1;

        int week_day = curr_day % 7;

        if(week_day == 0 and curr_day) week_day += 7;

        for(int t : work_days[worker]) {
            int x = curr_day + t - week_day;
            if(t <= week_day) x += 7;

            if(sh.count(x)) x = next_possible_day[x];

            if(min_day == -1 or min_day > x) min_day = x;
        }

        return min_day;
    };

    vector<vi> tasks(k);

    for(int i = 0; i < k; i++) {
        int p; cin >> p;
        for(int j = 0; j < p; j++) {
            int a; cin >> a; a--;
            tasks[i].pb(p);
        }

        reverse(all(tasks[i]));
    }

    vi curr_task_day(k, 0), curr_worker_time(n, 0);
    vector<set<int>> worker_time(n);
    vector<set<ii>> worker_tasks(n);
    set<ii> curr_possible_worker;

    auto insert_worker_by_task = [&](int worker, int task) {
        int nxt_day = get_nxt_work_day(worker, last_task_day[task]);

        if(nxt_day <= curr_worker_time[worker]) {
            worker_time[worker].insert(task);
        }
        else {
            if(last_worker_time.empty()) {
                curr_worker_time[worker] = nxt_day;
                worker_time[worker].insert(task);
            }
            else {
                worker_tasks[worker].insert({nxt_day, task});
            }
        }
    };

    auto process_worker = [&](int worker) {
        if(wor
    };
	
    return 0;
}


