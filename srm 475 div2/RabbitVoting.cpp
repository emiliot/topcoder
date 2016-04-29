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

struct RabbitVoting {
	string getWinner(vector <string> names, vector <string> votes) {
		map <string, int> m;
		for(int i=0, n=names.size(); i<n; ++i)
			m[names[i]] = 0;
		for(int i=0, n=votes.size(); i<n; ++i){
			if(names[i] == votes[i])continue;
			m[votes[i]]++;
		}
		int best = -1; string res = "";
		map <string,int>::iterator it = m.begin();
		while(it != m.end()){
			if(it ->second > best)res = it->first, best = it->second;
			else if(it -> second == best) res = "";
			it++;
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
			string names[]            = { "Alice", "Bill", "Carol", "Dick" };
			string votes[]            = { "Bill", "Dick", "Alice", "Alice" };
			string expected           = "Alice";

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
		}
		case 1: {
			string names[]            = { "Alice", "Bill", "Carol", "Dick" };
			string votes[]            = { "Carol", "Carol", "Bill", "Bill" };
			string expected           = "";

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
		}
		case 2: {
			string names[]            = { "Alice", "Bill", "Carol", "Dick" };
			string votes[]            = { "Alice", "Alice", "Bill", "Bill" };
			string expected           = "Bill";

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
		}
		case 3: {
			string names[]            = { "Alice", "Bill" };
			string votes[]            = { "Alice", "Bill" };
			string expected           = "";

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
		}
		case 4: {
			string names[]            = { "WhiteRabbit", "whiterabbit", "whiteRabbit", "Whiterabbit" };
			string votes[]            = { "whiteRabbit", "whiteRabbit", "whiteRabbit", "WhiteRabbit" };
			string expected           = "whiteRabbit";

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
		}

		// custom cases

      case 5: {
		  string names[]            = {"a","b","c"};
		  string votes[]            = {"a","c","a"};
			string expected           = "";

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
		}
/*      case 6: {
			string names[]            = ;
			string votes[]            = ;
			string expected           = ;

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
		}*/
/*      case 7: {
			string names[]            = ;
			string votes[]            = ;
			string expected           = ;

			return verify_case( casenum, expected, RabbitVoting().getWinner( vector <string>( names, names + ( sizeof names / sizeof names[0] ) ), vector <string>( votes, votes + ( sizeof votes / sizeof votes[0] ) ) ) );
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
