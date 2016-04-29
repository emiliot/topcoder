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

struct Matching {
	vector <string> findMatch(vector <string> first, vector <string> second) {
		vector <string> res;
		for(int i=0; i<4; ++i){
			string a = first[i], b = second[i];
			if(a == b){
				res.push_back(a);
				continue;
			}
			if(i == 0){
				if((a == "CIRCLE" && b == "DIAMOND") ||(a == "DIAMOND" && b == "CIRCLE") )res.push_back("SQUIGGLE");
				else if((a == "DIAMOND" && b == "SQUIGGLE")||(a == "SQUIGGLE" && b == "DIAMOND"))res.push_back("CIRCLE");
				else res.push_back("DIAMOND");
			}else if(i == 1){
				if((a == "RED" && b == "GREEN") ||(a == "GREEN" && b == "RED") )res.push_back("BLUE");
				else if((a == "GREEN" && b == "BLUE")||(a == "BLUE" && b == "GREEN"))res.push_back("RED");
				else res.push_back("GREEN");
			}else if(i == 2){
				if((a == "SOLID" && b == "EMPTY") ||(a == "EMPTY" && b == "SOLID") )res.push_back("STRIPED");
				else if((a == "EMPTY" && b == "STRIPED")||(a == "STRIPED" && b == "EMPTY"))res.push_back("SOLID");
				else res.push_back("EMPTY");
			}else{
				if((a == "ONE" && b == "TWO") ||(a == "TWO" && b == "ONE") )res.push_back("THREE");
				else if((a == "TWO" && b == "THREE")||(a == "THREE" && b == "TWO"))res.push_back("ONE");
				else res.push_back("TWO");
			}
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
			string first[]            = {"DIAMOND","BLUE","SOLID","ONE"} ;
			string second[]           = {"DIAMOND","GREEN","SOLID","TWO"} ;
			string expected[]         = { "DIAMOND",  "RED",  "SOLID",  "THREE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Matching().findMatch( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ) ) );
		}
		case 1: {
			string first[]            = {"CIRCLE","GREEN","EMPTY","TWO"} ;
			string second[]           = {"DIAMOND","BLUE","STRIPED","ONE"} ;
			string expected[]         = { "SQUIGGLE",  "RED",  "SOLID",  "THREE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Matching().findMatch( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ) ) );
		}
		case 2: {
			string first[]            = {"DIAMOND","RED","SOLID","ONE"} ;
			string second[]           = {"SQUIGGLE","BLUE","SOLID","TWO"} ;
			string expected[]         = { "CIRCLE",  "GREEN",  "SOLID",  "THREE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Matching().findMatch( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ) ) );
		}
		case 3: {
			string first[]            = {"SQUIGGLE","RED","STRIPED","ONE"} ;
			string second[]           = {"SQUIGGLE","RED","STRIPED","ONE"} ;
			string expected[]         = { "SQUIGGLE",  "RED",  "STRIPED",  "ONE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Matching().findMatch( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			string first[]            = ;
			string second[]           = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Matching().findMatch( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ) ) );
		}*/
/*      case 5: {
			string first[]            = ;
			string second[]           = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Matching().findMatch( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ) ) );
		}*/
/*      case 6: {
			string first[]            = ;
			string second[]           = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Matching().findMatch( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ) ) );
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
