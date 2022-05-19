#include "homework_4.h"
#include <cctype>
#include <iostream>
#include <vector>
// #include <algorithm>

int ipb::accumulate(const ipb::named_vector<int> &named_vector) {
  int answer=0;
  auto my_vector = named_vector.vector();
  for (int element : my_vector) {
    answer += element;
  }
  return answer;
}
int ipb::count(const ipb::named_vector<int> &named_vector,
               const int &target_num) {
  int answer = 0;
  auto &my_vector = named_vector.vector();
  for (int element : my_vector) {
    if (element == target_num) {
      answer+=1;
    }
  }
  return answer;
}
bool ipb::all_even(const ipb::named_vector<int> &named_vector) {
  bool flag=true;
  auto &my_vector = named_vector.vector();
  for (int element : my_vector) {
    if (element % 2 != 0) {
      flag=false;
    }
  }
  return flag;
}
void ipb::clamp(ipb::named_vector<int> &named_vector, const int kMin,
                const int kMax) {
  auto &my_vector = named_vector.vector();

  for (int &element : my_vector) {
    if (element > kMax) {
      element = kMax;
    } else if (element < kMin) {
      element = kMin;
    }
  }
  return;
}
void ipb::fill(ipb::named_vector<int> &named_vector, const int fill_num) {
  auto &my_vector = named_vector.vector();

  for (int &element : my_vector) {
    element = fill_num;
  }
}
bool ipb::find(const ipb::named_vector<int> &named_vector,
               const int &find_num) {
  auto &my_vector = named_vector.vector();

  for (int element : my_vector) {
    if (element == find_num) {
      return true;
    }
  }
  return false;
}
void ipb::print(const ipb::named_vector<int> &named_vector) {
  auto &my_vector = named_vector.vector();
  std::cout << named_vector.name();
  for (auto &element : my_vector)
    std::cout << element << ', ';
  std::cout << std::endl;
}
void ipb::toupper(ipb::named_vector<int> &named_vector) {
  auto &my_vector = named_vector.name();
  for (auto &element : my_vector) {
    element = std::toupper(element);
  }
}
int paritition(std::vector<int> &v, int left, int right) {

  int pivot = v[left];
  int low = left + 1;
  int high = right;
  while (low <= high)
  {
    while (low <= right && pivot >= v[low])
    {
      low++;
    }
    while (high >= (left + 1) &&
           pivot <= v[high])
    {
      high--;
    }
    if (low <= high)
    {
      int temp = v[low];
      v[low] = v[high];
      v[high] = temp;
    }
  }
  int temp = v[left];
  v[left] = v[high];
  v[high] = temp;
  return high;
}

void quick_sort(std::vector<int> &v, int left, int right) {
  if (left < right) {
    int q = paritition(v, left, right); 
    quick_sort(v, left, q - 1);          
    quick_sort(v, q + 1, right);         
  }
}
void ipb::sort(ipb::named_vector<int> &named_vector) {
  std::vector<int> &my_vector = named_vector.vector();
  quick_sort(my_vector, 0, my_vector.size()-1);
}
void ipb::rotate(ipb::named_vector<int> &named_vector,int rotate_num) {
  auto &my_vector = named_vector.vector();
  if (my_vector.empty() || (rotate_num %= my_vector.size()) == 0)
    return;
  int n = my_vector.size();
  for (int i = 0; i < n - rotate_num; ++i) {
    my_vector.push_back(my_vector[0]);
    my_vector.erase(my_vector.begin());
  }
}
void ipb::reverse(ipb::named_vector<int> &named_vector) {
  auto &my_vector = named_vector.vector();
  int left = 0;
  int right = my_vector.size() - 1;
  while (left < right) {
    int tmp = my_vector[left];
    my_vector[left] = my_vector[right];
    my_vector[right] = tmp;
    left += 1;
    right -= 1;
  }
}

