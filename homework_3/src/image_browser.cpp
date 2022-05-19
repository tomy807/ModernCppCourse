#include "../api/image_browser.hpp"
#include "../api/html_writer.hpp"

using namespace std;
using namespace html_writer;
/*
<div class="row">
    <div class="column" style="border: 5px solid green;">
        <h2>000000.png</h2>
        <img src="data/000000.png" />
        <p>score = 0.98</p>
    </div>
    <div class="column">
        <h2>000100.png</h2>
        <img src="data/000100.png" />
        <p>score = 0.96</p>
    </div>
    <div class="column">
        <h2>000200.png</h2>
        <img src="data/000200.png" />
        <p>score = 0.88</p>
    </div>
</div>
*/
void image_browser::AddFullRow(const ImageRow &row, bool first_row) {
  OpenRow();
  int iter = 0;
  bool highlight=false;
  for (ScoredImage element_by_row : row) {
    if (iter == 0 && first_row) {
      highlight=true;
    }else {
      highlight = false;
    }
    string img_path = get<0>(element_by_row);
    float score = get<1>(element_by_row);
    AddImage(img_path, score, highlight);
    iter++;
  }
  CloseRow();
}

void image_browser::CreateImageBrowser(const string &title,
                                       const string &stylesheet,
                                       const vector<ImageRow> &rows) {
  OpenDocument();
  AddTitle(title);
  AddCSSStyle(stylesheet);
  OpenBody();
  AddFullRow(rows[0],true);
  for (int i=1; i<rows.size(); i++) {
    AddFullRow(rows[i],false);
  }
  CloseBody();
  CloseDocument();
}
