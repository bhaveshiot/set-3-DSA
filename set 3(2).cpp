#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Function to find the OR of all possible subarrays and then the OR of all these OR results
int findORofSubarrayORs(const vector<int>& A) {
    set<int> orResults;  // To store distinct OR results

    int currentOR = 0;   // To keep track of the current OR of subarrays
    
    // Loop through each element in the array
    for (int i = 0; i < A.size(); i++) {
        currentOR = 0;  // Reset the current OR for the new subarray starting at i

        // Generate subarrays starting from index i
        for (int j = i; j < A.size(); j++) {
            // Update the current OR with the j-th element
            currentOR |= A[j];
            orResults.insert(currentOR); // Insert the current OR into the set (duplicates are ignored)
        }
    }

    // Calculate the OR of all distinct OR results
    int finalResult = 0;
    for (int res : orResults) {
        finalResult |= res;
    }

    return finalResult;
}

int main() {
    // Input the array size and the elements of the array
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Get the final OR result and print it
    cout << findORofSubarrayORs(A) << endl;
    
    return 0;
}
