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

    getline(cin, line);
    
    set<char> distinct_chars;
    map<char, size_t> char_values;
    size_t value = 1;

    for (size_t j = 0; j < line.length(); ++j) {
      if (distinct_chars.end() == distinct_chars.find(line[j])) {
        distinct_chars.insert(line[j]);
        char_values[line[j]] = value;

        if (1 == value) {
          value = 0;
        }
        else if (0 == value) {
          value = 2;
        }
        else {
          ++value;
        }
      }
    }

    size_t base = distinct_chars.size();
    if (1 == base) {
      base = 2;
    }

    unsigned long long final_val = 0;
    for (size_t j = 0; j < line.length(); ++j) {
      final_val *= base;
      final_val += char_values[line[j]];
    }
    cout << "Case #" << (i + 1) << ": " << final_val << endl;
  };

  return 0;
}

