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
  size_t n = 0, i;
  const size_t MAX_DIGITS = 10;

  getline(cin, line);
  iss.str(line);
  iss >> n;
  iss.clear();

  for (i = 0; i < n; i++) {
    string alien_num, src_lang, dest_lang;

    getline(cin, line);
    iss.str(line);
    iss >> alien_num >> src_lang >> dest_lang;
    iss.clear();

    size_t src_base = src_lang.length();
    size_t dest_base = dest_lang.length();

    map<char, unsigned short> src_mapping;
    for (size_t j = 0; j < src_lang.length(); ++j)
      src_mapping[src_lang[j]] = j;

    size_t decimal = 0;

    size_t alien_num_length = alien_num.length();
    for (size_t j = 0; j < alien_num_length; ++j) {
      decimal *= src_base;
      decimal += src_mapping[alien_num[j]];
    }

    if (DEBUG) cout << "Decimal: " << decimal << endl;

    ostringstream  os;
    do {
      os << dest_lang[(decimal % dest_base)];
      decimal /= dest_base;
    } while (decimal);
    string s = os.str();
    string ans(s.rbegin(), s.rend());
    cout << "Case #" << (i + 1) << ": " << ans << endl;
  };

  return 0;
}

