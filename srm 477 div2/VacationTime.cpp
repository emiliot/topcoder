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
// BEGIN CUT HERE

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
const int INF = 0x3f3f3f3f;

int f(const vector <int> &v, int k, int w){
	int count =0;
	for(int i=0, n=v.size(); i<n; ++i){
		if(v[i] >= k && v[i]<=k+w-1)++count;
	}
	return count;
}

struct VacationTime {
	int bestSchedule(int N, int K, vector <int> v) {
		int best = INF;
		sort(all(v));
		for(int i=1; i<=N-K+1; ++i){
			const int next = f(v, i, K);
			best = min(best,next);
		}
		return best;
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
			int N                     = 3;
			int K                     = 3;
			int workingDays[]         = {2};
			int expected              = 1;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
		}
		case 1: {
			int N                     = 4;
			int K                     = 3;
			int workingDays[]         = {3, 1, 2};
			int expected              = 2;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
		}
		case 2: {
			int N                     = 5;
			int K                     = 3;
			int workingDays[]         = {4, 1};
			int expected              = 1;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
		}
		case 3: {
			int N                     = 9;
			int K                     = 2;
			int workingDays[]         = {7, 4, 5, 6, 2};
			int expected              = 0;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
		}
		case 4: {
			int N                     = 1000;
			int K                     = 513;
			int workingDays[]         = {808, 459, 792, 863, 715, 70, 336, 731};
			int expected              = 2;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int workingDays[]         = ;
			int expected              = ;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int workingDays[]         = ;
			int expected              = ;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int workingDays[]         = ;
			int expected              = ;

			return verify_case( casenum, expected, VacationTime().bestSchedule( N, K, vector <int>( workingDays, workingDays + ( sizeof workingDays / sizeof workingDays[0] ) ) ) );
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
