#include <iostream>
#define KiB 12800
using namespace std;

void recur(int index) {
  double a[KiB];
  cerr << index * 100 << "[KiB] Allocated in the stack" << endl;
  recur(index + 1);
};
int main() {
  recur(1);
  return 0;
}