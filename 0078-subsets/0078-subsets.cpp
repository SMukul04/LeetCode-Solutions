class Solution {
public:
    void func(int ind, vector<int>& nums, int N, vector<int>& subSet, vector<vector<int>>& ans){

        if(ind == N){
            ans.push_back(subSet);
            return;
        }

        //Pick Number
        subSet.push_back(nums[ind]);
        func(ind + 1, nums, N, subSet, ans);
        subSet.pop_back();

        //Skip 
        func(ind + 1, nums, N, subSet, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subSet;
        func(0, nums, nums.size(), subSet, ans);

        return ans;
    }
};