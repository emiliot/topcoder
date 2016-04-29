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

i64 memo[102][52][52][2];
bool mark[102][52][52][2];

int D, H;
vector <int> v;
int moveH[3] = {-1, 0, 1};

i64 f(int d, int h, int i, bool high){
	if(h > H)return 0LL;
	if(h < 0)return 0LL;
	if(h == 0){
		if(d == D && high && i >= (int)v.size())return 1LL;
		else if(d > 0) return 0LL;
	}
	if(d >= D)return 0LL;

	i64 &count = memo[d][h][i][high];
	if(mark[d][h][i][high])return count;
	mark[d][h][i][high] = true;
	count = 0LL;

	for(int k=0; k<3; ++k){
		int next = h + moveH[k];
		if(i < (int) v.size() && next == v[i]){
			count += f(d+1, next, i+1, next == H || high);
		}else{
			count += f(d+1, next, i, next == H || high);
		}
	}
	return count;
}

struct HillHike {
	long long numPaths(int distance, int maxHeight, vector <int> landmarks) {
		memset(mark, false, sizeof(mark));
		v.assign(all(landmarks));
		D = distance, H = maxHeight;
		i64 res = f(0, 0, 0, false);
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
			int distance              = 59;
			int maxHeight             = 20;
			int landmarks[]           = {1, 9, 20, 18, 11, 13, 1};
			long long expected        = 469509251919309;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
		}
		case 1: {
			int distance              = 41;
			int maxHeight             = 3;
			int landmarks[]           = {1, 1, 2, 3, 3, 1, 2, 1, 2, 2, 3};
			long long expected        = 115742120360885;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
		}
		case 2: {
			int distance              = 5;
			int maxHeight             = 2;
			int landmarks[]           = {2,2};
			long long expected        = 1LL;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
		}
		case 3: {
			int distance              = 8;
			int maxHeight             = 3;
			int landmarks[]           = {2,2,3,1};
			long long expected        = 7LL;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
		}
		case 4: {
			int distance              = 38;
			int maxHeight             = 11;
			int landmarks[]           = {4,5,8,5,6};
			long long expected        = 201667830444LL;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int distance              = ;
			int maxHeight             = ;
			int landmarks[]           = ;
			long long expected        = LL;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
		}*/
/*      case 6: {
			int distance              = ;
			int maxHeight             = ;
			int landmarks[]           = ;
			long long expected        = LL;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
		}*/
/*      case 7: {
			int distance              = ;
			int maxHeight             = ;
			int landmarks[]           = ;
			long long expected        = LL;

			return verify_case( casenum, expected, HillHike().numPaths( distance, maxHeight, vector <int>( landmarks, landmarks + ( sizeof landmarks / sizeof landmarks[0] ) ) ) );
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
