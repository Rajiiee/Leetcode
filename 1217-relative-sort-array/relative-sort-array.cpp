class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> count;
    for (int num : arr1) {
        count[num]++;
    }
    
    vector<int> result;
    for (int num : arr2) {
        if (count.find(num) != count.end()) {
            result.insert(result.end(), count[num], num);
            count.erase(num);
        }
    }
    
    vector<int> remaining_elements;
    for (auto& pair : count) {
        remaining_elements.insert(remaining_elements.end(), pair.second, pair.first);
    }
    
    sort(remaining_elements.begin(), remaining_elements.end());
    result.insert(result.end(), remaining_elements.begin(), remaining_elements.end());
    
    return result;
    }
};