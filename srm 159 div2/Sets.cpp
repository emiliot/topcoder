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
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
// BEGIN CUT HERE

typedef long long i64;
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

struct Sets {
	vector <int> operate(vector <int> A, vector <int> B, string operation) {
		make_unique(A);
		make_unique(B);
		vector <int> res;
		if(operation == "UNION")set_union(all(A),all(B),back_inserter(res));
		else if(operation == "INTERSECTION")set_intersection(all(A),all(B),back_inserter(res));
		else set_symmetric_difference(all(A),all(B),back_inserter(res));
		set_union(A.begin(), A.end(), B.begin(), B.end(), ostream_iterator<int>(cout, "\n"));
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
			int A[]                   = {1,2,3,4};
			int B[]                   = {3,4,5,6};
			string operation          = "INTERSECTION";
			int expected[]            = { 3,  4 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
		}
		case 1: {
			int A[]                   = {1,2,3,4};
			int B[]                   = {3,4,5,6};
			string operation          = "UNION";
			int expected[]            = { 1,  2,  3,  4,  5,  6 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
		}
		case 2: {
			int A[]                   = {432,756,123};
			int B[]                   = {534,76,1209};
			string operation          = "INTERSECTION";
			int expected[]            = {-1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
		}
		case 3: {
			int A[]                   = {6,5,7,4};
			int B[]                   = {7,6,4,10};
			string operation          = "SYMMETRIC DIFFERENCE";
			int expected[]            = { 5,  10 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
		}
		case 4: {
			int A[]                   = {342,654,897,312,76,23,78};
			int B[]                   = {21,43,87,98,23,756,897,234,645,876,123};
			string operation          = "SYMMETRIC DIFFERENCE";
			int expected[]            = { 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
		}

		// custom cases

/*      case 5: {
			int A[]                   = ;
			int B[]                   = ;
			string operation          = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
		}*/
/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			string operation          = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
		}*/
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			string operation          = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Sets().operate( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operation ) );
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
