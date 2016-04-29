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

#define MAX_INP 1000010
#define MAX_OUT 4500
#define INF 0x3f3f3f3f

int prod3[MAX_INP], sum[MAX_INP], first[MAX_INP], smallest[MAX_INP];

void init(){
	int n, digits[30];
	for(int i=1; i<MAX_INP; ++i){
		n = 0, sum[i] = 0, prod3[i] = 1;
		int next = i;
		while(next > 0){
			digits[n] = next % 10, next/=10;
			sum[i] += digits[n];
			n++;
		}
		first[i] = digits[n-1];
		sort(digits, digits + n);
		smallest[i] = digits[0];
		
		for(int j=0, k=n-1; j<3 && k >= 0; ++j, --k)
			prod3[i] *= digits[k];
	}
}

int f(int x, int y){
	return 5 * prod3[x] + sum[y] * first[x] + smallest[y];
}

struct NewOperator {
	int minimumCount(int x, int goal) {
		if(x == goal)return 0;
		if(goal >= MAX_OUT)return -1;
		init();

		vector <int> best(MAX_OUT, INF);
		vector < vector <int> > v(MAX_OUT);
		v[0].push_back(x);

		for(int distance=1; distance < MAX_OUT; distance++){
			for(int d1 = 0; d1 < distance; d1 ++){
				int d2 = distance - d1 - 1;

				for(int i=0, n=v[d1].size(); i<n; ++i){
					for(int j=0, m=v[d2].size(); j<m; ++j){
						int x = v[d1][i], y = v[d2][j];
						int z = f(x,y);
						if(distance < best[z]){
							best[z] = distance;
							v[distance].push_back(z);
						}
					}
				}
			}
		}
		if(best[goal] >= INF)return -1;
		return best[goal];

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
			int x                     = 13;
			int goal                  = 13;
			int expected              = 0;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}
		case 1: {
			int x                     = 374;
			int goal                  = 465;
			int expected              = 1;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}
		case 2: {
			int x                     = 374;
			int goal                  = 469;
			int expected              = 2;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}
		case 3: {
			int x                     = 374;
			int goal                  = 659;
			int expected              = 2;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}
		case 4: {
			int x                     = 374;
			int goal                  = 1024;
			int expected              = 8;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}
		case 5: {
			int x                     = 654321;
			int goal                  = 12;
			int expected              = 10;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}
		case 6: {
			int x                     = 654321;
			int goal                  = 1234567;
			int expected              = -1;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}

		// custom cases

/*      case 7: {
			int x                     = ;
			int goal                  = ;
			int expected              = ;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}*/
/*      case 8: {
			int x                     = ;
			int goal                  = ;
			int expected              = ;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
		}*/
/*      case 9: {
			int x                     = ;
			int goal                  = ;
			int expected              = ;

			return verify_case( casenum, expected, NewOperator().minimumCount( x, goal ) );
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
