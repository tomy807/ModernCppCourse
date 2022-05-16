#include <iostream>
#include <string>
using namespace std;
    
void AddImage(const string &img_path) {

  // split img_path and find extention then exception handling
  // path would be "./web_app/data/000000.png"~"./web_app/data/000800.png"
  string path = img_path;

  size_t last_dot_index = path.find_last_of('.');
  size_t last_slash_index = path.find_last_of('/');
  string ext = path.substr(last_dot_index + 1);
  string file_num = path.substr(last_slash_index + 1, last_dot_index-last_slash_index-1);

  cout << ext << endl;
  cout << file_num << endl;
}

void test_int(string& i) {
  i+="A";
  return;
}

int main() {
  // const string img_path = "./web_app/data/000000.png";
  // AddImage(img_path);
  string test_for_int = "Hello";
  test_int(test_for_int);
      cout <<test_for_int << endl;
}