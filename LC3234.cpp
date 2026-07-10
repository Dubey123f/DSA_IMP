// 3234. Count the Number of Substrings With Dominant Ones
// You are given a binary string s.

// Return the number of substrings with dominant ones.

// A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.

 

// Example 1:

// Input: s = "00011"

// Output: 5

// Explanation:

// The substrings with dominant ones are shown in the table below.

// i	j	s[i..j]	Number of Zeros	Number of Ones
// 3	3	1	0	1
// 4	4	1	0	1
// 2	3	01	1	1
// 3	4	11	0	2
// 2	4	011	1	2
// Example 2:

// Input: s = "101101"

// Output: 16

// Explanation:

// The substrings with non-dominant ones are shown in the table below.

// Since there are 21 substrings total and 5 of them have non-dominant ones, it follows that there are 16 substrings with dominant ones.

// i	j	s[i..j]	Number of Zeros	Number of Ones
// 1	1	0	1	0
// 4	4	0	1	0
// 1	4	0110	2	2
// 0	4	10110	2	3
// 1	5	01101	2	3
 

// Constraints:

// 1 <= s.length <= 4 * 104
// s consists only of characters '0' and '1'.
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zero;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero.push_back(i);
        }
        int ones = n - zero.size(); 
        zero.push_back(n); 

        int res = 0, sid = 0; 

        for (int left = 0; left < n; left++) {
           
            for (int id = sid; id < zero.size() - 1; id++) {
                int cnt0 = id - sid + 1; 
                if (cnt0 * cnt0 > ones) break;
                int p = zero[id], q = zero[id + 1];
                int cnt1 = zero[id] - left - (id - sid);
                if (cnt1 >= cnt0 * cnt0) {
                    res += q - p;
                } else {
                    res += max(q - p - (cnt0 * cnt0 - cnt1), 0);
                }
            }
            if (s[left] == '0') {
                sid++;
            } else {
               
                res += zero[sid] - left;
                ones--;
            }
        }
        return res;
    }
};