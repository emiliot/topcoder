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
typedef long long i64;
i64 memo[60];
bool mark[60];

i64 f(vector <string> &v, int i){
	int sub = 0;
	for(int k=0,n=v.size(); k<n; ++k)
		if(v[i][k] == 'Y')++sub;
	if(sub == 0)return 1;
	i64 &best = memo[i];
	if(mark[i])return best;
	mark[i] = true;
	best = 0;
	for(int j=0,n=v.size(); j<n; ++j)
		if(v[i][j] == 'Y')best+=f(v,j);
	return best;
}

struct CorporationSalary {
  long long totalSalary(vector <string> v) {
	  memset(mark,false,sizeof(mark));
	  i64 res = 0;
	  for(int i=0,n=v.size(); i<n; ++i)
		  res += f(v,i);
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
	
	int verify_case( int casenum, const long long &expected, const long long &received ) { 
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
			string relations[]        = {"N"};
			long long expected        = 1LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
		}
		case 1: {
			string relations[]        = {"NNYN",  "NNYN",  "NNNN",  "NYYN"};
			long long expected        = 5LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
		}
		case 2: {
			string relations[]        = {"NNNNNN",  "YNYNNY",  "YNNNNY",  "NNNNNN",  "YNYNNN",  "YNNYNN"};
			long long expected        = 17LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
		}
		case 3: {
			string relations[]        = {"NYNNYN",  "NNNNNN",  "NNNNNN",  "NNYNNN",  "NNNNNN",  "NNNYYN"};
			long long expected        = 8LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
		}
		case 4: {
			string relations[]        = {"NNNN",  "NNNN",  "NNNN",  "NNNN"};
			long long expected        = 4LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string relations[]        = ;
			long long expected        = LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
		}*/
/*      case 6: {
			string relations[]        = ;
			long long expected        = LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
		}*/
/*      case 7: {
			string relations[]        = ;
			long long expected        = LL;

			return verify_case( casenum, expected, CorporationSalary().totalSalary( vector <string>( relations, relations + ( sizeof relations / sizeof relations[0] ) ) ) );
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
