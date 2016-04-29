// BEGIN CUT HERE

#pragma warning(disable:4018)  // signed/unsigned mistatch
#pragma warning(disable:4244)  // w64 to int cast
#pragma warning(disable:4267)  // big to small -- possible loss of data
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4800)  // forcing int to bool
#pragma warning(disable:4996)  // deprecations
// END CUT HERE
#include "assert.h"
#include "ctype.h"
#include "float.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "utility"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#define all(v) (v).begin(), (v).end()
typedef long long i64;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}

// BEGIN CUT HERE
#define TC_LOCAL_COMPILE
#ifdef TC_LOCAL_COMPILE
#include "hash_set"
#include "hash_map"
using namespace stdext;
#else
#include "ext/hash_set"
#include "ext/hash_map"
using namespace __gnu_cxx;
#endif
// END CUT HERE

string getState(vector < pair <int, string> > &v, int low){
	int k = 1;
	for(int n=v.size(); k<n && v[k].first < low; ++k);
	if(k >= v.size())return v[v.size()-1].second;
	else if(v[k].first == low)return v[k].second;
	else return v[k-1].second;
}

struct Undo {
	string getText(vector <string> commands, vector <int> time) {
		vector < pair <int, string> > v;
		v.push_back(make_pair(0, ""));
		string s = "";
		for(int i=0, n=commands.size(); i<n; ++i){
			istringstream iss(commands[i]);
			string next; iss >> next;
			if(next == "type"){
				char c; iss >> c;
				s+=c;
				v.push_back(make_pair(time[i], s));
			}else{
				int x; iss >> x;
				int low = max(0, time[i] - x - 1);
				s = getState(v, low);
				v.push_back(make_pair(time[i], s));
			}
		}
		return v[v.size()-1].second;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
  int isinf(double x) {return !_finite(x);}
  int isnan(double x) {return _isnan(x);}
};
namespace moj_harness {
	int run_test_case(int);
	void run_test( int casenum ) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case( int casenum, const string &expected, const string &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string commands[]         = {"type a", "type b", "type c", "undo 3"};
			int time[]                = {1, 2, 3, 5};
			string expected           = "a";

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}
		case 1: {
			string commands[]         = {"type a", "type b", "undo 2", "undo 2"};
			int time[]                = {1,2,3,4};
			string expected           = "a";

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}
		case 2: {
			string commands[]         = {"type a", "undo 1", "undo 1"};
			int time[]                = {1,2,3};
			string expected           = "a";

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}
		case 3: {
			string commands[]         = {"type a", "type b", "type c", "undo 10"};
			int time[]                = {1, 2, 3, 1000};
			string expected           = "abc";

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}
		case 4: {
			string commands[]         = {"undo 1"};
			int time[]                = {1};
			string expected           = "";

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string commands[]         = ;
			int time[]                = ;
			string expected           = ;

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}*/
/*      case 6: {
			string commands[]         = ;
			int time[]                = ;
			string expected           = ;

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}*/
/*      case 7: {
			string commands[]         = ;
			int time[]                = ;
			string expected           = ;

			return verify_case( casenum, expected, Undo().getText( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <int>( time, time + ( sizeof time / sizeof time[0] ) ) ) );
		}*/
		default:
			return -1;
		}
	}
}

int main() {
  moj_harness::run_test(-1);
} 
// END CUT HERE
