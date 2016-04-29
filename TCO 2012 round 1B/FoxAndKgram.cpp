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

bool ok(vector <int> &v, int k){
	vector <bool> mark(v.size(), false);
	int rows = 0;
	for(; rows < k; ++rows){
		bool found = false;
		for(int i=0, n=v.size(); i<n && !found; ++i){
			if(mark[i])continue;
			if(v[i] == k){
				found = true;
				mark[i] = true;
			}else if(v[i] < k){
				for(int j=0; j<n && !found; ++j){
					if(!mark[j] && i!=j && v[j] + v[i] == k-1){
						found = true;
						mark[i] = mark[j] = true;
						break;
					}
				}
			}
		}
		if(!found)return false;
	}
	return true;
}

struct FoxAndKgram {
	int maxK(vector <int> len) {
		sort(all(len));
		for(int i=50; i>0; --i){
			if(ok(len, i))return i;
		}
		return 0;
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
			int len[]                 = {1,1,1,1,3};
			int expected              = 3;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}
		case 1: {
			int len[]                 = {2,2,1,3,5,5,5};
			int expected              = 5;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}
		case 2: {
			int len[]                 = {1};
			int expected              = 1;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}
		case 3: {
			int len[]                 = {2,2,2,2,2,2,2,2,2,2};
			int expected              = 5;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}
		case 4: {
			int len[]                 = {1,2,3,1,2,4,2,3,1};
			int expected              = 4;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}
		case 5: {
			int len[]                 = {2,3,5,7,11,13,17,19,23,29};
			int expected              = 0;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			int len[]                 = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}*/
/*      case 7: {
			int len[]                 = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
		}*/
/*      case 8: {
			int len[]                 = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndKgram().maxK( vector <int>( len, len + ( sizeof len / sizeof len[0] ) ) ) );
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
