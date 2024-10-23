/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
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
  string validIPAddress(string queryIP) {
    size_t pos;
    if ((pos = queryIP.find('.')) != string::npos) {
      return validIPv4(queryIP, pos) ? "IPv4" : "Neither";
    } else if ((pos = queryIP.find(':')) != string::npos) {
      return validIPv6(queryIP, pos) ? "IPv6" : "Neither";
    }

    return "Neither";
  }

  private:
  bool validIPv4(const string& queryIP, size_t pos) {
    size_t prev_poz = 0;
    int found = 0;
    do {
      if (++found > 3) {
        return false;
      }

      if (!isByte(queryIP, prev_poz, pos)) {
        return false;
      }
      prev_poz = pos + 1;
    }
    while ((pos = queryIP.find('.', pos + 1)) != string::npos);

    if (!isByte(queryIP, prev_poz, queryIP.size())) {
      return false;
    }

    return found == 3;
  }

  bool validIPv6(const string& queryIP, size_t pos) {
    size_t prev_poz = 0;
    int found = 0;
    do {
      if (++found > 7) {
        return false;
      }

      if (!isByte2(queryIP, prev_poz, pos)) {
        return false;
      }
      prev_poz = pos + 1;
    }
    while ((pos = queryIP.find(':', pos + 1)) != string::npos);
    if (found != 7 || !isByte2(queryIP, prev_poz, queryIP.size())) {
      return false;
    }

    return true;
  }

  inline bool isByte(const string& queryIP, size_t pos_start, size_t pos_end) {
    if (pos_start == pos_end || pos_end - pos_start > 3) {
      return false;
    }

    size_t i = pos_start;
    for (; i < pos_end; ++i) {
      if (queryIP[i] < '0' || queryIP[i] > '9') {
        return false;
      }
    }

    if (pos_end - pos_start > 1 && queryIP[pos_start] == '0') {
      return false;
    }

    if (3 == pos_end - pos_start) {
      if (stoi(queryIP.substr(pos_start, pos_end - pos_start)) > 255) {
        return false;
      }
    }

    return true;
  }

  inline bool isByte2(const string& queryIP, size_t pos_start, size_t pos_end) {
    if (pos_start == pos_end || pos_end - pos_start > 4) {
      return false;
    }

    for (size_t i = pos_start; i < pos_end; ++i) {
      if (queryIP[i] >= '0' && queryIP[i] <= '9') {
        continue;
      }
      if (queryIP[i] >= 'A' && queryIP[i] <= 'F') {
        continue;
      }
      if (queryIP[i] >= 'a' && queryIP[i] <= 'f') {
        continue;
      }

      return false;
    }

    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution sol;
  assert(sol.validIPAddress("0.0.0.0") == "IPv4");
  assert(sol.validIPAddress("100.100.100.100") == "IPv4");
  assert(sol.validIPAddress("89.207.132.170") == "IPv4");
  assert(sol.validIPAddress("89.207.132.300") == "Neither");
  assert(sol.validIPAddress("256.256.256.256") == "Neither");
  assert(sol.validIPAddress("1.2.3.") == "Neither");
  assert(sol.validIPAddress("1.2..4") == "Neither");
  assert(sol.validIPAddress("1..3.4") == "Neither");
  assert(sol.validIPAddress(".2.3.4") == "Neither");
  assert(sol.validIPAddress("1.2.3.4.5") == "Neither");
  assert(sol.validIPAddress("01.01.01.01") == "Neither");
  assert(sol.validIPAddress("f16c:f7ec:cfa2:e1c5:9a3c:cb08:801f:36b8") == "IPv6");
  assert(sol.validIPAddress("f16c:f7ec:cfa2:e1c5:9a3c:cb08:801f:36b8:45ed") == "Neither");
  assert(sol.validIPAddress("25r0:d0c2:9d26:eb77:f3d5:8ca3:2069:7783") == "Neither");
  assert(sol.validIPAddress("2001:0db8:85a3:00000:0:8A2E:0370:7334") == "Neither");
  assert(sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:73341") == "Neither");
  assert(sol.validIPAddress("2001:db8:85a3:0::8a2E:0370:7334") == "Neither");
  assert(sol.validIPAddress("866c:cf9d:2994:cd3b:55da:97e3:a5b4:a39b") == "IPv6");
  assert(sol.validIPAddress("2560:d0c2:9d26:eb77:f3d5:8ca3:2069:7783") == "IPv6");
  assert(sol.validIPAddress("5be8:dde9:7f0b:d5a7:bd01:b3be:9c69:573b") == "IPv6");

  cout << "OK" << endl;
  return 0;
}