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

double f(const vector<int> &x, const vector <int> &m, int a, int b, double p){
	double F = 0.0;
	for(int i=a; i<b; ++i)
		F += (double)(m[i])/pow(p-(double)(x[i]),2.0);
	return F;
}

struct EquilibriumPoints {
	vector <double> getPoints(vector <int> x, vector <int> m) {
		vector <double> res;
		const double eps = 1e-9;
		for(int i=0, n=x.size(); i<n-1; ++i){
			double low = (double)(x[i]),high = (double)(x[i+1]);
			for(int j=0,maxit=1000000; j<maxit && high-low > eps; ++j){
				double mid = (low+high)/2.0;
				double left = f(x,m,0,i+1,mid);
				double right = f(x,m,i+1,x.size(),mid);
				if(left < right)high = mid;
				else low = mid;
			}
			res.push_back(low);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	static bool topcoder_fequ( const vector<double> &a, const vector<double> &b ) { if ( a.size() != b.size() ) return false; for ( size_t i=0; i<a.size(); ++i ) if ( !topcoder_fequ( a[i], b[i] ) ) return false; return true; }
	double moj_relative_error( const vector<double> &expected, const vector<double> &result ) { double ret = 0.0; for ( size_t i=0; i<expected.size(); ++i ) { ret = max( ret, moj_relative_error( expected[i], result[i] ) ); } return ret; }
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <double> &expected, const vector <double> &received ) { 
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
			int x[]                   = {1, 2};
			int m[]                   = {1, 1};
			double expected[]         = {1.5 };

			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), EquilibriumPoints().getPoints( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( m, m + ( sizeof m / sizeof m[0] ) ) ) );
		}
		case 1: {
			int x[]                   = {1, 2};
			int m[]                   = {1, 1000};
			double expected[]         = {1.0306534300317156 };

			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), EquilibriumPoints().getPoints( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( m, m + ( sizeof m / sizeof m[0] ) ) ) );
		}
		case 2: {
			int x[]                   = {1, 2, 3};
			int m[]                   = {1, 2, 1};
			double expected[]         = {1.4060952084922507, 2.5939047915077493 };

			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), EquilibriumPoints().getPoints( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( m, m + ( sizeof m / sizeof m[0] ) ) ) );
		}
		case 3: {
			int x[]                   = {2, 3, 5, 7};
			int m[]                   = {3, 2, 7, 5};
			double expected[]         = {2.532859446114924, 3.7271944335152813, 6.099953640852538 };

			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), EquilibriumPoints().getPoints( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( m, m + ( sizeof m / sizeof m[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int m[]                   = ;
			double expected[]         = ;

			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), EquilibriumPoints().getPoints( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( m, m + ( sizeof m / sizeof m[0] ) ) ) );
		}*/
/*      case 5: {
			int x[]                   = ;
			int m[]                   = ;
			double expected[]         = ;

			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), EquilibriumPoints().getPoints( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( m, m + ( sizeof m / sizeof m[0] ) ) ) );
		}*/
/*      case 6: {
			int x[]                   = ;
			int m[]                   = ;
			double expected[]         = ;

			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), EquilibriumPoints().getPoints( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( m, m + ( sizeof m / sizeof m[0] ) ) ) );
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
