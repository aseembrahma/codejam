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
    getline(cin, line);

    size_t space_pos;
    size_t current_pos = line.length();
    ostream_iterator<char> out_it (cout);

    cout << "Case #" << (i + 1) << ": ";

    do {
      space_pos = line.find_last_of(' ', current_pos - 1);
      if (space_pos != string::npos) {
        copy (line.begin() + space_pos + 1, line.begin() + current_pos, out_it);
        cout << " ";
        current_pos = space_pos;
      }
      else {
        copy (line.begin(), line.begin() + current_pos, out_it);
      }
    } while (space_pos != string::npos);

    cout << endl;
  };

  return 0;
}

