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

struct RaceApproximator {
	string timeToBeat(int d1, int t1, int d2, int t2, int raceDistance) {
		int t = t1*exp((double)(log((double)(t2)/(double)(t1))*log((double)(d1)/(double)(raceDistance))/log((double)(d1)/(double)(d2))));
		int h = t/3600, m = (t%3600)/60, s = (t%3600)%60;
		string res;
		char buffer[20];
		if(h == 0)res += "0:";
		else{
			sprintf(buffer,"%d:",h);
			res += string(buffer);
		}
		if(m == 0)res += "00:";
		else if(m < 10){
			sprintf(buffer,"0%d:",m);
			res += string(buffer);
		}else{
			sprintf(buffer,"%d:",m);
			res += string(buffer);
		}
		if(s == 0)res += "00";
		else if(s < 10){
			sprintf(buffer,"0%d",s);
			res += string(buffer);
		}else{
			sprintf(buffer,"%d",s);
			res += string(buffer);
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
			int d1                    = 800;
			int t1                    = 118;
			int d2                    = 5000;
			int t2                    = 906;
			int raceDistance          = 1500;
			string expected           = "0:03:57";

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
		}
		case 1: {
			int d1                    = 400;
			int t1                    = 65;
			int d2                    = 1600;
			int t2                    = 350;
			int raceDistance          = 800;
			string expected           = "0:02:30";

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
		}
		case 2: {
			int d1                    = 1600;
			int t1                    = 299;
			int d2                    = 10000;
			int t2                    = 2360;
			int raceDistance          = 5000;
			string expected           = "0:18:00";

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
		}
		case 3: {
			int d1                    = 100;
			int t1                    = 17;
			int d2                    = 10000;
			int t2                    = 4500;
			int raceDistance          = 9000;
			string expected           = "1:06:00";

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
		}
		case 4: {
			int d1                    = 156;
			int t1                    = 117;
			int d2                    = 3863;
			int t2                    = 2754;
			int raceDistance          = 1755;
			string expected           = "0:21:06";

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
		}

		// custom cases

/*      case 5: {
			int d1                    = ;
			int t1                    = ;
			int d2                    = ;
			int t2                    = ;
			int raceDistance          = ;
			string expected           = ;

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
		}*/
/*      case 6: {
			int d1                    = ;
			int t1                    = ;
			int d2                    = ;
			int t2                    = ;
			int raceDistance          = ;
			string expected           = ;

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
		}*/
/*      case 7: {
			int d1                    = ;
			int t1                    = ;
			int d2                    = ;
			int t2                    = ;
			int raceDistance          = ;
			string expected           = ;

			return verify_case( casenum, expected, RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance ) );
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
