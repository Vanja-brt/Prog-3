#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void inc_coin(int coin, vector<pair<int, int>> &s) {
    for (auto &p : s) {        // MUST be reference
        if (p.first == coin) {
            p.second++;
            return;
        }
    }
}

bool isEqual(vector<pair<int,int>> &a, vector<pair<int,int>> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].second != b[i].second) return false;
    }
    return true;
}
vector<vector<pair<int, int>>> coins_change(int change, vector<int> &coins)
{
    vector<vector<pair<int, int>>> sol;

    vector<pair<int, int>> zero;
    for (int c : coins) {
        zero.push_back({c, 0});
    }

    if (change == 0) {
        sol.push_back(zero);
    } else {
        for (int c : coins) {
            if (change - c >= 0) {
                auto sub = coins_change(change - c, coins);
                for (auto ss : sub) {
                    inc_coin(c, ss);
                    sol.push_back(ss);
                }
            }
        }
    }
    return sol;
}
void filter_duplicates(vector<vector<pair<int, int>>> &solutions) {
    vector<vector<pair<int, int>>> unique;

    for (auto &s : solutions) {
        bool found = false;
        for (auto &u : unique) {
            if (isEqual(s, u)) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique.push_back(s);
        }
    }
    solutions = unique;
}
int count_coins(vector<pair<int,int>> &s) {
    int total = 0;
    for (auto &p : s) total += p.second;
    return total;
}

int main() {
    int change;
    vector<int> coins = {1,2,5};
    cout << "Enter change sum: ";
    cin >> change;
    auto solutions = coins_change(change, coins);
    filter_duplicates(solutions);
    int best = 1e9;
    vector<pair<int,int>> best_sol;
    for (auto &s : solutions) {
        int cnt = count_coins(s);
        if (cnt < best) {
            best = cnt;
            best_sol = s;
        }
    }
    cout << "\nOptimal solution (" << best << " coins):\n";
    for (auto &p : best_sol) {
        cout << "<" << p.first << "," << p.second << "> ";
    }
    cout << endl;
    return 0;
}