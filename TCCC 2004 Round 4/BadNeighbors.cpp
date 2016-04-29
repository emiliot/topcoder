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

int memo[100];

int f(vector <int> &v){
	memset(memo,0,sizeof(memo));
	int best = 0;
	for(int i=0, n=v.size(); i<n; ++i){
		int a = i-2, b = i-3;
		memo[i] = max(v[i] + (a >=0 ? memo[a] : 0), (i>0? v[i-1] : 0) + (b >= 0? memo[b] : 0));
		best = max(best, memo[i]);
	}
	return best;
}

struct BadNeighbors {
	int maxDonations(vector <int> donations) {
		vector <int> v1(donations.begin(), donations.end()-1),
			v2(donations.begin() + 1, donations.end());
		return max(f(v1), f(v2));
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
			int donations[]           =  { 10, 3, 2, 5, 7, 8 };
			int expected              = 19;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
		}
		case 1: {
			int donations[]           = { 11, 15 };
			int expected              = 15;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
		}
		case 2: {
			int donations[]           = { 7, 7, 7, 7, 7, 7, 7 };
			int expected              = 21;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
		}
		case 3: {
			int donations[]           = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
			int expected              = 16;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
		}
		case 4: {
			int donations[]           = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,     6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,   52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
			int expected              = 2926;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int donations[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
		}*/
/*      case 6: {
			int donations[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
		}*/
/*      case 7: {
			int donations[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, BadNeighbors().maxDonations( vector <int>( donations, donations + ( sizeof donations / sizeof donations[0] ) ) ) );
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
