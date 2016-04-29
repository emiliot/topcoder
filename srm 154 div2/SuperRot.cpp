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

struct SuperRot {
	string decoder(string message) {
		string a = "nopqrstuvwxyz", b = "abcdefghijklm";
		string A = "NOPQRSTUVWXYZ",	B = "ABCDEFGHIJKLM";
		string n1 = "56789", n2 = "01234";
		string res = "";
		for(int i=0,n=message.size(); i<n; ++i){
			char next = message[i];
			if(next >= 'A' && next <= 'M')next = A[next - 'A'];
			else if(next >= 'N' && next <= 'Z')next = B[next -'N'];
			else if(next >= 'a' && next <= 'm')next = a[next-'a'];
			else if(next >= 'n' && next <= 'z')next = b[next - 'n'];
			else if(next >= '0' && next <= '4')next = n1[next - '0'];
			else if(next >= '5' && next <= '9')next = n2[next - '5'];
			res += next;
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
	
	int verify_case( int casenum, const string &expected, const string &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string message            = "Uryyb 28";
			string expected           = "Hello 73";

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}
		case 1: {
			string message            = "GbcPbqre";
			string expected           = "TopCoder";

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}
		case 2: {
			string message            = "";
			string expected           = "";

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}
		case 3: {
			string message            = "5678901234";
			string expected           = "0123456789";

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}
		case 4: {
			string message            = "NnOoPpQqRr AaBbCcDdEe";
			string expected           = "AaBbCcDdEe NnOoPpQqRr";

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}
		case 5: {
			string message            = "Gvzr vf 54 71 CZ ba Whyl 4gu bs gur lrne 7558 NQ";
			string expected           = "Time is 09 26 PM on July 9th of the year 2003 AD";

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}
		case 6: {
			string message            = "Gur dhvpx oebja sbk whzcf bire n ynml qbt";
			string expected           = "The quick brown fox jumps over a lazy dog";

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}

		// custom cases

/*      case 7: {
			string message            = ;
			string expected           = ;

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}*/
/*      case 8: {
			string message            = ;
			string expected           = ;

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
		}*/
/*      case 9: {
			string message            = ;
			string expected           = ;

			return verify_case( casenum, expected, SuperRot().decoder( message ) );
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
