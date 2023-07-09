// Author : Amish Verma (@thisisamish)
// Approach 1 : Find all the words and store them in an array, then create the result string.
// TC - O(n)
// SC - O(n)

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string currWord = "";
        string ans = "";

        for (char c : s) {
            if (c == ' ') {
                if (currWord.size() > 0) {
                    words.push_back(currWord);
                    currWord = "";
                }
            } else {
                currWord += c;
            }
        }
        if (currWord.size() > 0) {
            words.push_back(currWord);
        }

        for (int i = words.size() - 1; i >= 0; i--) {
            if (i == 0) {
                ans += words[i];
            } else {
                ans += words[i] + " ";
            }
        }

        return ans;
    }
};