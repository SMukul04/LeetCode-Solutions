class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> great;
        int i = 0;
        int j = 0;
        int cnt = 0;

        while(i < nums.size()){
            if(nums[i] < pivot){
                nums[j] = nums[i];
                j++;
            }
            else if(nums[i] == pivot){
                cnt++;
            }
            else{
                great.push_back(nums[i]);
            }
            i++;
        }

        i = 0;

        while(i < great.size() || cnt > 0){
            if(cnt > 0){
                nums[j] = pivot;
                j++;
                cnt--;
            }
            else{
                nums[j] = great[i];
                i++;
                j++;
            }
        }

        return nums;
    }
};