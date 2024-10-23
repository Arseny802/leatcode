/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
  int compress(vector<char>& chars) {
    vector<char> result;

    int i = 0;
    while (i < chars.size()) {
      int j = i;
      while (j < chars.size() && chars[j] == chars[i]) {
        j++;
      }
      result.push_back(chars[i]);
      if (j - i > 1) {
        string count = to_string(j - i);
        for (char c: count) {
          result.push_back(c);
        }
      }
      i = j;
    }

    chars = std::move(result);
    return chars.size();
  }
};
// @lc code=end

int main() {
  Solution solution;
  {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    assert(solution.compress(chars) == 6);
    assert(chars == vector<char>({'a', '2', 'b', '2', 'c', '3'}));
  }
  {
    vector<char> chars = {'a'};
    assert(solution.compress(chars) == 1);
    assert(chars == vector<char>({'a'}));
  }
  {
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    assert(solution.compress(chars) == 4);
    assert(chars == vector<char>({'a', 'b', '1', '2'}));
  }
  {
    vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    assert(solution.compress(chars) == 6);
    assert(chars == vector<char>({'a', '3', 'b', '2', 'a', '2'}));
  }

  cout << "OK" << endl;
  return 0;
}