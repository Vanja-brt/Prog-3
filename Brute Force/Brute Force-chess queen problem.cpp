#include <iostream>
#include <vector>

using namespace std;

int my_abs(int x) {
    if (x < 0) return -x;
    return x;
}

bool is_safe(vector<int> &pos, int current_row, int column) {
    for (int i = 0; i < current_row; i++) {
        if (pos[i] == column)
            return false;
        if (my_abs(i - current_row) == my_abs(pos[i] - column))
            return false;
    }
    return true;
}

void solve(int row, int n, vector<int> &pos, int &count) {
    if (row == n) {
        count++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (is_safe(pos, row, col)) {
            pos[row] = col;
            solve(row + 1, n, pos, count);
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> pos(n);
    int count = 0;
    solve(0, n, pos, count);
    cout << "Number of solutions: " << count << endl;
    return 0;
}
