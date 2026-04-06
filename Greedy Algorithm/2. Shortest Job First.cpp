/**
 * Given a set of processes with their burst times, the task is to find the average waiting time using Shortest Job First (SJF) scheduling.
 * SJF is a Greedy algorithm that selects the process with the smallest burst time from the set of available processes.
 * The average waiting time is calculated as the total waiting time divided by the number of processes.
 * 
 * Example:
 * Input: Burst times = {6, 8, 7, 3}
 * Output: Average waiting time = 5
 * Explanation:
 * The order of execution will be: 3, 6, 7, 8
 * Waiting times for each process: 
 * Process with burst time 3: Waiting time = 0
 * Process with burst time 6: Waiting time = 3
 * Process with burst time 7: Waiting time = 9
 * Process with burst time 8: Waiting time = 16
 * Total waiting time = 0 + 3 + 9 + 16 = 28
 * Average waiting time = Total waiting time / Number of processes = 28 / 4 = 7
 */

#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    int n = bt.size();
    sort(bt.begin(), bt.end());
    long long t = 0, wtTime = 0;
    for (int i = 0; i < n; i++) {
        wtTime += t;
        t += bt[i];
    }
    return (wtTime / n);
}