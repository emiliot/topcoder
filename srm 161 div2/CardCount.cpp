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

struct CardCount {
	vector <string> dealHands(int numPlayers, string deck) {
		vector <string> res(numPlayers, "");
		for(int i=0, n=deck.size()/numPlayers; i<n; ++i){
			for(int j=0; j<numPlayers; j++)
				res[j] += deck[(i*numPlayers)+j];
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
	template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case( int casenum, const vector <string> &expected, const vector <string> &received ) { 
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
			int numPlayers            = 6;
			string deck               = "012345012345012345";
			string expected[]         = { "000",  "111",  "222",  "333",  "444",  "555" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
		}
		case 1: {
			int numPlayers            = 4;
			string deck               = "111122223333";
			string expected[]         = { "123",  "123",  "123",  "123" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
		}
		case 2: {
			int numPlayers            = 1;
			string deck               = "012345012345012345";
			string expected[]         = { "012345012345012345" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
		}
		case 3: {
			int numPlayers            = 6;
			string deck               = "01234";
			string expected[]         = { "",  "",  "",  "",  "",  "" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
		}
		case 4: {
			int numPlayers            = 2;
			string deck               = "";
			string expected[]         = { "",  "" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
		}

		// custom cases

/*      case 5: {
			int numPlayers            = ;
			string deck               = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
		}*/
/*      case 6: {
			int numPlayers            = ;
			string deck               = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
		}*/
/*      case 7: {
			int numPlayers            = ;
			string deck               = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CardCount().dealHands( numPlayers, deck ) );
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
