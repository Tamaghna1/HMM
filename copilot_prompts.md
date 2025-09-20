# GitHub Copilot Prompts for Code Generation

## Parcel Deduplication Problem - C++ Solution

### Complete Prompt for GitHub Copilot

**Copy and paste this exact prompt to GitHub Copilot:**

---

You are given a list of parcels where each parcel is represented as a pair of integers: ID and weight. Some parcels may have the same ID but different weight values, which are considered duplicates.

Your task is to identify all parcel IDs that appear more than once in the list. For each duplicate ID, return the minimum weight among all its occurrences.

**Function Signature:**
```cpp
vector<vector<int>> question_one(const vector<vector<int>>& parcels);
```

**Input Format:**
• parcels: A vector of vectors where each inner vector contains two integers:
  – parcels[i][0]: ID of the i-th parcel
  – parcels[i][1]: Weight of the i-th parcel

**Output Format:** 
A vector of vectors where each inner vector contains:
• output[i][0]: A parcel ID that appears more than once
• output[i][1]: The minimum weight among all parcels with that ID

**Note:** The output list should be sorted by ID.

**Constraints:**
• 0 ≤ id, weight ≤ 10^8
• 1 ≤ n ≤ 10^8 (where n is the number of parcels)

**Requirements:**
- Use unordered_map<int, pair<int, int>> to track parcel IDs with {min_weight, count}
- Include proper C++ headers and using namespace std
- Sort the final result by parcel ID using sort()
- Only return IDs that appear more than once (count > 1)
- Use range-based for loops for iteration

**Example:**
Input: [[1, 10], [2, 5], [1, 3], [3, 8], [2, 7]]
Output: [[1, 3], [2, 5]]
Explanation: ID 1 appears twice with weights [10, 3], minimum is 3. ID 2 appears twice with weights [5, 7], minimum is 5.

Write a complete C++ function that solves this problem efficiently using STL containers and algorithms.

---

### Expected Generated Code Structure

When you use this prompt, GitHub Copilot should generate code similar to:

```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> question_one(const vector<vector<int>>& parcels) {
    unordered_map<int, pair<int, int>> parcel_map; // ID -> {min_weight, count}
    
    // Process each parcel
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
    
    // Build result for IDs that appear more than once
    vector<vector<int>> result;
    for (const auto& entry : parcel_map) {
        if (entry.second.second > 1) {
            result.push_back({entry.first, entry.second.first});
        }
    }
    
    sort(result.begin(), result.end()); // Sort by ID
    return result;
}
```

### Tips for Using This Prompt

1. **Context Setup**: Before using the prompt, create a new C++ file or open an existing one
2. **Incremental Generation**: You can start with just the problem description and let Copilot suggest the function signature
3. **Code Comments**: Add comments like `// ID -> {min_weight, count}` to guide Copilot's understanding
4. **Alternative Prompts**: You can also use shorter versions like "Find duplicate parcel IDs and return minimum weights for each duplicate ID"

### Quick Reference - Minimal Prompt

If you prefer a shorter prompt, you can use this condensed version:

```
Write a C++ function that finds duplicate parcel IDs and returns the minimum weight for each duplicate.

Input: vector<vector<int>> parcels where parcels[i] = [id, weight]
Output: vector<vector<int>> result where result[i] = [duplicate_id, min_weight]
Requirements: Use unordered_map, sort result by ID, only return IDs that appear > 1 times

Function signature: vector<vector<int>> question_one(const vector<vector<int>>& parcels);
```

### Test File

A complete test file (`parcel_deduplication_example.cpp`) is included in this repository to verify the generated code works correctly with various test cases.