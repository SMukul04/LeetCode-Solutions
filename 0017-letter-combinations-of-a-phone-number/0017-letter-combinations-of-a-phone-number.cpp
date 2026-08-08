class Solution {
public:
    void findCombination(int index, string& digits, vector<string>& mapping,
                          string& path, vector<string>& result) {
        if (index == (int)digits.size()) {
            result.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mapping[digit];

        for (char c : letters) {
            path.push_back(c);
            findCombination(index + 1, digits, mapping, path, result);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string path;
        findCombination(0, digits, mapping, path, result);

        return result;
    }
};