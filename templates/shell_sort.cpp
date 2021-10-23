//希尔排序
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;
const int N = 1e6 + 10;
int n, q[N];

void shell_sort(int q[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = 0; i < gap; i++) {
      for (int j = i + gap; j < n; j += gap) {
        if (q[j] < q[j - gap]) {
          int tmp = q[j];
          int k = j - gap;
          while (k >= 0 && q[k] > tmp) {
            q[k + gap] = q[k];
            k -= gap;
          }
          q[k + gap] = tmp;
        }
      }
    }
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &q[i]);
  
  shell_sort(q, n);

  for (int i = 0; i < n; i++) printf("%d ", q[i]);
  return 0;
}
