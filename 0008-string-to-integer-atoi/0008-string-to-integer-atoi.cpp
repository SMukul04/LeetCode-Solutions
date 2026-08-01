class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = (int)s.size();

        // Step 1: skip leading whitespace
        while (i < n && s[i] == ' ') i++;

        // Step 2: determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Step 3: read digits, accumulating with overflow protection
        long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            // Step 4: clamp early if we exceed 32-bit range
            if (sign * result >= INT_MAX) return INT_MAX;
            if (sign * result <= INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }
};