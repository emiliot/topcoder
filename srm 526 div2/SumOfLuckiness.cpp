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

i64 memo[11][11][11][2];
bool mark[11][11][11][2];

i64 g(string &s, int i, int n4, int n7, bool ok){
	if(i >= (int)s.size()){
		return (i64)(abs(n4-n7));
	}
	i64 &count  = memo[i][n4][n7][ok];
	if(mark[i][n4][n7][ok])return count;
	mark[i][n4][n7][ok] = true;
	count = 0LL;
	for(int k=0; k<=9; ++k){
		if(!ok){
			if(k < s[i]-'0')
				count += g(s,i+1,k==4? n4+1 : n4, k==7? n7+1:n7, true);
			else if(k == s[i]-'0')
				count += g(s,i+1,k==4? n4+1 : n4, k==7? n7+1:n7, false);
		}else{
			count += g(s,i+1,k==4? n4+1 : n4, k==7? n7+1:n7, ok);
		}
	}

	return count;
}

i64 f(int x){
	char buffer[20];
	sprintf(buffer, "%d", x);
	string s(buffer);
	memset(mark, false, sizeof(mark));
	return g(s,0,0,0, false);
}

struct SumOfLuckiness {
	long long theSum(int A, int B) {
		return f(B) - f(A-1);
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
			int A                     = 1;
			int B                     = 10;
			long long expected        = 2LL;

			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
		}
		case 1: {
			int A                     = 40;
			int B                     = 47;
			long long expected        = 8LL;

			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
		}
		case 2: {
			int A                     = 58;
			int B                     = 526;
			long long expected        = 231LL;
			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
		}
		case 3: {
			int A                     = 4444;
			int B                     = 7777;
			long long expected        = 2338LL;

			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
		}
		case 4: {
			int A                     = 585858585;
			int B                     = 858585858;
			long long expected        = 287481025LL;

			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
		}

		// custom cases

      case 5: {
			int A                     = 1;
			int B                     = 50;
			long long expected        = 18LL;
			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
		}
/*      case 6: {
			int A                     = ;
			int B                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, SumOfLuckiness().theSum( A, B ) );
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
