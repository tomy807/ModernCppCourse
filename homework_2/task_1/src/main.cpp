#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;


int main() {
  random_device rd;
  mt19937 rng(rd());

  const int MAX_RAND_RANGE = 98;

  uniform_int_distribution<> dist1(1, MAX_RAND_RANGE);
  int target = dist1(rng);
  bool flag = true;

  while (flag) {
    int input_number = 0;
    cout << "input a number(0~99)" << endl;
    cin >> input_number;
    const int MAX_NUMBER = 99;
    if (!cin.fail()) {
      if (input_number >= 0 && input_number <= MAX_NUMBER) {
        if (input_number > target) {
          cout << "random number is smaller" << endl;
        } else if (input_number < target) {
          cout << "random number is bigger" << endl;
        } else {
          flag=false;
        }
      } else {
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