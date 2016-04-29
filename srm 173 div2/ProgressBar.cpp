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

struct ProgressBar {
	string showProgress(vector <int> taskTimes, int tasksCompleted) {
		int total = accumulate(taskTimes.begin(),taskTimes.end(),0);
		int done = 0;
		for(int i=0; i<tasksCompleted;++i)
			done += taskTimes[i];
		double aux = (double)(done)*100.0/(double)(total);
		int x = (int)floor(aux*20.0 /100.0);
		string res;
		for(int i=0; i<x; ++i)
			res+="#";
		for(int i=0; i<20-x; ++i)
			res+=".";
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
			int taskTimes[]           = {19,6,23,17};
			int tasksCompleted        = 3;
			string expected           = "##############......";

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
		}
		case 1: {
			int taskTimes[]           = {2,3,7,1,4,3};
			int tasksCompleted        = 4;
			string expected           = "#############.......";

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
		}
		case 2: {
			int taskTimes[]           = {553,846,816,203,101,120,161,818,315,772};
			int tasksCompleted        = 4;
			string expected           = "##########..........";

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
		}
		case 3: {
			int taskTimes[]           = {7,60,468,489,707,499,350,998,1000,716,457,104,597,583,396,862};
			int tasksCompleted        = 2;
			string expected           = "....................";

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
		}
		case 4: {
			int taskTimes[]           = {419,337,853,513,632,861,336,594,94,367,336,297,966,627,399,433,846,859,80,2};
			int tasksCompleted        = 19;
			string expected           = "###################.";

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
		}

		// custom cases

      case 5: {
			int taskTimes[]           = {2, 3, 7, 1, 4, 3};
			int tasksCompleted        = 4;
			string expected           = "#############......."
;

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
		}
/*      case 6: {
			int taskTimes[]           = ;
			int tasksCompleted        = ;
			string expected           = ;

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
		}*/
/*      case 7: {
			int taskTimes[]           = ;
			int tasksCompleted        = ;
			string expected           = ;

			return verify_case( casenum, expected, ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted ) );
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
