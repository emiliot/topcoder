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

int f(string &train, string &s){
	int n = min(train.size()-1, s.size()-1);
	for(;n>0;n--){
		if(train.substr(train.size()-n,n) == s.substr(0,n))
			return n;
	}
	return n;
}

string g(string &s){
	string res; int x = s.size();
	bool mark[27]; memset(mark,false,sizeof(mark));
	for(int i=s.size()-1; i>=0; i--)if(!mark[s[i]-'A']){
		mark[s[i]-'A'] = true;
		res += s[i];
	}
	char buffer[100]; sprintf(buffer,"%d",x);
	reverse(buffer, buffer + strlen(buffer));
	(res += " ")+=buffer;
	reverse(all(res));
	return res;
}

struct StringTrain {
	string buildTrain(vector <string> cars) {
		string train = cars[0];
		set <int> mark; set <string> prefixes;
		for(int i=1, n=cars.size(); i<n; ++i){
			int best = 0;
		}
		return g(train);
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
			string cars[]             = {"ABCDE","CDFFF","CDE","CDEGG","GABC"};
			string expected           = "10 DEGABC";

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
		}
		case 1: {
			string cars[]             = {"AAAAA","AAAAA","AAAAA"};
			string expected           = "7 A";

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
		}
		case 2: {
			string cars[]             = {"CABABDABAB","CABAB","ABABDABAB","DABAB"};
			string expected           = "15 CDAB";

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
		}
		case 3: {
			string cars[]             = {"ABABAB","ABABAB","ABABABAB","BZZZZZ"};
			string expected           = "15 ABZ";

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
		}
		case 4: {
			string cars[]             = {"A","A","A","AA"};
			string expected           = "1 A";

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string cars[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
		}*/
/*      case 6: {
			string cars[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
		}*/
/*      case 7: {
			string cars[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, StringTrain().buildTrain( vector <string>( cars, cars + ( sizeof cars / sizeof cars[0] ) ) ) );
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
