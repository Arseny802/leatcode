/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
  public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j;) {
      if (!isalnum(s[i])) {
        ++i;
        continue;
      }
      if (!isalnum(s[j])) {
        --j;
        continue;
      }
      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }

      ++i;
      --j;
    }

    return true;
  }
};
// @lc code=end

int main() {
  Solution solution;
  {
    string s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s) << endl;
  }

  {
    string s = "race a car";
    cout << solution.isPalindrome(s) << endl;
  }

  {
    string s = " ";
    cout << solution.isPalindrome(s) << endl;
  }

  {
    string s = "0P";
    cout << solution.isPalindrome(s) << endl;
  }

  return 0;
}