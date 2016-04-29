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

struct point{
	int x, y;
	point(){}
	point(int _x, int _y):
	x(_x), y(_y){}
	point (const point &p){
		x = p.x, y=p.y;
	}
	bool operator <(const point &p)const{
		if(x < p.x)return false;
		else if(p.x < x)return true;
		else if(y < p.y)return false;
		else if(p.y < y)return true;
		else return false;
	}
};

bool checkInside(point p0, point r0, point r1){
	return(p0.x >= r0.x && p0.x <= r1.x && p0.y >= r0.y && p0.y <= r1.y);
}

struct Intersect {
	int area(vector <int> x, vector <int> y) {
		point r0(x[0], y[0]), r1(x[1],y[1]);
		if(r0 < r1)swap(r0,r1);
		if(r0.y > r1.y)swap(r0.y, r1.y);
		
		for(int i=2,n=x.size(); i<n; i+=2){
			point p0(x[i],y[i]), p1(x[i+1],y[i+1]), next0, next1;
			if(p0 < p1)swap(p0,p1);
			if(p0.y > p1.y)swap(p0.y, p1.y);

			next0.x = max(r0.x, p0.x);
			next0.y = max(r0.y, p0.y);
			next1.x = min(r1.x, p1.x);
			next1.y = min(r1.y, p1.y);

			if(checkInside(next0,r0,r1) && checkInside(next1,r0,r1) &&
				checkInside(next0,p0,p1) && checkInside(next1,p0,p1))
				swap(r0,next0), swap(r1,next1);
			else return 0;

		}
		return (max(r1.x,r0.x) - min(r0.x,r1.x))*(max(r1.y,r0.y) - min(r0.y,r1.y));
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
	
	int verify_case( int casenum, const int &expected, const int &received ) { 
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
			int x[]                   = {0,2,3,-4};
			int y[]                   = {17,1000,18,6};
			int expected              = 2;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 1: {
			int x[]                   = {10000,-10000};
			int y[]                   = {-10000,10000};
			int expected              = 400000000;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 2: {
			int x[]                   = {3,8,6,12,10,15};
			int y[]                   = {7,17,7,17,7,17};
			int expected              = 0;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 3: {
			int x[]                   = {0,0,0,0,0,0,0,0};
			int y[]                   = {5,5,5,5,5,5,5,5};
			int expected              = 0;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 4: {
			int x[]                   = {2,100,5,32,1000,-20,47,12};
			int y[]                   = {29,-1000,-800,-200,-900,300,-600,-650};
			int expected              = 1000;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 5: {
			int x[]                   = {1,7,12,3,16,8,3,12}	;
			int y[]                   = {-90,-60,-70,3,-60,-90,-80,-100};
			int expected              = 0;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, Intersect().area( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
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
