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

int f(int w, int h, int k, vector<int> box){
	if(k>8)return -1;
	if((w<=box[0] && h<=box[1])||(w<=box[1] && h<=box[0]))return k;
	box[0]*=2;
	int r1 = f(w,h,k+1,box);
	box[0]/=2;
	box[1]*=2;
	int r2 = f(w,h,k+1,box);
	box[1]/=2;
	if(r1==-1)return r2;
	else if(r2 == -1)return r1;
	else return min(r1,r2);
}

struct PaperFold {
	int numFolds(vector <int> paper, vector <int> box) {
		return f(paper[0],paper[1],0,box);
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
			int paper[]               = {8, 11};
			int box[]                 = {6, 10};
			int expected              = 1;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}
		case 1: {
			int paper[]               = {11, 17};
			int box[]                 = {6, 4};
			int expected              = 4;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}
		case 2: {
			int paper[]               = {11, 17};
			int box[]                 = {5, 4};
			int expected              = 4;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}
		case 3: {
			int paper[]               = {1000,1000};
			int box[]                 = {62,63};
			int expected              = -1;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}
		case 4: {
			int paper[]               = {100,30};
			int box[]                 = {60,110};
			int expected              = 0;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}
		case 5: {
			int paper[]               = {1895, 6416};
			int box[]                 = {401, 1000};
			int expected              = 5;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			int paper[]               = ;
			int box[]                 = ;
			int expected              = ;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}*/
/*      case 7: {
			int paper[]               = ;
			int box[]                 = ;
			int expected              = ;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
		}*/
/*      case 8: {
			int paper[]               = ;
			int box[]                 = ;
			int expected              = ;

			return verify_case( casenum, expected, PaperFold().numFolds( vector <int>( paper, paper + ( sizeof paper / sizeof paper[0] ) ), vector <int>( box, box + ( sizeof box / sizeof box[0] ) ) ) );
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
