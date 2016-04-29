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

struct Zoo {
	long long theCount(vector <int> answers) {
		vector <int> v(50, 0);
		for(int i=0, n=answers.size(); i<n; ++i){
			v[answers[i]]++;
		}
		
		for(int i=0; i<50; ++i)
			if(v[i]>2)return 0LL;

		for(int i=1, n=50; i<n; ++i){
			if(v[i] > v[i-1])return 0LL;
		}
		
		int twos = 0;
		for(;v[twos] == 2; ++twos);

		if(v[twos] == 1)return 1LL << (twos+1);
		else return 1LL << twos;
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
			int answers[]             = {0, 1, 2, 3, 4};
			long long expected        = 2LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
		}
		case 1: {
			int answers[]             = {5, 8};
			long long expected        = 0LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
		}
		case 2: {
			int answers[]             = {0, 0, 0, 0, 0, 0};
			long long expected        = 0LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
		}
		case 3: {
			int answers[]             = {1, 0, 2, 0, 1};
			long long expected        = 8LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
		}
		case 4: {
			int answers[]             = {1, 0, 1};
			long long expected        = 0LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int answers[]             = ;
			long long expected        = LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
		}*/
/*      case 6: {
			int answers[]             = ;
			long long expected        = LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
		}*/
/*      case 7: {
			int answers[]             = ;
			long long expected        = LL;

			return verify_case( casenum, expected, Zoo().theCount( vector <int>( answers, answers + ( sizeof answers / sizeof answers[0] ) ) ) );
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
