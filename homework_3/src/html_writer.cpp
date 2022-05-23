#include "../api/html_writer.hpp"
#include <iostream>

using namespace std;

/*
<!DOCTYPE html>
<html>
*/
void html_writer::OpenDocument() {
  cout << "<!DOCTYPE html>" << endl;
  cout << "<html>" << endl;
}

void html_writer::CloseDocument() { cout << "</html>" << endl; }
/*
<head>
    <link rel="stylesheet" type="text/css" href="style.css" />
  </head>
when want to write " in string, \" is " in string
*/
void html_writer::AddCSSStyle(const string &stylesheet) {
  cout << "<head>" << endl;
  cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" << stylesheet
            << "\" />" << endl;
  cout << "</head>" << endl;
}
/*
<title>Image Browser</title>
*/
void html_writer::AddTitle(const string &title) {
  cout << "<title>" << title << "</title>" << endl;
}
/*
<body>
*/
void html_writer::OpenBody() { cout << "<body>" << endl; }
/*
</body>
*/
void html_writer::CloseBody() { cout << "</body>" << endl; }
/*
<div class="row">
*/
void html_writer::OpenRow() { cout << "<div class=\"row\">" << endl; }
/*
</div>
*/
void html_writer::CloseRow() { cout << "</div>" << endl; }
/*
when highlight==true
<div class="column" style="border: 5px solid green;">
    <h2>000000.png</h2>
    <img src="data/000000.png" />
    <p>score = 0.98</p>
</div>
when highlight==false(default)
<div class="column">
    <h2>000100.png</h2>
    <img src="data/000100.png" />
    <p>score = 0.96</p>
</div>
*/
void html_writer::AddImage(const string &img_path, float score,bool highlight) {

  // split img_path and find extention then exception handling
  // path would be "./web_app/data/000000.png"~"./web_app/data/000800.png"
  string path = img_path;
  size_t last_dot_index = path.find_last_of('.');
  size_t last_slash_index =path.find_last_of('/');
  string ext = path.substr(last_dot_index + 1);
  string file_number =path.substr(last_slash_index + 1, last_dot_index - last_slash_index - 1);

  if (!(ext == "png" || ext == "jpg")) {
    cout << ext <<endl;
    cerr << "It should be png or jpg File!!!" << endl;
  }

  if (highlight == true) {
    cout << "<div class = \"column\" style = \"border: 5px solid green;\">"
         << endl;
  } else {
    cout << "<div class = \"column\">" << endl;
  }
  cout << "<h2>" << file_number + "." + ext << "</h2>" << endl;
  cout << "<img src=" << path << " />" << endl;
  cout.precision(2);
  cout << "<p>score = " << score << "</p>" << endl;
  cout << "</div>" << endl;
}

