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
const int INF = 0x3f3f3f3f;
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

int memo[1 << 7][2];
bool mark[1 << 7][2];

int f(const vector <int> &v, int mask, bool light){
	int right = 0;
	for(int i=0, n=v.size(); i<n; ++i){
		if(mask &(1 << i))right++;
	}
	if(right == (int)v.size())return 0;
	
	int &best = memo[mask][light];
	if(mark[mask][light])return best;
	mark[mask][light] = true;
	best = INF;
	if(!light){//light on left side
		for(int i=0, n=v.size(); i<n;++i){
			if(!(mask & (1 << i))){
				int count = 0;
				for(int j=0; j<n; ++j){
					if(i == j)continue;
					count++;
					if(!(mask & (1 <<j))){
						int time = max(v[i], v[j]);
						int nextMask = mask | (1<<i) | (1 << j);
						best = min(best, f(v, nextMask, true) + time);
					}
				}
				if(count == 0)return v[i];
			}
		}
	}else{//light on right side
		for(int i=0, n=v.size(); i<n; ++i){
			if(mask &(1 << i)){
				int nextMask = mask ^(1 << i);
				best = min(best, f(v, nextMask, false) + v[i]);
			}
		}
	}
	return best;
}

struct BridgeCrossing {
	int minTime(vector <int> times) {
		memset(mark, false, sizeof(mark));
		return f(times, 0, false);
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
			int times[]               = { 1, 2, 5, 10 };
			int expected              = 17;

			return verify_case( casenum, expected, BridgeCrossing().minTime( vector <int>( times, times + ( sizeof times / sizeof times[0] ) ) ) );
		}
		case 1: {
			int times[]               = { 1, 2, 3, 4, 5 };
			int expected              = 16;

			return verify_case( casenum, expected, BridgeCrossing().minTime( vector <int>( times, times + ( sizeof times / sizeof times[0] ) ) ) );
		}
		case 2: {
			int times[]               = { 100 };
			int expected              = 100;

			return verify_case( casenum, expected, BridgeCrossing().minTime( vector <int>( times, times + ( sizeof times / sizeof times[0] ) ) ) );
		}
		case 3: {
			int times[]               = { 1, 2, 3, 50, 99, 100 };
			int expected              = 162;

			return verify_case( casenum, expected, BridgeCrossing().minTime( vector <int>( times, times + ( sizeof times / sizeof times[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int times[]               = ;
			int expected              = ;

			return verify_case( casenum, expected, BridgeCrossing().minTime( vector <int>( times, times + ( sizeof times / sizeof times[0] ) ) ) );
		}*/
/*      case 5: {
			int times[]               = ;
			int expected              = ;

			return verify_case( casenum, expected, BridgeCrossing().minTime( vector <int>( times, times + ( sizeof times / sizeof times[0] ) ) ) );
		}*/
/*      case 6: {
			int times[]               = ;
			int expected              = ;

			return verify_case( casenum, expected, BridgeCrossing().minTime( vector <int>( times, times + ( sizeof times / sizeof times[0] ) ) ) );
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
