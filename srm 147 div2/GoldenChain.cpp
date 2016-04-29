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

struct GoldenChain {
	int minCuts(vector <int> v) {
		sort(all(v));
		int n = v.size(), res = 0;
		for(int i=0, m=v.size(); i<m; ++i){
			if(v[i] < n){
				res += v[i];
				n-= v[i] + 1;
			}else{
				res += n;
				break;
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
	
	int verify_case( int casenum, const int &expected, const int &received ) { 
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
			int sections[]            = {3,3,3,3};
			int expected              = 3;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}
		case 1: {
			int sections[]            = {2000000000};
			int expected              = 1;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}
		case 2: {
			int sections[]            = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20, 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37, 38,39,40,41,42,43,44,45,46,47,48,49,50};
			int expected              = 42;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}
		case 3: {
			int sections[]            = {20000000,20000000,2000000000};
			int expected              = 3;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}
		case 4: {
			int sections[]            = {10,10,10,10,10,1,1,1,1,1};
			int expected              = 5;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}
		case 5: {
			int sections[]            = {1,10};
			int expected              = 1;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			int sections[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}*/
/*      case 7: {
			int sections[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
		}*/
/*      case 8: {
			int sections[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, GoldenChain().minCuts( vector <int>( sections, sections + ( sizeof sections / sizeof sections[0] ) ) ) );
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
