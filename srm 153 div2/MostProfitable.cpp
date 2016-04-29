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

struct MostProfitable {
	string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items) {
		int best = 0, k = 0;
		for(int i=0, n=costs.size(); i<n; ++i){
			int nextP = (prices[i]-costs[i])*sales[i];
			if(nextP > best){
				best = nextP;
				k = i;
			}
		}
		if(best > 0)return items[k];
		else return "";
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
			int costs[]               = {100,120,150,1000};
			int prices[]              = {110,110,200,2000};
			int sales[]               = {20,100,50,3};
			string items[]            = {"Video Card","256M Mem","CPU/Mobo combo","Complete machine"};
			string expected           = "Complete machine";

			return verify_case( casenum, expected, MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}
		case 1: {
			int costs[]               = {100};
			int prices[]              = {100};
			int sales[]               = {134};
			string items[]            = {"Service, at cost"};
			string expected           = "";

			return verify_case( casenum, expected, MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}
		case 2: {
			int costs[]               = {38,24};
			int prices[]              = {37,23};
			int sales[]               = {1000,643};
			string items[]            = {"Letter","Postcard"};
			string expected           = "";

			return verify_case( casenum, expected, MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}
		case 3: {
			int costs[]               = {10,10};
			int prices[]              = {11,12};
			int sales[]               = {2,1};
			string items[]            = {"A","B"};
			string expected           = "A";

			return verify_case( casenum, expected, MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int costs[]               = ;
			int prices[]              = ;
			int sales[]               = ;
			string items[]            = ;
			string expected           = ;

			return verify_case( casenum, expected, MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}*/
/*      case 5: {
			int costs[]               = ;
			int prices[]              = ;
			int sales[]               = ;
			string items[]            = ;
			string expected           = ;

			return verify_case( casenum, expected, MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}*/
/*      case 6: {
			int costs[]               = ;
			int prices[]              = ;
			int sales[]               = ;
			string items[]            = ;
			string expected           = ;

			return verify_case( casenum, expected, MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
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
