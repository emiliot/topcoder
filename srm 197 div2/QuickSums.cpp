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

const int INF = 0x3f3f3f3f;
int memo[20][200];
bool mark[20][200];

int f(vector <int> &v, const int sum, int i, int k){
	if(i >= (int)v.size()){
		if(k == sum)return 0;
		else return INF;
	}
	int &best = memo[i][k];
	if(mark[i][k])return best;
	mark[i][k] = true;

	best = INF;
	int next = v[i], j=i+1;
	for(int n=v.size(); j<n; ++j){
		if(next + k <= sum){
			best = min(best, f(v,sum,j,next+k)+1);
			(next *= 10) += v[j];
		}
	}
	if(next + k <= sum)
		best = min(best, f(v,sum,j,k+next));

	return best;
}

struct QuickSums {
	int minSums(string numbers, int sum) {
		vector <int> v(numbers.size());
		for(int i=0, n=v.size(); i<n; ++i)
			v[i] = numbers[i]-'0';
		memset(mark,false,sizeof(mark));
		int res = f(v,sum,0,0);
		if(res >= INF)return -1;
		else return res;
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
			string numbers            = "99999";
			int sum                   = 45;
			int expected              = 4;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}
		case 1: {
			string numbers            = "1110";
			int sum                   = 3;
			int expected              = 3;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}
		case 2: {
			string numbers            = "0123456789";
			int sum                   = 45;
			int expected              = 8;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}
		case 3: {
			string numbers            = "99999";
			int sum                   = 100;
			int expected              = -1;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}
		case 4: {
			string numbers            = "382834";
			int sum                   = 100;
			int expected              = 2;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}
		case 5: {
			string numbers            = "9230560001";
			int sum                   = 71;
			int expected              = 4;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}

		// custom cases

/*      case 6: {
			string numbers            = ;
			int sum                   = ;
			int expected              = ;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}*/
/*      case 7: {
			string numbers            = ;
			int sum                   = ;
			int expected              = ;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
		}*/
/*      case 8: {
			string numbers            = ;
			int sum                   = ;
			int expected              = ;

			return verify_case( casenum, expected, QuickSums().minSums( numbers, sum ) );
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
