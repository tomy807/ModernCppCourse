#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int get_first(int num);
int get_last(int num);
int main(int argc, char *argv[]) {

  int num_list[2];
  string ext_list[2];
  if (argc != 3) {
    printf("[ERROR] : Only two arguments allowed\n");
    exit(EXIT_FAILURE);
  } else {
    
    for (int i = 1; i < argc; ++i) {
      istringstream iss(argv[i]);
      string ext;
      int num;
      iss >> num >> ext;
      if (ext.compare(".txt") != 0 && ext.compare(".png") != 0) {
        cerr << "[ERROR] : Unsupported extension format\n ";
        exit(EXIT_FAILURE);
      } else {
        if (ext.compare(".txt") == 0) {
          num_list[i - 1] = num;
          ext_list[i - 1] = "txt";
        } else if (ext.compare(".png") == 0) {
          num_list[i - 1] = num;
          ext_list[i - 1] = "png";
        }
      }
      
    }
    if (ext_list[0].compare("txt")==0 && ext_list[1].compare("txt")==0) {
      cout << (num_list[0]+num_list[1])/2 << endl;
    }
    else if(ext_list[0].compare("png")==0 && ext_list[1].compare("png")==0) {
        cout << (num_list[0]+num_list[1]) << endl;
    }
    else {
        cout << num_list[0] % num_list[1] << endl;
    }
  }
  return 0;
}