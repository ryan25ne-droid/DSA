class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;
        if (m > n) return -1;

        // Build bad character table
        vector<int> badChar(256, -1);
        for (int i = 0; i < m; i++) {
            badChar[(int)needle[i]] = i;
        }

        int shift = 0;
        while (shift <= n - m) {
            int j = m - 1;

            // Match from right to left
            while (j >= 0 && needle[j] == haystack[shift + j]) {
                j--;
            }

            if (j < 0) {
                return shift; // found match
                // shift += (shift + m < n) ? m - badChar[haystack[shift + m]] : 1;
            } else {
                // Apply bad character rule
                shift += max(1, j - badChar[(int)haystack[shift + j]]);
            }
        }
        return -1;
    }
};
