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

bool mark[1 << 12];
int memo[1 << 12];

int f(vector <int> &v, int mask){
	int n = 0;
	for(int i=1, m=v.size(); i<m-1; ++i){
		if(mask &(1 << i))n++;
	}
	if(n == (int)v.size()-2)return 0;
	int &best = memo[mask];
	if(mark[mask])return best;
	mark[mask] = true;
	best = 0;

	for(int i=1, m=v.size(); i<m-1; ++i){
		if(!(mask &(1 << i))){
			int left = i-1, right = i+1;
			while((mask & (1 << left)) && left >= 0)left--;
			while((mask & (1 << right)) && right < m)right++;
			best = max(best, f(v, mask | (1 << i))+(v[left]*v[right]));
		}
	}
	return best;
}

struct CasketOfStarEasy {
	int maxEnergy(vector <int> weight) {
		memset(mark, false, sizeof(mark));
		return f(weight, 0);
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
			int weight[]              = {1,2,3,4};
			int expected              = 12;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
		}
		case 1: {
			int weight[]              = {100,2,1,3,100};
			int expected              = 10400;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
		}
		case 2: {
			int weight[]              = {2,2,7,6,90,5,9};
			int expected              = 1818;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
		}
		case 3: {
			int weight[]              = {477,744,474,777,447,747,777,474};
			int expected              = 2937051;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
		}
		case 4: {
			int weight[]              = {1,1,1,1,1,1,1,1,1,1};
			int expected              = 8;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
		}

		// custom cases

      case 5: {
		  int weight[]              = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int expected              = 8000000;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
		}
/*      case 6: {
			int weight[]              = ;
			int expected              = ;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
		}*/
/*      case 7: {
			int weight[]              = ;
			int expected              = ;

			return verify_case( casenum, expected, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) ) );
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
