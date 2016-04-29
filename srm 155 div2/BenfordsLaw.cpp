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

int f(int x){
	int res = x % 10;
	while(x > 0){
		x/=10;
		if(x % 10 != 0)
			res = x %10;
	}
	return res;
}

struct BenfordsLaw {
	int questionableDigit(vector <int> transactions, int threshold) {
		vector <double> exp(10);
		for(int i=1; i<10; ++i){
			exp[i] = log10(1 + (1.0/(double)(i)));
		}
		vector <int> v(10);
		for(int i=0, n=transactions.size(); i<n; ++i){
			int k = f(transactions[i]);
			if(k != 0)v[k]++;
		}
		for(int i=1; i<10; ++i){
			double t = (double)threshold, freq = (double)(v[i]), n = (double)(transactions.size());
			if(freq < exp[i]*n/t || freq > exp[i]*t*n)
				return i; 
		}
		return -1;
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
			int transactions[]        = { 5236,7290,200,1907,3336,9182,17,4209,8746,7932,   6375,909,2189,3977,2389,2500,1239,3448,6380,4812 };
			int threshold             = 2;
			int expected              = 1;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
		}
		case 1: {
			int transactions[]        = { 1,10,100,2,20,200,2000,3,30,300 };
			int threshold             = 2;
			int expected              = 2;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
		}
		case 2: {
			int transactions[]        = { 9,87,765,6543,54321,43219,321987,21987,1987,345,234,123 };
			int threshold             = 2;
			int expected              = -1;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
		}
		case 3: {
			int transactions[]        = { 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 };
			int threshold             = 8;
			int expected              = 9;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
		}
		case 4: {
			int transactions[]        = { 987,234,1234,234873487,876,234562,17,   7575734,5555,4210,678234,3999,8123 };
			int threshold             = 3;
			int expected              = 8;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
		}

		// custom cases

/*      case 5: {
			int transactions[]        = ;
			int threshold             = ;
			int expected              = ;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
		}*/
/*      case 6: {
			int transactions[]        = ;
			int threshold             = ;
			int expected              = ;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
		}*/
/*      case 7: {
			int transactions[]        = ;
			int threshold             = ;
			int expected              = ;

			return verify_case( casenum, expected, BenfordsLaw().questionableDigit( vector <int>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ), threshold ) );
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
