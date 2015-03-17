#include <iostream>
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

#define DEBUG 0

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

void reset() {

}

int main(int argc, char* argv[]) {
  string line;
  istringstream iss;
  size_t num_test_cases = 0, i;

  getline(cin, line);
  iss.str(line);
  iss >> num_test_cases;
  iss.clear();

  for (i = 0; i < num_test_cases; i++) {
    size_t total_credit, num_items;
    vector<size_t> items_ordered;
    set<size_t> items;
    set<size_t>::iterator it;

    getline(cin, line);
    iss.str(line);
    iss >> total_credit;
    iss.clear();

    getline(cin, line);
    iss.str(line);
    iss >> num_items;
    iss.clear();

    getline(cin, line);
    iss.str(line);
    for (size_t j = 0; j < num_items; ++j) {
      size_t item_value;
      iss >> item_value;

      if ((it = items.find(total_credit - item_value)) != items.end())
      {
        cout << "Case #" << (i + 1) << ": ";
        size_t k = (find(items_ordered.begin(), items_ordered.end(), *it)
                    - items_ordered.begin());
        if (j < k) {
          cout << (j + 1) << " " << (k + 1);
        }
        else {
          cout << (k + 1) << " " << (j + 1);
        }
        cout << endl;
        break;
      }

      items.insert(item_value);
      items_ordered.push_back(item_value);
    }
    iss.clear();

  };

  return 0;
}

