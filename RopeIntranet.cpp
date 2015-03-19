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
    size_t num_wires;

    getline(cin, line);
    iss.str(line);
    iss >> num_wires;
    iss.clear();

    vector<pair<size_t, size_t> > wires;

    for (size_t j = 0; j < num_wires; ++j) {
      size_t start, end;

      getline(cin, line);
      iss.str(line);
      iss >> start >> end;
      iss.clear();

      wires.push_back(make_pair(start, end));
    }

    sort(wires.begin(), wires.end());

    size_t intersections = 0;

    for (size_t j = 0; j < num_wires; ++j) {
      for (size_t k = j + 1; k < num_wires; ++k) {
        if (wires[k].second < wires[j].second) {
          intersections++;
        }
      }
    }
    cout << "Case #" << (i + 1) << ": " << intersections << endl;
  };


  return 0;
}

