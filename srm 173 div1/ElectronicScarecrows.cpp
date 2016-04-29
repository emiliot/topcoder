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
const int INF = 0x3f3f3f3f;
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
struct p2{
	int x, y;
	p2(){}
	p2(int _x, int _y):
	x(_x), y(_y){}

	p2 operator -(const p2 &other){
		return p2(x - other.x, y - other.y);
	}
	p2 operator +(const p2 &other){
		return p2(x + other.x , y + other.y);
	}
};

int crossP(p2 &a, p2 &b){
	return (a.x * b.y) - (a.y * b.x);
}

int dotP(p2 &a, p2 &b){
	return (a.x * b.x) + (a.y + b.y);
}

//ccw: return -1 cw, 0 colinear and +1 ccw
int ccw(const p2 &a, const p2 &b, const p2 &c){
	p2 ab = p2(b.x - a.x, b.y - a.y), ac = p2(c.x - a.x, c.y - a.y);
	int cross = crossP(ab, ac);
	if(cross < 0)return -1;
	else if(cross == 0)return 0;
	else return 1;
}

//functor used to sort the points in ccw form, requires a point pivot to sort around
p2 pivot;
bool func(const p2 &a, const p2 &b){
	int x = ccw(pivot, a, b);
	if(x == 1)return true; //they are in ccw;
	else return false; //colinear or cw
}

vector <p2> convexHull(vector <p2> &v){
	int start = 0, n = (int)v.size();
	//find the point with lowest y coordinate, if there is a tie choose the x lowest
	for(int i=0; i<n; ++i){
		if(v[i].y < v[start].y)start = i;
		else if(v[i].y == v[start].y && v[i].x < v[start].x)start = i;
	}
	
	//set the point to the functor
	pivot.x = v[start].x, pivot.y = v[start].y;
	swap(v[start], v[0]);

	//sort the points
	sort(v.begin()+1, v.end(), func);

	vector <bool> mark(n, false);
	//build the convex hull
	int p = 0, next, dist; start = 0;
	do{
		next = -1;
		dist = 0;
		for(int i=0; i<n; ++i){
			if(i == p)continue;
			if(mark[i])continue;
			if(next == -1)next = i;
			int angle = ccw(v[p], v[i], v[next]);
			p2 aux = v[i] - v[p];
			int d = dotP(aux, aux);
			if(angle > 0){
				next = i;
				dist = d;
			}else if(angle == 0){
				if(d > dist){
					dist = d;
					next = i;
				}
			}
		}
		p = next;
		mark[p] = true;
	}while(p != start);
	
	vector <p2> res;
	for(int i=0; i<n; ++i)
		if(mark[i])res.push_back(v[i]);
	return res;
}

int memo[60][60][60];
bool mark[60][60][60];

int f(vector <p2> &v, int first, int last, int left){
	if(left <= 0){
		return crossP(v[last], v[first]);
	}

	int &best = memo[first][last][left];
	if(mark[first][last][left])return best;
	mark[first][last][left] = true;

	best = -INF;
	for(int k=last+1, n=(int)v.size() - left + 1; k<n; ++k){
		int next = f(v, first, k, left-1) + crossP(v[last], v[k]);
		best = max(best, next);
	}
	return best;
}

struct ElectronicScarecrows {
	double largestArea(vector <int> x, vector <int> y, int n) {
		int m = (int)x.size();
		vector <p2> v(m);
		for(int i=0; i<m; ++i){
			v[i].x = x[i], v[i].y = y[i];
		}
		vector <p2> hull = convexHull(v);

		//set n to be the max between n and hull.size()
		n = min(n, (int) hull.size());
		
		//set m to the hull size
		m = (int)hull.size();
		int best = 0;

		for(int i=0; i<m; ++i){
			memset(mark, false, sizeof(mark));
			for(int j=i+1; j<m; ++j){
				int next = f(hull, i, j, n - 2) + crossP(hull[i], hull[j]);
				best = max(best, next);
			}
		}

		return (double)(best)/2.0;
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
			int x[]                   = {2,1,6,5,3,7,9};
			int y[]                   = {2,5,1,5,7,6,4};
			int n                     = 4;
			double expected           = 24.0;

			return verify_case( casenum, expected, ElectronicScarecrows().largestArea( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), n ) );
		}
		case 1: {
			int x[]                   = {183,229,723,510,395,936,447,328};
			int y[]                   = {1000,823,0,412,786,446,312,286};
			int n                     = 15;
			double expected           = 347200.0;

			return verify_case( casenum, expected, ElectronicScarecrows().largestArea( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), n ) );
		}
		case 2: {
			int x[]                   = {33,36,26,8,12,8,28,19,8,37,9,22,31,30,25};
			int y[]                   = {12,8,6,16,27,7,31,33,35,22,22,36,29,22,32};
			int n                     = 8;
			double expected           = 740.5;

			return verify_case( casenum, expected, ElectronicScarecrows().largestArea( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), n ) );
		}
		case 3: {
			int x[]                   = {327,196,744,91,709,38,944,300,927,715,835,874,958,667,748,511,377,956,184,956,  809,925,12,45,184,180,169,374,914,398,954,875,286,422,76,315,497,209,512,938};
			int y[]                   = {913,843,73,213,903,444,444,905,352,54,194,207,373,57,105,959,932,480,843,424,  140,661,578,616,851,132,135,936,676,23,578,737,74,959,724,924,955,854,958,376};
			int n                     = 25;
			double expected           = 685819.5;

			return verify_case( casenum, expected, ElectronicScarecrows().largestArea( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), n ) );
		}

		// custom cases

      case 4: {
		  int x[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
		  int y[]                   = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39};
		  int n                     = 3;
			double expected           = 19.0;

			return verify_case( casenum, expected, ElectronicScarecrows().largestArea( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), n ) );
		}
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int n                     = ;
			double expected           = ;

			return verify_case( casenum, expected, ElectronicScarecrows().largestArea( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), n ) );
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int n                     = ;
			double expected           = ;

			return verify_case( casenum, expected, ElectronicScarecrows().largestArea( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), n ) );
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
