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

struct hour{
	int h, m, s;
	hour(){h=m=s=0;}
	hour(int _h, int _m, int _s):
	h(_h),m(_m),s(_s){}
	bool operator <(const hour &x)const{
		int s1 = (x.h*3600)+(x.m*60)+x.s;
		int s2 = (h*3600)+(m*60)+s;
		return s1 < s2;
	}
	bool operator ==(const hour &x)const{
		return (x.h == h && x.m == m && x.s == s);
	}
};

struct BadClock {
	double nextAgreement(string trueTime, string skewTime, int dt){
		stringstream s1(trueTime), s2(skewTime);
		hour h1, h2; char c;
		s1 >> h1.h >> c >> h1.m >> c >> h1.s;
		s2 >> h2.h >> c >> h2.m >> c >> h2.s;
		if(h1 == h2)return 0.0;
		int t1 = (h1.h*3600)+(h1.m*60)+h1.s;
		int t2 = (h2.h*3600)+(h2.m*60)+h2.s;
		if(dt < 0){
			swap(t1,t2);
			dt = -dt;
		}
		if(t1 -t2 < 0) t1 += 12*3600;
		double res = (double)(t1-t2)/(double)(dt);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case( int casenum, const double &expected, const double &received ) { 
		cerr << "Example " << casenum << "... "; 
		cerr.precision(9); 
		if ( topcoder_fequ( expected, received ) ) {
			cerr << "PASSED"; 
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) cerr << " (relative error " << rerr << ")";
			cerr << endl;
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
			string trueTime           = "07:07:07";
			string skewTime           = "07:07:07";
			int hourlyGain            = 1776;
			double expected           = 0.0;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}
		case 1: {
			string trueTime           = "11:59:58";
			string skewTime           = "12:03:28";
			int hourlyGain            = -3;
			double expected           = 70.0;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}
		case 2: {
			string trueTime           = "12:03:28";
			string skewTime           = "11:59:58";
			int hourlyGain            = 3;
			double expected           = 70.0;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}
		case 3: {
			string trueTime           = "03:03:02";
			string skewTime           = "03:01:47";
			int hourlyGain            = 5;
			double expected           = 15.0;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}
		case 4: {
			string trueTime           = "03:03:02";
			string skewTime           = "03:01:47";
			int hourlyGain            = -5;
			double expected           = 8625.0;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}
		case 5: {
			string trueTime           = "07:08:09";
			string skewTime           = "09:08:07";
			int hourlyGain            = -321;
			double expected           = 22.42367601246106;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}

		// custom cases

/*      case 6: {
			string trueTime           = ;
			string skewTime           = ;
			int hourlyGain            = ;
			double expected           = ;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}*/
/*      case 7: {
			string trueTime           = ;
			string skewTime           = ;
			int hourlyGain            = ;
			double expected           = ;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
		}*/
/*      case 8: {
			string trueTime           = ;
			string skewTime           = ;
			int hourlyGain            = ;
			double expected           = ;

			return verify_case( casenum, expected, BadClock().nextAgreement( trueTime, skewTime, hourlyGain ) );
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
