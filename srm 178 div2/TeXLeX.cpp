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

struct TeXLeX {
	vector <int> getTokens(string input) {
		vector <int> res;
		for(int i=0, n=input.size(); i<n;){
			if(input[i]!='^'){
				res.push_back(input[i++]);
				continue;
			}
			if(i+3 < n && input[i+1]=='^' && ((input[i+2] >= 'a' && input[i+2]<='f')||(input[i+2] >= '0' && input[i+2]<='9')) && ((input[i+3] >= 'a' && input[i+3]<='f')||(input[i+3] >= '0' && input[i+3]<='9'))){
				int x = isdigit(input[i+2])? input[i+2] - '0' : input[i+2] -'a'+10;
				(x*=16)+= (isdigit(input[i+3])? input[i+3] -'0': input[i+3]-'a'+10);
				if(x == 94){
					input[i+3] = '^';
					i+=3;
				}else{ 
					res.push_back(x);
					i+= 4;
				}
				continue;
			}
			if(i+2 < n && input[i+1] == '^' && input[i+2] > 63){
				int x = input[i+2] - 64;
				if(x == 94){
					input[i+2] = '^';
					i+=2;
				}else {
					res.push_back(x);
					i+=3;
				}
				continue;
			}
			if(i+2 < n &&  input[i+1] == '^' && input[i+2] < 64){
			int x = input[i+2] + 64;
				if(x == 94){
					input[i+2] = '^';
					i+=2;
				}else {
					res.push_back(x);
					i+=3;
				}
				continue;
			}
			if(i < n && input[i] == '^')res.push_back(input[i++]);
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
			string input              = "aAbB cd";
			int expected[]            = { 97,  65,  98,  66,  32,  99,  100 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}
		case 1: {
			string input              = "^^ ^^5e";
			int expected[]            = { 96,  94 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}
		case 2: {
			string input              = "^^";
			int expected[]            = { 94,  94 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}
		case 3: {
			string input              = "^^^5e5e";
			int expected[]            = { 30,  53,  101,  53,  101 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}
		case 4: {
			string input              = "^^5e^5e^5e^5e^ abASFs&*^@%#";
			int expected[]            = { 96,  97,  98,  65,  83,  70,  115,  38,  42,  94,  64,  37,  35 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}
		case 5: {
			string input              = "^^5E ^^40";
			int expected[]            = { 117,  69,  32,  64 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}
		case 6: {
			string input              = "^^`2^^^^OC^^c^^xJ^^Dq9GQpe^^)^^i_&_Q<^^@>|AL8^^d^^";
			int expected[]            = { 32,  50,  30,  94,  79,  67,  35,  56,  74,  4,  113,  57,  71,  81,  112,  101,  105,  41,  95,  38,  95,  81,  60,  0,  62,  124,  65,  76,  56,  36,  94,  94 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}

		// custom cases

/*      case 7: {
			string input              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}*/
/*      case 8: {
			string input              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
		}*/
/*      case 9: {
			string input              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), TeXLeX().getTokens( input ) );
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
