class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 1;

        while(i > 0 && s[i] <= s[i - 1]) {
            i--;
        }

        if(i == 0) {
            return -1;
        }

        int pivot = i - 1;
        i = s.size() - 1;

        while(s[i] <= s[pivot]) {
            i--;
        }

        swap(s[i], s[pivot]);
        reverse(s.begin() + pivot + 1, s.end());
        long long ans = stoll(s);

        if(ans > INT_MAX) {
            return -1;
        }

        return ans;
    }
};