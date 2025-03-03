#include "iostream"
using namespace std;

//1
bool myCompare(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}
int max_activities(pair<int, int> arr[], int n) {
    sort(arr, arr + n, myCompare);
    int prev = 0;
    int res = 1; //1st activity is always selected.

    for (int i = 1; i < n; i++) {
        if (arr[i].first > arr[prev].second) {
            res++;
            prev = i;
        }
    }
    return res;
}

//2 => Fractional Knapsack
bool myCompare2(const pair<int, int> &p1, const pair<int, int> &p2) {
    double r1 = static_cast<double>(p1.first) / p1.second;
    double r2 = static_cast<double>(p2.first) / p2.second;
    return r1 > r2;
}
double fractional_knapsack(int W, pair<int, int> arr[], int n) {
    double res = 0.0;
    sort(arr, arr + n, myCompare2);
    for (int i = 0; i < n; i++) {
        if (arr[i].first <= W) {
            res += arr[i].first;
            W -= arr[i].second;
        }
        else {
            res += arr[i].first * (static_cast<double>(W) / arr[i].second);
            break;
        }
    }
    return res;
}

int main() {
    pair<int, int> arr[] = {{1, 3}, {3, 8}, {10, 11}, {2, 4}};
    cout << max_activities(arr, 5) << endl;
}