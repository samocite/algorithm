#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int people[1001];
int T, n, m, i, table;

/*
  题目大意：某人举办生日派对，请来许多来客，若来客之间为朋友，则可以坐在一桌，计算需要多少桌子
  输入格式：先输入测试次数T，然后输入T组数据，首先是来客数n和互相是朋友的组数m，然后输入m对整数，表示两人的编号
  输出格式：输出需要的桌子数
*/
int fd(int a) { return people[a] == a ? a : fd(people[a]); }
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m;
    table = n;
    for (i = 1; i <= n; i++) {
      people[i] = i;
    }
    
    for (i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      /*牵引队长*/
      if (fd(x) != fd(y)) {
        people[fd(y)] = fd(x);
        table--;
      }
    }
    cout << table << endl;
  }
  return 0;
}
