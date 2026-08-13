class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        vector<int> ans;
        
        while(i < nums1.size()){
            int nextGreat = -1;

            for(int j = 0; j < nums2.size() - 1; j++){
                if(nums2[j] == nums1[i]){

                    for(int k = j + 1; k < nums2.size(); k++){
                        if(nums2[k] > nums1[i]){
                            nextGreat = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            ans.push_back(nextGreat);
            i++;
        }

        return ans;
    }
};