class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = nums1[0];
        bool allEven = true;

        for(int i = 0; i < nums1.size(); i++){
            mini = min(mini, nums1[i]);

            if(nums1[i]%2 != 0){
                allEven = false;
            }
        }

        if(mini%2 != 0){
            return true;
        }

        if(allEven){
            return true;
        }

        return false;
    }
};