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
typedef long long i64;
// BEGIN CUT HERE
#define all(v) (v).begin(), (v).end()

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

i64 memo[100010];

struct EngineersPrimes {
	long long smallestNonPrime(int N) {
		memo[0] = 2; bool p; int primes = 1;
		for(i64 i=3; primes <= N; i+=2){
			p = true;
			int n = (int)ceil(sqrt((double)(i)));
			if(i%2 == 0)p = false;
			for(int k=3; k<=n && p; k+=2){
				if(i%k == 0)p=false;
			}
			if(p)memo[primes++] = i;
		}
		return memo[N]*memo[N];
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
			int N                     = 3;
			long long expected        = 49LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
		}
		case 1: {
			int N                     = 1;
			long long expected        = 9LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
		}
		case 2: {
			int N                     = 265;
			long long expected        = 2886601LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
		}
		case 3: {
			int N                     = 1835;
			long long expected        = 247716121LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
		}
		case 4: {
			int N                     = 10000;
			long long expected        = 10971096049LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
		}

		// custom cases

      case 5: {
			int N                     = 15048;
			long long expected        = 27019798129LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
		}
      case 6: {
			int N                     = 100000;
			long long expected        = 1689274677841LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
		}
/*      case 7: {
			int N                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, EngineersPrimes().smallestNonPrime( N ) );
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
