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

int memo[1000001];

struct RecurrenceRelation {
	int moduloTen(vector <int> v, vector <int> start, int N) {
		memset(memo,0,sizeof(memo));
		for(int i=0, n=v.size(); i<n; ++i){
			if(start[i] < 0) memo[i] = (10 - (abs(start[i])%10))%10;
			else memo[i] = start[i] % 10;
		}
		for(int i=v.size(); i<=N; ++i){
			for(int j=0, n=v.size(); j<n; ++j){
				int next = memo[i-n+j]*v[j];
				if(next < 0) next = (10 -(abs(next)%10))%10;
				else next %= 10;
				(memo[i] += next)%= 10;
			}
		}
		return memo[N];
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
			int coefficients[]        = {2,1};
			int initial[]             = {9,7};
			int N                     = 6;
			int expected              = 5;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}
		case 1: {
			int coefficients[]        = {1,1};
			int initial[]             = {0,1};
			int N                     = 9;
			int expected              = 4;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}
		case 2: {
			int coefficients[]        = {2};
			int initial[]             = {1};
			int N                     = 20;
			int expected              = 6;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}
		case 3: {
			int coefficients[]        = {2};
			int initial[]             = {1};
			int N                     = 64;
			int expected              = 6;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}
		case 4: {
			int coefficients[]        = {25,143};
			int initial[]             = {0,0};
			int N                     = 100000;
			int expected              = 0;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}
		case 5: {
			int coefficients[]        = {9,8,7,6,5,4,3,2,1,0};
			int initial[]             = {1,2,3,4,5,6,7,8,9,10};
			int N                     = 654;
			int expected              = 5;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}
		case 6: {
			int coefficients[]        = {901,492,100};
			int initial[]             = {-6,-15,-39};
			int N                     = 0;
			int expected              = 4;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}

		// custom cases

/*      case 7: {
			int coefficients[]        = ;
			int initial[]             = ;
			int N                     = ;
			int expected              = ;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}*/
/*      case 8: {
			int coefficients[]        = ;
			int initial[]             = ;
			int N                     = ;
			int expected              = ;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
		}*/
/*      case 9: {
			int coefficients[]        = ;
			int initial[]             = ;
			int N                     = ;
			int expected              = ;

			return verify_case( casenum, expected, RecurrenceRelation().moduloTen( vector <int>( coefficients, coefficients + ( sizeof coefficients / sizeof coefficients[0] ) ), vector <int>( initial, initial + ( sizeof initial / sizeof initial[0] ) ), N ) );
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
