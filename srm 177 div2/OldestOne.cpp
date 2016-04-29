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

struct OldestOne {
	string oldest(vector <string> data) {
		vector <string> names;
		vector <int> ages;
		for(int i=0, n=data.size(); i<n; ++i){
			const int m = data[i].size();
			int k,base,j;
			for(k=0; k<m && data[i][k] == ' '; ++k);
			base = k;
			for(;k<m && !isdigit(data[i][k]); ++k);
			string x = data[i].substr(base,k-base);

			for(j=x.size()-1; j>=0 && x[j] == ' '; --j);
			x = x.substr(0,j+1);
			names.push_back(x);
			x.clear();
			
			for(;k<m && isdigit(data[i][k]);++k)x+=data[i][k];
			ages.push_back(atoi(x.c_str()));
		}
		int high = *max_element(ages.begin(),ages.end());
		for(int i=0, n=ages.size(); i<n; ++i)
			if(ages[i]==high)return names[i];
		return "";
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
			string data[]             = {"DOUG JONES 22 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST"};
			string expected           = "BOB     A SMITH";

			return verify_case( casenum, expected, OldestOne().oldest( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
		case 1: {
			string data[]             = {"DOUG JONES 102 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",  "A 1 999ELM"};
			string expected           = "DOUG JONES";

			return verify_case( casenum, expected, OldestOne().oldest( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
		case 2: {
			string data[]             = {"DOUG JONES 122 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",  "A 199 ELM"};
			string expected           = "A";

			return verify_case( casenum, expected, OldestOne().oldest( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
		case 3: {
			string data[]             = {"   DOUG                 JONES   122 213 ALDEN LANE", "   BOB     A SMITH                       102  3",  " J O H N N Y           199 ELM"};
			string expected           = "J O H N N Y";

			return verify_case( casenum, expected, OldestOne().oldest( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			string data[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, OldestOne().oldest( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}*/
/*      case 5: {
			string data[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, OldestOne().oldest( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}*/
/*      case 6: {
			string data[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, OldestOne().oldest( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
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
