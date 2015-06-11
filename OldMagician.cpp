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
  string answer;

  getline(cin, line);
  iss.str(line);
  iss >> num_test_cases;
  iss.clear();

  for (size_t i = 0; i < num_test_cases; i++) {

    size_t white, black;

    getline(cin, line);
    iss.str(line);
    iss >> white >> black;
    iss.clear();

    // If we're left with 3 balls at the end this is how it's going to play out
    // 0W3B->B
    // 2W1B->B
    // 1W2B->W
    // 3W0B->W

    // Also, at any point if we have W white balls and B black balls, the
    // possibilites are
    // 2W -> W-1, B
    // W, B -> W-1, B
    // 2B -> W+1, B-2
    // So the white count only ever changes by 1, and the black count only ever
    // decreases by 2

    if (black % 2 == 0)
    {
      answer = "WHITE";
    }
    else
    {
      answer = "BLACK";
    }
    cout << "Case #" << (i + 1) << ": " << answer << endl;
  };

  return 0;
}

