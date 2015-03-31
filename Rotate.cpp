#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <limits>
#include <numeric>
#include <bitset>

#define DEBUG 1

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

template <typename K, typename V>
V GetWithDef(const  std::map <K,V> & m, const K & key, const V & defval ) {
    typename std::map<K,V>::const_iterator it = m.find( key );
    if ( it == m.end() ) {
        return defval;
    }
    else {
        return it->second;
    }
}

struct sort_custom {
  bool operator()(const pair<size_t, size_t> &left,
                  const pair<size_t, size_t> &right)
  {
    return (left.first < right.first);
  }
};

void reset() {

}

int main(int argc, char* argv[]) {
  string line;
  istringstream iss;
  size_t num_test_cases;

  getline(cin, line);
  iss.str(line);
  iss >> num_test_cases;
  iss.clear();

  for (size_t i = 0; i < num_test_cases; i++) {
    size_t num_dimension, num_k;

    getline(cin, line);
    iss.str(line);
    iss >> num_dimension >> num_k;
    iss.clear();

    vector<vector<char> > table;

    for (size_t j = 0; j < num_dimension; j++) {
      getline(cin, line);
      iss.str(line);
      char c;
      vector<char> row;
      size_t num_blank = 0;
      for (size_t k = 0; k < num_dimension; k++) {
        iss >> c;
        if ('.' != c) {
          row.push_back(c);
        }
        else {
          ++num_blank;
        }
      }
      row.insert(row.begin(), num_blank, '.');
      table.push_back(row);
      iss.clear();
    }

    // print the table
    /*
    cout << "n = " << num_dimension << ", k = " << num_k << endl;
    for (size_t j = 0; j < num_dimension; j++) {
      for (size_t k = 0; k < num_dimension; k++) {
        cout << table[j][k];
      }
      cout << endl;
    }
    cout << endl;
    */

    bool red = false, blue = false;

    for (size_t l = 0; l < 4; ++l) {

      if (0 == l) {
        // Horizontal/rows
        for (size_t j = 0; j < num_dimension; j++) {
          size_t red_count = 0, blue_count = 0;
          for (size_t k = 0; k < num_dimension; k++) {
            if (!red) {
              if ('R' == table[j][k]) {
                red_count++;
                if (red_count >= num_k) {
                  red = true;
                }
              }
              else {
                red_count = 0;
              }
            }

            if (!blue) {
              if ('B' == table[j][k]) {
                blue_count++;
                if (blue_count >= num_k) {
                  blue = true;
                }
              }
              else {
                blue_count = 0;
              }
            }
          }
        }
      }
      else if (1 == l) {
        // Vertical/columns
        for (size_t j = 0; j < num_dimension; j++) {
          size_t red_count = 0, blue_count = 0;
          for (size_t k = 0; k < num_dimension; k++) {

            if (!red) {
              if ('R' == table[k][j]) {
                red_count++;
                if (red_count >= num_k) {
                  red = true;
                }
              }
              else {
                red_count = 0;
              }
            }

            if (!blue) {
              if ('B' == table[k][j]) {
                blue_count++;
                if (blue_count >= num_k) {
                  blue = true;
                }
              }
              else {
                blue_count = 0;
              }
            }
          }
        }
      }
      else if (2 == l) {
        // Diagonals from top left to bottom right
        for (int j = int(num_dimension) - 1;
             j > (-1 * int(num_dimension));
             --j)
        {
          size_t red_count = 0, blue_count = 0;
          size_t start_row, start_col;
          if (j < 0) {
            start_row = 0;
          }
          else {
            start_row = j;
          }
          start_col = abs(j) - start_row;
          for (size_t k = 0; k < num_dimension - abs(j); k++) {

            if (!red) {
              if ('R' == table[start_row][start_col]) {
                red_count++;
                if (red_count >= num_k) {
                  red = true;
                }
              }
              else {
                red_count = 0;
              }
            }

            if (!blue) {
              if ('B' == table[start_row][start_col]) {
                blue_count++;
                if (blue_count >= num_k) {
                  blue = true;
                }
              }
              else {
                blue_count = 0;
              }
            }

            start_row += 1;
            start_col += 1;
          }
        }
      }
      else if (3 == l) {
        // Diagonals from bottom left to top right
        for (int j = int(num_dimension) - 1;
             j > (-1 * int(num_dimension));
             --j)
        {
          size_t red_count = 0, blue_count = 0;
          size_t start_row, start_col;
          if (j >= 0) {
            start_row = 0;
            start_col = (num_dimension - 1) - j;
          }
          else {
            start_row = abs(j);
            start_col = num_dimension - 1;
          }
          for (size_t k = 0; k < num_dimension - abs(j); k++) {

            if (!red) {
              if ('R' == table[start_row][start_col]) {
                red_count++;
                if (red_count >= num_k) {
                  red = true;
                }
              }
              else {
                red_count = 0;
              }
            }

            if (!blue) {
              if ('B' == table[start_row][start_col]) {
                blue_count++;
                if (blue_count >= num_k) {
                  blue = true;
                }
              }
              else {
                blue_count = 0;
              }
            }

            start_row += 1;
            start_col -= 1;
          }
        }
      }

      if (red && blue) {
        break;
      }
    }

    cout << "Case #" << (i + 1) << ": ";
    if (red && blue)
      cout << "Both";
    else if (red)
      cout << "Red";
    else if (blue)
      cout << "Blue";
    else
      cout << "Neither";
    cout << endl;
  };


  return 0;
}

