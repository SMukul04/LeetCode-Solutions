class Solution {
public:
    void findCombination(int start, int k, int n, vector<int>& ans, vector<vector<int>>& result) {
        if ((int)ans.size() == k) {
            if (n == 0) {
                result.push_back(ans);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) break; 
            
            ans.push_back(i);
            findCombination(i + 1, k, n - i, ans, result);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> result;

        findCombination(1, k, n, ans, result);

        return result;
    }
};