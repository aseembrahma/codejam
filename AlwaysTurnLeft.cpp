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
  const char char_map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                           'a', 'b', 'c', 'd', 'e', 'f' };

  getline(cin, line);
  iss.str(line);
  iss >> n;
  iss.clear();

  for (i = 0; i < n; i++) {
    string entry_to_exit, exit_to_entry;

    getline(cin, line);
    iss.str(line);
    iss >> entry_to_exit >> exit_to_entry;
    iss.clear();

    int x = 0, y = 0;
    int x_max = 0, y_max = 0, y_min = 0;
    map<pair<int, int>, int> routes;

    enum routes_t {
      CAN_GO_UP = 1,
      CAN_GO_DOWN = 2,
      CAN_GO_LEFT = 4,
      CAN_GO_RIGHT = 8
    };

    enum direction_t {
      FACING_UP = CAN_GO_UP,
      FACING_DOWN = CAN_GO_DOWN,
      FACING_LEFT = CAN_GO_LEFT,
      FACING_RIGHT = CAN_GO_RIGHT
    };
    direction_t direction = FACING_DOWN;

    routes[make_pair(x, y)] |= CAN_GO_UP;

    for (size_t j = 1; j < entry_to_exit.length() - 1; ++j) {
      if (entry_to_exit[j] == 'W') {
        if (FACING_UP == direction) {
          routes[make_pair(x, y)] |= CAN_GO_UP;
          --x;
          routes[make_pair(x, y)] |= CAN_GO_DOWN;
        }
        else if (FACING_RIGHT == direction) {
          routes[make_pair(x, y)] |= CAN_GO_RIGHT;
          ++y;
          if (y > y_max)
            y_max = y;
          routes[make_pair(x, y)] |= CAN_GO_LEFT;
        }
        else if (FACING_DOWN == direction) {
          routes[make_pair(x, y)] |= CAN_GO_DOWN;
          ++x;
          if (x > x_max)
            x_max = x;
          routes[make_pair(x, y)] |= CAN_GO_UP;
        }
        else if (FACING_LEFT == direction) {
          routes[make_pair(x, y)] |= CAN_GO_LEFT;
          --y;
          if (y < y_min)
            y_min = y;
          routes[make_pair(x, y)] |= CAN_GO_RIGHT;
        }
      }
      else if (entry_to_exit[j] == 'R') {
        if (FACING_UP == direction)
          direction = FACING_RIGHT;
        else if (FACING_RIGHT == direction)
          direction = FACING_DOWN;
        else if (FACING_DOWN == direction)
          direction = FACING_LEFT;
        else if (FACING_LEFT == direction)
          direction = FACING_UP;
      }
      else if (entry_to_exit[j] == 'L') {
        if (FACING_UP == direction)
          direction = FACING_LEFT;
        else if (FACING_LEFT == direction)
          direction = FACING_DOWN;
        else if (FACING_DOWN == direction)
          direction = FACING_RIGHT;
        else if (FACING_RIGHT == direction)
          direction = FACING_UP;
      }
    }

    if (FACING_UP == direction) {
      routes[make_pair(x, y)] |= CAN_GO_UP;
    }
    else if (FACING_RIGHT == direction) {
      routes[make_pair(x, y)] |= CAN_GO_RIGHT;
    }
    else if (FACING_DOWN == direction) {
      routes[make_pair(x, y)] |= CAN_GO_DOWN;
    }
    else if (FACING_LEFT == direction) {
      routes[make_pair(x, y)] |= CAN_GO_LEFT;
    }

    // Make an about turn!
    exit_to_entry.erase(0, 1);
    exit_to_entry.insert(0, "RR");
    for (size_t j = 0; j < exit_to_entry.length() - 1; ++j) {
      if (exit_to_entry[j] == 'W') {
        if (FACING_UP == direction) {
          routes[make_pair(x, y)] |= CAN_GO_UP;
          --x;
          routes[make_pair(x, y)] |= CAN_GO_DOWN;
        }
        else if (FACING_RIGHT == direction) {
          routes[make_pair(x, y)] |= CAN_GO_RIGHT;
          ++y;
          if (y > y_max)
            y_max = y;
          routes[make_pair(x, y)] |= CAN_GO_LEFT;
        }
        else if (FACING_DOWN == direction) {
          routes[make_pair(x, y)] |= CAN_GO_DOWN;
          ++x;
          if (x > x_max)
            x_max = x;
          routes[make_pair(x, y)] |= CAN_GO_UP;
        }
        else if (FACING_LEFT == direction) {
          routes[make_pair(x, y)] |= CAN_GO_LEFT;
          --y;
          if (y < y_min)
            y_min = y;
          routes[make_pair(x, y)] |= CAN_GO_RIGHT;
        }
      }
      else if (exit_to_entry[j] == 'R') {
        if (FACING_UP == direction)
          direction = FACING_RIGHT;
        else if (FACING_RIGHT == direction)
          direction = FACING_DOWN;
        else if (FACING_DOWN == direction)
          direction = FACING_LEFT;
        else if (FACING_LEFT == direction)
          direction = FACING_UP;
      }
      else if (exit_to_entry[j] == 'L') {
        if (FACING_UP == direction)
          direction = FACING_LEFT;
        else if (FACING_LEFT == direction)
          direction = FACING_DOWN;
        else if (FACING_DOWN == direction)
          direction = FACING_RIGHT;
        else if (FACING_RIGHT == direction)
          direction = FACING_UP;
      }
    }

    if (FACING_UP == direction) {
      routes[make_pair(x, y)] |= CAN_GO_UP;
    }
    else if (FACING_RIGHT == direction) {
      routes[make_pair(x, y)] |= CAN_GO_RIGHT;
    }
    else if (FACING_DOWN == direction) {
      routes[make_pair(x, y)] |= CAN_GO_DOWN;
    }
    else if (FACING_LEFT == direction) {
      routes[make_pair(x, y)] |= CAN_GO_LEFT;
    }

    cout << "Case #" << (i + 1) << ":" << endl;
    if (DEBUG) {
      cout << "Dimensions are "
           << (1 + x_max) << ", "
           << (1 + y_max - y_min) << endl;

      for (map<pair<int, int>, int>::iterator it = routes.begin();
          it!= routes.end();
          ++it) {
        cout << "(" << it->first.first << ", " << it->first.second << ") "
             << ((it->second) & CAN_GO_UP) << " "
             << ((it->second) & CAN_GO_DOWN) << " "
             << ((it->second) & CAN_GO_LEFT) << " "
             << ((it->second) & CAN_GO_RIGHT) << " "
             << endl;
      }
      cout << endl;
    }

    for (size_t j = 0; j < (1 + x_max); ++j) {
      for (size_t k = 0; k < (1 + y_max - y_min); ++k) {
        cout << char_map[routes[make_pair(j, y_min + k)]];
      }
      cout << endl;
    }
  };

  return 0;
}

