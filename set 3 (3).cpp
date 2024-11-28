#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& arr, int K) {
    deque<int> dq;  // Deque to store indices of potential maximum elements
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Remove elements from the front of the deque if they are out of the current window
        if (!dq.empty() && dq.front() < i - K + 1) {
            dq.pop_front();
        }

        // Remove elements from the back of the deque if they are smaller than the current element
        // because they will not be the maximum for future windows
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the deque
        dq.push_back(i);

        // Once we've processed at least K elements, the front of the deque will be the maximum
        // for the current window, so we add it to the result
        if (i >= K - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    // Input the array and the size of the subarray
    vector<int> arr = {1, 2, 3, 1, 4, 5};
    int K = 3;

    vector<int> result = maxSlidingWindow(arr, K);

    // Output the results
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
