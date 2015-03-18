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

void reset() {

}

int main(int argc, char* argv[]) {
  string line;
  istringstream iss;
  size_t num_test_cases;
  size_t word_length, num_words;

  getline(cin, line);
  iss.str(line);
  iss >> word_length >> num_words >> num_test_cases;
  iss.clear();

  map<string, bool> prefix_map;

  for (size_t i = 0; i < num_words; i++) {
    string alien_word;
    getline(cin, line);
    iss.str(line);
    iss >> alien_word;
    iss.clear();

    for (size_t j = 0; j < alien_word.length(); ++j) {
      prefix_map[string(alien_word, 0, j + 1)] = true;
    }
  };

/*
#if DEBUG
  for (map<string, size_t>::iterator it = prefix_map.begin();
       it != prefix_map.end();
       ++it) {
    cout << it->first << " : " << it->second << endl;
  }
#endif
*/

  for (size_t i = 0; i < num_test_cases; i++) {
    string test_case;
    getline(cin, line);
    iss.str(line);
    iss >> test_case;
    iss.clear();

    size_t match_count = 0;
    queue<string> q;
    size_t length_covered = 0;

    for (size_t j = 0; j < test_case.length(); ++j) {
      vector<char> new_chars;
      if (test_case[j] != '(')
      {
        new_chars.push_back(test_case[j]);
      }
      else
      {
        for (j++; test_case[j] != ')'; ++j) {
          new_chars.push_back(test_case[j]);
        }
      }
      length_covered++;

      if (q.empty()) {
        for (vector<char>::iterator it = new_chars.begin();
             it != new_chars.end();
             ++it)
        {
          string new_string(1, *it);
          if (0 != prefix_map[new_string]) {
            q.push(new_string);
          }
        }
      }
      else {
        while((!q.empty()) && q.front().length() == (length_covered - 1))
        {
          for (vector<char>::iterator it = new_chars.begin();
               it != new_chars.end();
               ++it)
          {
            string new_string(q.front() + *it);
            if (0 != prefix_map[new_string]) {
              q.push(new_string);
            }
          }
          q.pop();
        }
      }

      if (q.empty())
        break;
    }

    if ((!q.empty()) && q.front().length() == word_length) {
      match_count = q.size();
    }
    cout << "Case #" << (i + 1) << ": " << match_count << endl;
  };

  return 0;
}

