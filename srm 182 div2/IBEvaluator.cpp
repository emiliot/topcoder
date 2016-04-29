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

struct IBEvaluator {
	vector <int> getSummary(vector <int> pred, vector <int> real) {
		vector <int> res(7,0);
		for(int i=0,n=pred.size(); i<n; ++i)
			res[abs(pred[i]-real[i])]++;
		for(int i=0; i<7; ++i){
			res[i] = (res[i]*100)/pred.size();
		}
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received ) { 
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
			int predictedGrades[]     = {1,5,7,3};
			int actualGrades[]        = {3,5,4,5};
			int expected[]            = { 25,  0,  50,  25,  0,  0,  0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) ) );
		}
		case 1: {
			int predictedGrades[]     = {1,1,1};
			int actualGrades[]        = {5,6,7};
			int expected[]            = { 0,  0,  0,  0,  33,  33,  33 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) ) );
		}
		case 2: {
			int predictedGrades[]     = {3};
			int actualGrades[]        = {3};
			int expected[]            = { 100,  0,  0,  0,  0,  0,  0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) ) );
		}
		case 3: {
			int predictedGrades[]     = {1,5,3,5,6,4,2,5,7,6,5,2,3,4,1,4,6,5,4,7,6,6,1};
			int actualGrades[]        = {5,1,3,2,6,4,1,7,5,2,7,4,2,6,5,7,3,1,4,6,3,1,7};
			int expected[]            = { 17,  13,  21,  17,  21,  4,  4 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int predictedGrades[]     = ;
			int actualGrades[]        = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) ) );
		}*/
/*      case 5: {
			int predictedGrades[]     = ;
			int actualGrades[]        = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) ) );
		}*/
/*      case 6: {
			int predictedGrades[]     = ;
			int actualGrades[]        = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) ) );
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
