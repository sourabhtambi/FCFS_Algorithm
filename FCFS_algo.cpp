#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

bool compareArrival(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input process data
    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID, Arrival Time, Burst Time for process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].arrival_time >> processes[i].burst_time;
    }

    // Sort by arrival time (FCFS)
    sort(processes.begin(), processes.end(), compareArrival);

    int current_time = 0;
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;

        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        current_time = processes[i].completion_time;

        total_tat += processes[i].turnaround_time;
        total_wt += processes[i].waiting_time;
    }

    // Output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t"
             << processes[i].arrival_time << "\t"
             << processes[i].burst_time << "\t"
             << processes[i].completion_time << "\t"
             << processes[i].turnaround_time << "\t"
             << processes[i].waiting_time << "\n";
    }

    cout << "\nAverage Turnaround Time: " << total_tat / n;
    cout << "\nAverage Waiting Time: " << total_wt / n << endl;

    return 0;
}
