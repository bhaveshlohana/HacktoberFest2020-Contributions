#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
struct pivot
{
int m1,m2;
};
int partition2(vector<long int> &a, int l, int r) {
  long x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
pivot partition3(vector<long int> &a, int l, int r) {
  long x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }

int k=l;
for(int i=l+1;i<=j;i++)
{
if(a[i]<x)
{
k++;
swap(a[i],a[k]);
}
}
swap(a[l],a[k]);
pivot m;
m.m1=k;
m.m2=j;
  return m;
}



void randomized_quick_sort(vector<long int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pivot m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.m1 - 1);
  randomized_quick_sort(a, m.m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
