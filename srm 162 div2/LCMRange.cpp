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

int f(vector <int> &v, int fact){
	int res = 0;
	for(int i=0, n=v.size(); i<n; ++i){
		int count =0;
		while(v[i]%fact == 0){
			++count;
			v[i]/=fact;
		}
		res = max(res,count);
	}
	return res;
}

struct LCMRange {
	int lcm(int first, int last) {
		if(last == 1)return 1;
		const int n = last-first+1;
		int primes[] = {2,3,5,7,11};
		vector <int> v(n);
		for(int i=0; i<n; ++i)v[i] = first+i;
		vector<int> facts(5,0);
		
		for(int i=0; i<5; ++i){
			facts[i]=f(v,primes[i]);
			int count = 0;
			for(int j=0; j<n; ++j){
				if(v[j] == 1)++count;
			}
			if(count == n)break;
		}
		int res = 1;
		for(int i=0; i<5; ++i)
			for(int j=0; j<facts[i]; ++j)
				res *= primes[i];
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
			int first                 = 1;
			int last                  = 5;
			int expected              = 60;

			return verify_case( casenum, expected, LCMRange().lcm( first, last ) );
		}
		case 1: {
			int first                 = 4;
			int last                  = 5;
			int expected              = 20;

			return verify_case( casenum, expected, LCMRange().lcm( first, last ) );
		}
		case 2: {
			int first                 = 1;
			int last                  = 12;
			int expected              = 27720;

			return verify_case( casenum, expected, LCMRange().lcm( first, last ) );
		}

		// custom cases

/*      case 3: {
			int first                 = ;
			int last                  = ;
			int expected              = ;

			return verify_case( casenum, expected, LCMRange().lcm( first, last ) );
		}*/
/*      case 4: {
			int first                 = ;
			int last                  = ;
			int expected              = ;

			return verify_case( casenum, expected, LCMRange().lcm( first, last ) );
		}*/
/*      case 5: {
			int first                 = ;
			int last                  = ;
			int expected              = ;

			return verify_case( casenum, expected, LCMRange().lcm( first, last ) );
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
