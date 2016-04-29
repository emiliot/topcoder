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

bool ok(string &c, int mHits, int fHits){
	if((mHits | fHits) != (1 << c.size())-1)return false;
	return true;
}

struct PaternityTest {
	vector <int> possibleFathers(string child, string mother, vector <string> men) {
		int mHits = 0, fHits;
		for(int i=0, n=child.size(); i<n; ++i){
			if(child[i] == mother[i]){
				mHits = mHits | (1 << i);
			}
		}
		vector <int> res;
		for(int k=0, m=men.size(); k<m; ++k){
			fHits = 0;
			int hits = 0;
			for(int i=0, n=child.size(); i<n; ++i){
				if(child[i] == men[k][i]){
					fHits = fHits | (1 << i);
					hits ++;
				}
			}
			if(hits >= child.size()/2 && ok(child, mHits, fHits))
				res.push_back(k);
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received ) { 
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
			string child              = "ABCD";
			string mother             = "AXCY";
			string men[]              = { "SBTD", "QRCD" };
			int expected[]            = { 0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
		}
		case 1: {
			string child              = "ABCD";
			string mother             = "ABCX";
			string men[]              = { "ABCY", "ASTD", "QBCD" } ;
			int expected[]            = { 1,  2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
		}
		case 2: {
			string child              = "ABABAB";
			string mother             = "ABABAB";
			string men[]              = { "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" };
			int expected[]            = { 0,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
		}
/*		case 3: {
			string child              = "YZGLSYQT";
			string mother             = "YUQRWYQT";
			string men[]              = {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"};
			int expected[]            = { };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
		}*/
		case 4: {
			string child              = "WXETPYCHUWSQEMKKYNVP";
			string mother             = "AXQTUQVAUOSQEEKCYNVP";
			string men[]              = { "WNELPYCHXWXPCMNKDDXD",   "WFEEPYCHFWDNPMKKALIW",   "WSEFPYCHEWEFGMPKIQCK",   "WAEXPYCHAWEQXMSKYARN",   "WKEXPYCHYWLLFMGKKFBB" };
			int expected[]            = { 1,  3 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string child              = ;
			string mother             = ;
			string men[]              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
		}*/
/*      case 6: {
			string child              = ;
			string mother             = ;
			string men[]              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
		}*/
/*      case 7: {
			string child              = ;
			string mother             = ;
			string men[]              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PaternityTest().possibleFathers( child, mother, vector <string>( men, men + ( sizeof men / sizeof men[0] ) ) ) );
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
