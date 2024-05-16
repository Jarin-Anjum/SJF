#include <iostream>
using namespace std;

void sortProcesses(int n, int pid[], int burst_time[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {

                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;


                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
}

void calculateWaitingTime(int n, int burst_time[], int waiting_time[]) {
    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
}

void calculateTurnaroundTime(int n, int burst_time[], int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void printTimes(int n, int pid[], int burst_time[], int waiting_time[], int turnaround_time[]) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    cout << "PID\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        cout << pid[i] << "\t" << burst_time[i] << "\t" << waiting_time[i] << "\t" << turnaround_time[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_waiting_time / n << endl;
    cout << "Average turnaround time = " << (float)total_turnaround_time / n << endl;
}

int main() {
    int n = 4;
    int pid[] = {1, 2, 3, 4};
    int burst_time[] = {6, 8, 7, 3};
    int waiting_time[4], turnaround_time[4];

    sortProcesses(n, pid, burst_time);

    calculateWaitingTime(n, burst_time, waiting_time);
    calculateTurnaroundTime(n, burst_time, waiting_time, turnaround_time);
    printTimes(n, pid, burst_time, waiting_time, turnaround_time);

    return 0;
}
