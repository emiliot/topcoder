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

struct FontSize {
	int getPixelWidth(string sentence, vector <int> uppercase, vector <int> lowercase) {
		int res = 0;
		for(int i=0, n=sentence.size(); i<n; ++i){
			if(sentence[i] >= 'A' && sentence[i]<='Z')
				res += uppercase[sentence[i]-'A'];
			else if(sentence[i] >= 'a' && sentence[i]<='z')
				res += lowercase[sentence[i]-'a'];
			else res+= 3;
			++res;
		}
		return res-1;
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
			string sentence           = "Dead Beef";
			int uppercase[]           = {6,6,6,7,7,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
			int lowercase[]           = {5,5,5,4,4,4,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
			int expected              = 49;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
		}
		case 1: {
			string sentence           = "Hello World";
			int uppercase[]           = {7,8,8,8,7,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8};
			int lowercase[]           = {5,6,6,6,5,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6};
			int expected              = 74;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
		}
		case 2: {
			string sentence           = "Hello World";
			int uppercase[]           = {7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,7,7,7};
			int lowercase[]           = {5,5,5,6,6,5,5,5,5,5,5,1,5,5,6,5,5,6,5,5,5,5,5,5,5,5};
			int expected              = 63;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
		}
		case 3: {
			string sentence           = "ThE qUiCk BrOwN fOx JuMpEd OvEr ThE lAzY dOg";
			int uppercase[]           = {36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11};
			int lowercase[]           = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
			int expected              = 778;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
		}
		case 4: {
			string sentence           = "two  spaces";
			int uppercase[]           = {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
			int lowercase[]           = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
			int expected              = 43;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string sentence           = ;
			int uppercase[]           = ;
			int lowercase[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
		}*/
/*      case 6: {
			string sentence           = ;
			int uppercase[]           = ;
			int lowercase[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
		}*/
/*      case 7: {
			string sentence           = ;
			int uppercase[]           = ;
			int lowercase[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, FontSize().getPixelWidth( sentence, vector <int>( uppercase, uppercase + ( sizeof uppercase / sizeof uppercase[0] ) ), vector <int>( lowercase, lowercase + ( sizeof lowercase / sizeof lowercase[0] ) ) ) );
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
