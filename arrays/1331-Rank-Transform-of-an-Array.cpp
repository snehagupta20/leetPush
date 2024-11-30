class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Make a copy of the original array 'arr' into 'arr2'
        vector<int> arr2 = arr;
        
        // Sort the copied array 'arr2'
        sort(arr2.begin(), arr2.end());
        
        // Create a map to store the rank of each unique number
        unordered_map<int, int> rank;
        int count = 1; // Start the ranking from 1
        
        // Loop through the sorted array and assign ranks to unique elements
        for (int i = 0; i < arr2.size(); i++) {
            // If the current element is not already ranked, assign the next rank
            if (!rank[arr2[i]]) {
                rank[arr2[i]] = count;
                count++; // Increment rank for the next unique element
            }
        }
        
        // Create a vector 'ans' to store the result (ranks of elements in the original array)
        vector<int> ans;
        
        // Loop through the original array and fetch the corresponding rank for each element
        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(rank[arr[i]]); // Use the 'rank' map to find the rank of 'arr[i]'
        }
        
        // Return the final vector of ranks
        return ans;
    }
};


// Explanation of Comments:
// Copying the array: The original array arr is copied to arr2 so we can sort arr2 without modifying the original input.

// Sorting: Sorting the copied array allows us to find the relative order of the elements.

// Using a map for ranks: We use an unordered_map to store ranks of unique elements. The condition if (!rank[arr2[i]]) ensures that we only assign ranks to elements that haven't been assigned yet.

// Assigning ranks: Each unique number in the sorted array gets an increasing rank, starting from 1.

// Generating the result: After calculating the ranks, we map the ranks back to the elements of the original array arr.