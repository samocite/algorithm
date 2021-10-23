// https://pintia.cn/problem-sets/994805046380707840/problems/1111914599412858885
// PTA L1-064
// 原题为一道字符串题, 这里采用了正则表达式的方法

#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <regex>

using namespace std;

int n;
string s;

int main() {
  cin >> n;
  getchar();
  while (n--) {
    getline(cin, s);
    cout << s << endl;
    s = regex_replace(s, regex(R"(\s+)"), " ");
    if (s[0] == ' ') s.erase(0, 1);
    if (s[s.size() - 1] == ' ') s.erase(s.size() - 1, 1);
    s = regex_replace(s, regex(R"(^\s+|\s+$|\s+(?=\W))"), "");
    for (auto &c : s) if (c != 'I') c = tolower(c);
    s = regex_replace(s, regex(R"(\bI\b)"), "&&&");
    s = regex_replace(s, regex(R"(\bme\b)"), "&&&");
    s = regex_replace(s, regex(R"(\bcan you\b)"), "I can");
    s = regex_replace(s, regex(R"(\bcould you\b)"), "I could");
    s = regex_replace(s, regex(R"(&&&)"), "you");
    s = regex_replace(s, regex(R"(\?)"), "!");
    cout << "AI: " << s << endl;
  }

  return 0;
}
