#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

// This is the code that should be generated using the Copilot prompt
vector<vector<int>> question_one(const vector<vector<int>>& parcels) {
    unordered_map<int, pair<int, int>> parcel_map; // ID -> {min_weight, count}

    for (const auto& parcel : parcels) {
        int id = parcel[0];
        int weight = parcel[1];

        if (parcel_map.find(id) == parcel_map.end()) {
            parcel_map[id] = {weight, 1};
        } else {
            parcel_map[id].first = min(parcel_map[id].first, weight);
            parcel_map[id].second += 1;
        }
    }

    vector<vector<int>> result;
    for (const auto& entry : parcel_map) {
        if (entry.second.second > 1) {
            result.push_back({entry.first, entry.second.first});
        }
    }

    sort(result.begin(), result.end()); // Sort by ID

    return result;
}

// Test function to verify the implementation
int main() {
    // Test case 1: Example from the problem
    vector<vector<int>> parcels1 = {{1, 10}, {2, 5}, {1, 3}, {3, 8}, {2, 7}};
    vector<vector<int>> result1 = question_one(parcels1);
    
    cout << "Test 1 - Expected: [[1, 3], [2, 5]]" << endl;
    cout << "Actual: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[" << result1[i][0] << ", " << result1[i][1] << "]";
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test case 2: No duplicates
    vector<vector<int>> parcels2 = {{1, 10}, {2, 5}, {3, 8}};
    vector<vector<int>> result2 = question_one(parcels2);
    
    cout << "Test 2 - Expected: []" << endl;
    cout << "Actual: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "[" << result2[i][0] << ", " << result2[i][1] << "]";
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test case 3: Multiple duplicates
    vector<vector<int>> parcels3 = {{1, 10}, {1, 5}, {1, 15}, {2, 20}, {2, 10}};
    vector<vector<int>> result3 = question_one(parcels3);
    
    cout << "Test 3 - Expected: [[1, 5], [2, 10]]" << endl;
    cout << "Actual: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << "[" << result3[i][0] << ", " << result3[i][1] << "]";
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}