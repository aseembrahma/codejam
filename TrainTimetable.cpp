#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <functional>
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


typedef pair<pair<size_t, size_t>, bool> PQ_TYPE;
struct TrainStartTimeFunctor { 
   bool operator()(const PQ_TYPE &a, const PQ_TYPE &b) {
       return a.first.first > b.first.first;
   }
};

int main(int argc, char* argv[]) {
  string line;
  istringstream iss;
  size_t n = 0, i;
  const size_t MINUTES_PER_HOUR = 60;

  getline(cin, line);
  iss.str(line);
  iss >> n;
  iss.clear();

  for (i = 0; i < n; i++) {
    // T is the turnaround time, NA is the number of trips from A to B, NB is
    // the number of trips from B to A
    size_t T, NA, NB;
    //vector<pair<size_t, size_t> > tripsAB;
    //vector<pair<size_t, size_t> > tripsBA;
    // Queue with the start time as the key, and the <end_time, trip is from A
    // to B?> as the value
    priority_queue<PQ_TYPE, vector<PQ_TYPE>, TrainStartTimeFunctor>
      train_times;

    getline(cin, line);
    iss.str(line);
    iss >> T;
    iss.clear();

    getline(cin, line);
    iss.str(line);
    iss >> NA >> NB;
    iss.clear();

    for (size_t j = 0; j < NA; ++j) {
      char dummy;
      size_t start_hour, start_minute, end_hour, end_minute;
      getline(cin, line);
      iss.str(line);
      iss >> start_hour >> dummy >> start_minute
          >> end_hour >> dummy >> end_minute;
      iss.clear();
      /*
      tripsAB.push_back(
        make_pair(
          (start_hour * MINUTES_PER_HOUR) + start_minute,
          (end_hour * MINUTES_PER_HOUR) + end_minute));
      */
      train_times.push(
        make_pair(make_pair(
          (start_hour * MINUTES_PER_HOUR) + start_minute,
          (end_hour * MINUTES_PER_HOUR) + end_minute),
          true));
    }

    for (size_t j = 0; j < NB; ++j) {
      char dummy;
      size_t start_hour, start_minute, end_hour, end_minute;
      getline(cin, line);
      iss.str(line);
      iss >> start_hour >> dummy >> start_minute
          >> end_hour >> dummy >> end_minute;
      iss.clear();
      /*
      tripsBA.push_back(
        make_pair(
          (start_hour * MINUTES_PER_HOUR) + start_minute,
          (end_hour * MINUTES_PER_HOUR) + end_minute));
      */
      train_times.push(
        make_pair(make_pair(
          (start_hour * MINUTES_PER_HOUR) + start_minute,
          (end_hour * MINUTES_PER_HOUR) + end_minute),
          false));
    }

    size_t trainsStartingA = 0, trainsStartingB = 0;
    priority_queue<size_t, vector<size_t>, greater<size_t> > trainsAtA;
    priority_queue<size_t, vector<size_t>, greater<size_t> > trainsAtB;

    //cout << "T = " << T << endl;
    while (!train_times.empty()) {
      PQ_TYPE p = train_times.top();
      train_times.pop();

      if (p.second) {
        if (trainsAtA.empty() || trainsAtA.top() > p.first.first) {
          //cout << "Adding A train start time " << p.first.first << endl;
          trainsStartingA++;
          trainsAtA.push(p.first.first);
        }
        trainsAtA.pop();
        trainsAtB.push(p.first.second + T);
        //cout << "Train at B at " << (p.first.second + T) << endl;
      }
      else {
        if (trainsAtB.empty() || trainsAtB.top() > p.first.first) {
          //cout << "Adding B train start time " << p.first.first << endl;
          trainsStartingB++;
          trainsAtB.push(p.first.first);
        }
        trainsAtB.pop();
        trainsAtA.push(p.first.second + T);
        //cout << "Train at A at " << (p.first.second + T) << endl;
      }
    }

    cout << "Case #" << (i + 1) << ": " << trainsStartingA << " "
         << trainsStartingB << endl;
  };

  return 0;
}

