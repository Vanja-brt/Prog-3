#include <iostream>
#include <vector>

using namespace std;

struct Result {
    int sum;
    int left;
    int right;
};

Result max_result(Result a, Result b, Result c) {
    Result best = a;
    if (b.sum > best.sum)
        best = b;
    if (c.sum > best.sum)
        best = c;
    return best;
}

Result max_crossing_sum(vector<int> &arr, int left, int mid, int right) {
    int sum = 0;
    int best_left_sum = -1000000000;
    int best_left_index = mid;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > best_left_sum) {
            best_left_sum = sum;
            best_left_index = i;
        }
    }
    sum = 0;
    int best_right_sum = -1000000000;
    int best_right_index = mid + 1;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > best_right_sum) {
            best_right_sum = sum;
            best_right_index = i;
        }
    }
    Result res;
    res.sum = best_left_sum + best_right_sum;
    res.left = best_left_index;
    res.right = best_right_index;
    return res;
}

Result max_subarray(vector<int> &arr, int left, int right) {
    if (left == right) {
        Result base;
        base.sum = arr[left];
        base.left = left;
        base.right = left;
        return base;
    }
    int mid = (left + right) / 2;
    Result left_res = max_subarray(arr, left, mid);
    Result right_res = max_subarray(arr, mid + 1, right);
    Result cross_res = max_crossing_sum(arr, left, mid, right);
    return max_result(left_res, right_res, cross_res);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Result result = max_subarray(arr, 0, n - 1);
    cout << result.sum << endl;
    cout <<  result.left << endl;
    cout <<  result.right << endl;

    return 0;
}
