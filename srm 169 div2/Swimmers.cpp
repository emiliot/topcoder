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

// BEGIN CUT HERE
#define all(v) (v).begin(), (v).end()
typedef long long i64;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
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

struct Swimmers {
	vector <int> getSwimTimes(vector <int> d, vector <int> s, int current) {
		vector <int> res;
		for(int i=0, n = s.size(); i<n; ++i){
			if(d[i]==0){
				res.push_back(0);
				continue;
			}
			if(s[i] <= current){
				res.push_back(-1);
				continue;
			}
			int time = floor(((double)(d[i])/(double)(s[i]+current))+((double)(d[i])/(double)(s[i]-current)));
			res.push_back(time);
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
			int distances[]           = { 300, 300, 300 };
			int speeds[]              = { 1, 2, 3 };
			int current               = 2;
			int expected[]            = { -1,  -1,  360 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
		}
		case 1: {
			int distances[]           = { 500, 500 };
			int speeds[]              = { 4, 5 };
			int current               = 2;
			int expected[]            = { 333,  238 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
		}
		case 2: {
			int distances[]           = { 0, 0 };
			int speeds[]              = { 1, 2 };
			int current               = 1;
			int expected[]            = { 0,  0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
		}
		case 3: {
			int distances[]           = { 0, 1 };
			int speeds[]              = { 0, 0 };
			int current               = 0;
			int expected[]            = { 0,  -1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
		}
		case 4: {
			int distances[]           = { 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583,   7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691,   7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823,   7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919 };
			int speeds[]              = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,   73, 79, 83, 89, 97, 99, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,   32, 34, 36, 38, 40, 42, 44, 46, 48, 51 };
			int current               = 6;
			int expected[]            = { -1,  -1,  -1,  8108,  1950,  1474,  1014,  882,  705,  544,  507,  420,  377,  359,  328,  290,  260,  252,  229,  216,  210,  195,  185,  173,  159,  155,  -1,  -1,  4409,  2413,  1717,  1354,  1127,  969,  852,  764,  692,  635,  585,  543,  507,  476,  449,  424,  402,  383,  365,  349,  334,  314 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
		}

		// custom cases

/*      case 5: {
			int distances[]           = ;
			int speeds[]              = ;
			int current               = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
		}*/
/*      case 6: {
			int distances[]           = ;
			int speeds[]              = ;
			int current               = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
		}*/
/*      case 7: {
			int distances[]           = ;
			int speeds[]              = ;
			int current               = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current ) );
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
