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

int memo[60][60];

struct DNASingleMatcher {
	int longestMatch(string sequence1, string sequence2) {
		//dp de longest common substring
		for(int i=0; i<60; ++i)memo[0][i] = memo[i][0] = 0; //inicializo la primera fila y la primera columna
		int best = 0;
		for(int i=1, n = sequence1.size(); i-1<n;++i){
			for(int j=1, m = sequence2.size(); j-1<m; ++j){
				memo[i][j] = 0;
				if(sequence1[i-1] == sequence2[j-1]){
					memo[i][j] = memo[i-1][j-1]+1;
					best = max(best,memo[i][j]);
				}
			}
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
			string sequence1          = "AAAAAAAAAAAAAAAAAAAAACCCGGGGGGGGGGGGG";
			string sequence2          = "AAAACCCGGGGGGGGGGGGGGGGTTTTTTTTTGGGGGGGGGGGG";
			int expected              = 20;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}
		case 1: {
			string sequence1          = "CAT";
			string sequence2          = "AT";
			int expected              = 2;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}
		case 2: {
			string sequence1          = "TCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTC";
			string sequence2          = "GAGAGGAGAAAGAGAGAGAAGAGAGGAGGAAAGAGAGAGAAAAGAGGGAA";
			int expected              = 0;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}
		case 3: {
			string sequence1          = "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTAC";
			string sequence2          = "GTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGT";
			int expected              = 48;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}
		case 4: {
			string sequence1          = "TC";
			string sequence2          = "CATCAT";
			int expected              = 2;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}
		case 5: {
			string sequence1          = "CGCATTAGATTCAGAG";
			string sequence2          = "CGCATGAGTAGATTC";
			int expected              = 7;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}

		// custom cases

/*      case 6: {
			string sequence1          = ;
			string sequence2          = ;
			int expected              = ;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}*/
/*      case 7: {
			string sequence1          = ;
			string sequence2          = ;
			int expected              = ;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
		}*/
/*      case 8: {
			string sequence1          = ;
			string sequence2          = ;
			int expected              = ;

			return verify_case( casenum, expected, DNASingleMatcher().longestMatch( sequence1, sequence2 ) );
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
