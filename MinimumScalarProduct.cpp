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
    size_t num_elements;
    vector<long long int> v1, v2;

    getline(cin, line);
    iss.str(line);
    iss >> num_elements;
    iss.clear();

    getline(cin, line);
    iss.str(line);
    for (size_t j = 0; j < num_elements; ++j) {
      long long int elem;
      iss >> elem;
      v1.push_back(elem);
    }
    iss.clear();

    getline(cin, line);
    iss.str(line);
    for (size_t j = 0; j < num_elements; ++j) {
      long long int elem;
      iss >> elem;
      v2.push_back(elem);
    }
    iss.clear();

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), std::greater<int>());

    long long int product = 0;
    for (size_t j = 0; j < num_elements; ++j) {
      product += (v1[j] * v2[j]);
    }

    cout << "Case #" << (i + 1) << ": " << product << endl;
  };

  return 0;
}

