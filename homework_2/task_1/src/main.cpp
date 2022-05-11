#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;

int main() {
  random_device rd;
  mt19937 rng(rd());

  uniform_int_distribution<> dist1(1, 98);
  int target = dist1(rng);
  bool flag = true;

  while (flag) {
    int input_number;
    cout << "input a number(0~99)" << endl;
    cin >> input_number;
    if (!cin.fail()) {
      if (input_number >= 0 && input_number <= 99) {
        if (input_number > target) {
          cout << "random number is smaller" << endl;
        } else if (input_number < target) {
          cout << "random number is bigger" << endl;
        } else {
          flag=false;
        }
      }
      else {
        cerr << "[WARNING] : Number must be between 0 and 99" << endl;
      }
    }
    else {
      cerr << "Error encountered, exiting..." << endl;
      exit(EXIT_FAILURE);
    }
  }
  cout <<target << endl;
  exit(EXIT_SUCCESS);
}