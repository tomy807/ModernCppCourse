#include "../include/main.hpp"
using namespace image_browser;
using namespace std;

// create ScoredImage,ImageRow
// ImageRow1={ScoredImage1,ScoredImage2,ScoredImage3}
// ImageRow2={ScoredImage4,ScoredImage5,ScoredImage6}
// ImageRow3={ScoredImage7,ScoredImage8,ScoredImage9}
// ScoredImagei=(imagepath=./web_app/data/000+'i'00,score=random(0.0,1.0))
/*
 when method createRows()'s return value was 'vector<ImageRow>',
 warning"use a trailing return type for this functionclang-tidy(modernize-use-trailing-return-type)" occured
but when change to auto,it's ok
why more accurate return make warning??? 
*/
auto createRows() {
  random_device rd;
  mt19937 generator(rd());
  uniform_real_distribution<> uniform_real_distribution(0.0, 1.0);

  string image_folder_path = "./web_app/data/";
  vector<ImageRow> imgs_rows = {};
  for (int i = 0; i < 3; i++) {
    ImageRow image_row;
    for (int j = 0; j < 3; j++) {
      string img_path =
          image_folder_path + "000" + to_string(3 * i + j) + "00.png";
      float random_score = uniform_real_distribution(generator);
      ScoredImage scoredImage = make_tuple(img_path, random_score);

      image_row[j]=scoredImage;
    }
    imgs_rows.push_back(image_row);
  }
  return imgs_rows;
}
/*
i still dont know why 'int main' occur warning??????
*/
int main() {
  vector<ImageRow> rows = createRows();
  const string title = "Image Browser";
  const string stylesheet = "./web_app/style.css";
  CreateImageBrowser(title, stylesheet, rows);
  return 0;
}