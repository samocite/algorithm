/*回溯法解n皇后，maxn = 14，递归解法*/
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int maxn = 15;
int check[3][2 * maxn] = {}, n, ans[maxn], total;
void print() {
  total++;
  if (total > 3) return;
  for (int j = 1; j <= n; j++) printf("%d ", ans[j]);
  printf("\n");
  return;
}
void dfs(int n1) {
  if (n1 > n) print();
  for (int i = 1; i <= n; i++) {
    if (!check[0][i] && (!check[1][n1 + i]) && (!check[2][n1 - i + n])) { 
      /*
      check[0]储存了棋子的列数，每一次进行ans[line]=i，使check[0][i]标记为已使用;
      check[1]和check[2]储存对角线上的棋子分布情况;
      对于一条从右上到左下的对角线，其上的棋子坐标应满足x+y为一定值;
      对于一条从左上到右下的对角线，其上的棋子坐标应满足x-y为一定值,
      为了避免负数的产生，代码中用x-y+n来储存数字;
      */
      ans[n1] = i;
      check[0][i] = 1; check[1][n1 + i] = 1; check[2][n1 - i + n] = 1;
      dfs(n1 + 1);
      check[0][i] = 0; check[1][n1 + i] = 0; check[2][n1 - i + n] = 0;
    }
  }
  return;
}
int main() {
  scanf("%d", &n);
  dfs(1);
  printf("%d", total);
  return 0;
}
