#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Proc {
    int id;
    int at;     // Arrival Time
    int bt;     // Burst Time
    int rt;     // Remaining Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
};

void getInput(vector<Proc>& p, int& tq) {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    p.clear();
    for (int i = 0; i < n; i++) {
        Proc temp;
        temp.id = i + 1;
        cout << "Arrival Time for P" << temp.id << ": ";
        cin >> temp.at;
        cout << "Burst Time for P" << temp.id << ": ";
        cin >> temp.bt;
        temp.rt = temp.bt;
        p.push_back(temp);
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;
}

void roundRobin(vector<Proc>& p, int tq) {
    int n = p.size();
    queue<int> q;
    vector<bool> in_q(n, false);
    int time = 0, done = 0;

    // Sort by arrival time
    sort(p.begin(), p.end(), [](Proc a, Proc b) {
        return a.at < b.at;
    });

    // Add first process
    q.push(0);
    in_q[0] = true;

    cout << "\nGantt Chart:\n";
    while (!q.empty()) {
        int i = q.front(); q.pop();

        if (p[i].rt > 0) {
            int exec = min(tq, p[i].rt);
            cout << "| P" << p[i].id << " ";
            time = max(time, p[i].at) + exec;
            p[i].rt -= exec;

            // Push any new arriving processes
            for (int j = 0; j < n; j++) {
                if (!in_q[j] && p[j].at <= time && p[j].rt > 0) {
                    q.push(j);
                    in_q[j] = true;
                }
            }

            // Re-push if not done
            if (p[i].rt > 0) {
                q.push(i);
            } else {
                p[i].ct = time;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                done++;
            }
        }
    }
    cout << "|\n";

    float total_tat = 0, total_wt = 0;
    cout << "\nPID\tAT\tBT\tWT\tTAT\n";
    for (auto& x : p) {
        cout << "P" << x.id << "\t" << x.at << "\t" << x.bt << "\t" 
             << x.wt << "\t" << x.tat << "\n";
        total_tat += x.tat;
        total_wt += x.wt;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << "\n";
}

int main() {
    vector<Proc> p;
    int tq, ch;

    while (true) {
        cout << "\n--- Round Robin CPU Scheduling ---\n";
        cout << "1. Enter Process Data\n";
        cout << "2. Run Scheduling\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1: getInput(p, tq); break;
            case 2:
                if (!p.empty())
                    roundRobin(p, tq);
                else
                    cout << "Please input process details first.\n";
                break;
            case 3: cout << "Bye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
