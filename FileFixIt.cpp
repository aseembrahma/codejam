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
    size_t num_existing_dirs, num_new_dirs;

    getline(cin, line);
    iss.str(line);
    iss >> num_existing_dirs >> num_new_dirs;
    iss.clear();

    map<string, set<string> > dirs;

    for (size_t j = 0; j < num_existing_dirs; j++) {   
      getline(cin, line);

      string prev("/");
      size_t slash_pos_start = 0;
      size_t slash_pos_end;

      do {
        slash_pos_end = line.find_first_of('/', slash_pos_start + 1);
        string next(line, 0, slash_pos_end);

        dirs[prev].insert(next);
        prev = next;
        slash_pos_start = slash_pos_end;

      } while (slash_pos_start != string::npos);
    }

    /*
    for (map<string, set<string> >::iterator it = dirs.begin();
         it != dirs.end();
         ++it)
    {
      cout << it->first << " : ";
      for (set<string>::iterator it2 = (it->second).begin();
           it2 != (it->second).end();
           ++it2)
      {
        cout << *it2 << " ";
      }
      cout << endl;
    }
    */

    size_t num_mkdirs = 0;

    for (size_t j = 0; j < num_new_dirs; j++) {   
      getline(cin, line);

      string prev("/");
      size_t slash_pos_start = 0;
      size_t slash_pos_end;

      do {
        slash_pos_end = line.find_first_of('/', slash_pos_start + 1);
        string next(line, 0, slash_pos_end);

        if (dirs[prev].end() == dirs[prev].find(next)) {
          ++num_mkdirs;
          dirs[prev].insert(next);
        }

        prev = next;
        slash_pos_start = slash_pos_end;

      } while (slash_pos_start != string::npos);
    }

    cout << "Case #" << (i + 1) << ": " << num_mkdirs << endl;
  };


  return 0;
}

