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

struct LeaguePicks {
	vector <int> returnPicks(int position, int friends, int picks) {
		vector <int> res; bool head = true;
		for(int i=1, k = position-i; i+k <=picks;){
			i = i+k;
			res.push_back(i);
			if(head){
				k = 2*(friends - position)+1;
				head = false;
			}else{
				k = 2*(position-1) + 1;
				head = true;
			}
		}
		return res;
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int position              = 3;
			int friends               = 6;
			int picks                 = 15;
			int expected[]            = { 3,  10,  15 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), LeaguePicks().returnPicks( position, friends, picks ) );
		}
		case 1: {
			int position              = 1;
			int friends               = 1;
			int picks                 = 10;
			int expected[]            = { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), LeaguePicks().returnPicks( position, friends, picks ) );
		}
		case 2: {
			int position              = 1;
			int friends               = 2;
			int picks                 = 39;
			int expected[]            = { 1,  4,  5,  8,  9,  12,  13,  16,  17,  20,  21,  24,  25,  28,  29,  32,  33,  36,  37 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), LeaguePicks().returnPicks( position, friends, picks ) );
		}
		case 3: {
			int position              = 5;
			int friends               = 11;
			int picks                 = 100;
			int expected[]            = { 5,  18,  27,  40,  49,  62,  71,  84,  93 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), LeaguePicks().returnPicks( position, friends, picks ) );
		}

		// custom cases

/*      case 4: {
			int position              = ;
			int friends               = ;
			int picks                 = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), LeaguePicks().returnPicks( position, friends, picks ) );
		}*/
/*      case 5: {
			int position              = ;
			int friends               = ;
			int picks                 = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), LeaguePicks().returnPicks( position, friends, picks ) );
		}*/
/*      case 6: {
			int position              = ;
			int friends               = ;
			int picks                 = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), LeaguePicks().returnPicks( position, friends, picks ) );
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
