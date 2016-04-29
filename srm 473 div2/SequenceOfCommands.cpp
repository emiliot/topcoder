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

void f(int &pi, int &pj, int &face, vector <string> v){
	int movi[] = {1,0,-1,0};
	int movj[] = {0,1,0,-1};
	for(int i=0, n=v.size(); i<n; ++i){
		for(int j=0, m=v[i].size(); j<m; ++j){
			if(v[i][j] == 'S'){
				pi+=movi[face];
				pj += movj[face];
			}else if(v[i][j] == 'R')face=(face+1)%4;
			else if(v[i][j] == 'L')face = face == 0? 3 : face-1;
		}
	}
}

struct SequenceOfCommands {
	string whatHappens(vector <string> commands) {
		int posi = 0, posj = 0;
		int face = 0;
		vector <int> v(10,0);
		for(int i=0; i<10; ++i){
			f(posi,posj,face,commands);
			v[i] = abs(posi)+abs(posj);
		}
		int count = 0;
		for(int i=1; i<10; ++i){
			if(v[i]>v[i-1])++count;
		}
		if(count == 9)return "unbounded";
		else return "bounded";
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
			string commands[]         = {"L"};
			string expected           = "bounded";

			return verify_case( casenum, expected, SequenceOfCommands().whatHappens( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ) ) );
		}
		case 1: {
			string commands[]         = {"SRSL"};
			string expected           = "unbounded";

			return verify_case( casenum, expected, SequenceOfCommands().whatHappens( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ) ) );
		}
		case 2: {
			string commands[]         = {"SSSS","R"};
			string expected           = "bounded";

			return verify_case( casenum, expected, SequenceOfCommands().whatHappens( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ) ) );
		}
		case 3: {
			string commands[]         = {"SRSL","LLSSSSSSL","SSSSSS","L"};
			string expected           = "unbounded";

			return verify_case( casenum, expected, SequenceOfCommands().whatHappens( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ) ) );
		}

		// custom cases

      case 4: {
		  string commands[]         = {"RRRRRRRRRRRRRRRRRRRRR"};
			string expected           = "bounded";

			return verify_case( casenum, expected, SequenceOfCommands().whatHappens( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ) ) );
		}
/*      case 5: {
			string commands[]         = ;
			string expected           = ;

			return verify_case( casenum, expected, SequenceOfCommands().whatHappens( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ) ) );
		}*/
/*      case 6: {
			string commands[]         = ;
			string expected           = ;

			return verify_case( casenum, expected, SequenceOfCommands().whatHappens( vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ) ) );
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
