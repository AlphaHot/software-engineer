/* Easy
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:
Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.

Constraints:
0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lower-case English letters.

Relatives:
136. Single Number
137. Single Number II
260. Single Number III
268. Missing Number
287. Find the Duplicate Number
389. Find the Difference
645. Set Mismatch */

#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char chr = 0;   // 0 ^ X = X

        for (int i = 0; i < s.size(); ++i)
            chr ^= s[i] ^ t[i];
        chr ^= t.back();

        return chr;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ascii[256] = { 0 };
        
        for (auto i = 0; i < s.size(); ++i) {
            ++ascii[s[i]];
            --ascii[t[i]];
        }
        --ascii[t.back()];
                
        for (auto i = 0; i < 256; ++i) {
            if (ascii[i] != 0)
                return i;
        }
                
        return 0;
    }
};