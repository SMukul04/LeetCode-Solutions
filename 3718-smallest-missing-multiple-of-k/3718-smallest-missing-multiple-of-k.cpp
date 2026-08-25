class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int i : nums){
            st.insert(i);
        }

        int temp = k;

        while(st.count(temp)){
            temp += k;
        }

        return temp;
    }
};