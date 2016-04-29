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

vector <int> v;
int cost, jobs;
const int INF = 0x3f3f3f3f;

bool mark[51][51];
int memo[51][51];

int f(int foxes, int left){
	if(left <= 0)return 0;

	int &best = memo[foxes][left];
	if(mark[foxes][left])return best;
	mark[foxes][left] = true;

	best = INF;
	if(foxes >= left){
		//enough foxes to solve all tasks, return the longest
		best = v[jobs - left];
	}else{
		//try assigning i foxes to work and split the rest
		for(int i=0; i<foxes; ++i){
			int nfoxes = (foxes - i) * 2;
			nfoxes = min(nfoxes, left - i);
			int next = f(nfoxes, left - i) + cost;
			best = min(best, max(next, v[jobs - left]));
		}
	}
	return best;
}

struct FoxAndDoraemon {
	int minTime(vector <int> workCost, int splitCost) {
		v.assign(all(workCost));
		cost = splitCost, jobs = workCost.size();
		sort(all(v), greater<int>());
		memset(mark, false, sizeof(mark));
		int res = f(1, (int)workCost.size());
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
			int workCost[]            = {1,2};
			int splitCost             = 1000;
			int expected              = 1002;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 1: {
			int workCost[]            = {3,6,9,12};
			int splitCost             = 1000;
			int expected              = 2012;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 2: {
			int workCost[]            = {1000,100,10,1};
			int splitCost             = 1;
			int expected              = 1001;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 3: {
			int workCost[]            = {1712,1911,1703,1610,1697,1612};
			int splitCost             = 100;
			int expected              = 2012;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 4: {
			int workCost[]            = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
			int splitCost             = 3000;
			int expected              = 15000;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 5: {
			int workCost[]            = {58};
			int splitCost             = 3600;
			int expected              = 58;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}

		// custom cases

/*      case 6: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}*/
/*      case 7: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}*/
/*      case 8: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
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
