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

bool mark[40][4][4];
i64 memo[40][4][4];

i64 f(int n, int i, int l1, int l2){
	if(i >= n)return 1LL;

	i64 &count = memo[i][l1][l2];
	if(mark[i][l1][l2])return count;
	mark[i][l1][l2] = true;

	count = 0;
	if(l1 == 0){
		if(l2 == 0)count += f(n, i+1, l2, 0) + f(n, i+1, l2, 1) + f(n, i+1, l2, 2);
		else if(l2 == 1) count += f(n, i+1, l2, 0) + f(n, i+1, l2, 1);
		else if(l2 == 2) count += f(n, i+1, l2, 0) + f(n, i+1, l2, 2);
	}else if(l1 == 1){
		if(l2 == 0)count += f(n, i+1, l2, 0) + f(n, i+1, l2, 1);
		else if(l2 == 1) count += f(n, i+1, l2, 0) + f(n, i+1, l2, 1) + f(n, i+1, l2, 2);
		else if(l2 == 2) count += f(n, i+1, l2, 1) + f(n, i+1, l2, 2);
	}else if(l1 == 2){
		if(l2 == 0)count += f(n, i+1, l2, 0) + f(n, i+1, l2, 2);
		else if(l2 == 1) count += f(n, i+1, l2, 1) + f(n, i+1, l2, 2);
		else if(l2 == 2) count += f(n, i+1, l2, 0) + f(n, i+1, l2, 1) + f(n, i+1, l2, 2);
	}
	return count;
}

struct ForbiddenStrings {
	long long countNotForbidden(int n) {
		if(n == 1)return 3LL;
		if(n == 2)return 9LL;

		i64 res = 0;
		memset(mark, false, sizeof(mark));
		for(int i=0; i<3; ++i){
			for(int j=0; j<3; ++j){
				res += f(n, 2, i, j);
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
	
	int verify_case( int casenum, const long long &expected, const long long &received ) { 
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
			int n                     = 2;
			long long expected        = 9LL;

			return verify_case( casenum, expected, ForbiddenStrings().countNotForbidden( n ) );
		}
		case 1: {
			int n                     = 3;
			long long expected        = 21LL;

			return verify_case( casenum, expected, ForbiddenStrings().countNotForbidden( n ) );
		}
		case 2: {
			int n                     = 4;
			long long expected        = 51LL;

			return verify_case( casenum, expected, ForbiddenStrings().countNotForbidden( n ) );
		}

		// custom cases

/*      case 3: {
			int n                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, ForbiddenStrings().countNotForbidden( n ) );
		}*/
/*      case 4: {
			int n                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, ForbiddenStrings().countNotForbidden( n ) );
		}*/
/*      case 5: {
			int n                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, ForbiddenStrings().countNotForbidden( n ) );
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
