#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> coins  = {1, 3, 11, 21};   // Bug 1: correct coins
    int maxChange      = 226;
    vector<int> change(maxChange + 1, INT_MAX); // Bug 2: big enough

    change[0] = 0;   // Bug 3: base case — 0 coins needed to make change 0

    for (int i = 0; i <= maxChange; i++) {
        if (change[i] == INT_MAX) continue;
        for (int j = 0; j < (int)coins.size(); j++) {
            if (i + coins[j] > maxChange) continue;  // bounds check
            int x = change[i + coins[j]];
            change[i + coins[j]] = min(change[i] + 1, x); // Bug 4 & 5 fixed
        }                                                  // coins[j] not coins[i]
    }                                                      // change[i]+1 not literal 2

    cout << "Change for 124: " << change[124] << " coins" << endl;
    cout << "Change for 226: " << change[226] << " coins" << endl;
    cout << "Change for 121: " << change[121] << " coins" << endl;

    return 0;
}