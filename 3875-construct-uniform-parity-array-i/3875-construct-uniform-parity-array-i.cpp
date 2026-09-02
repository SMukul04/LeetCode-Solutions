class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> nums2(nums1.size());
        int n = nums1.size();
        int i;
        int evenCount = 0, oddCount = 0;

        for(i = 0; i < n; i++){
            if(nums1[i] % 2 != 0){
                oddCount++;
            }
            else{
                evenCount++;
            }

            if(evenCount == n) return true;
            if(oddCount == n) return true;
        }

        int j = 0;
        int cnt = 0;

        if(evenCount != n){
            i = 0;
            for(i = 0; i < n; i++){
                for(j = 0; j < n; j++){
                    if(i != j){
                        int number = nums1[i] - nums1[j];
                        if(number % 2 != 0){
                            cnt++;
                            if(cnt = n){
                                return true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};