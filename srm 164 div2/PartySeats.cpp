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
// BEGIN CUT HERE

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

struct PartySeats {
	vector <string> seating(vector <string> v) {
		vector <string> girls, boys;
		for(int i=0, n=v.size(); i<n; ++i){
			if(v[i].substr(v[i].size()-3,3)=="boy")boys.push_back(v[i].substr(0,v[i].size()-4));
			else girls.push_back(v[i].substr(0,v[i].size()-5));
		}
		sort(all(girls));
		sort(all(boys));
		vector <string> res;
		int g = girls.size(), b = boys.size();
		if((g!=b) || g%2!=0 || b%2 != 0 || g<2 || b<2)return res;
		res.push_back("HOST");
		int i=0, j=0, k=1;
		for(int n=v.size()/2; k<=n; ++k){
			if(k%2 == 1){
				res.push_back(girls[i]);
				++i;
			}else{
				res.push_back(boys[j]);
				++j;
			}
		}
		res.push_back("HOSTESS"); ++k;
		for(int n=v.size(); k<=n+1; ++k){
			if(k%2 == 1){
				res.push_back(girls[i]);
				++i;
			}else{
				res.push_back(boys[j]);
				++j;
			}
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
	template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case( int casenum, const vector <string> &expected, const vector <string> &received ) { 
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
			string attendees[]        = {"BOB boy","SAM girl","DAVE boy","JO girl"};
			string expected[]         = { "HOST",  "JO",  "BOB",  "HOSTESS",  "DAVE",  "SAM" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PartySeats().seating( vector <string>( attendees, attendees + ( sizeof attendees / sizeof attendees[0] ) ) ) );
		}
		case 1: {
			string attendees[]        = {"JOHN boy"};
			string expected[]         = {"-1" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PartySeats().seating( vector <string>( attendees, attendees + ( sizeof attendees / sizeof attendees[0] ) ) ) );
		}
		case 2: {
			string attendees[]        = {"JOHN boy","CARLA girl"};
			string expected[]         = {"-1" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PartySeats().seating( vector <string>( attendees, attendees + ( sizeof attendees / sizeof attendees[0] ) ) ) );
		}
		case 3: {
			string attendees[]        = {"BOB boy","SUZIE girl","DAVE boy","JO girl", "AL boy","BOB boy","CARLA girl","DEBBIE girl"};
			string expected[]         = { "HOST",  "CARLA",  "AL",  "DEBBIE",  "BOB",  "HOSTESS",  "BOB",  "JO",  "DAVE",  "SUZIE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PartySeats().seating( vector <string>( attendees, attendees + ( sizeof attendees / sizeof attendees[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			string attendees[]        = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PartySeats().seating( vector <string>( attendees, attendees + ( sizeof attendees / sizeof attendees[0] ) ) ) );
		}*/
/*      case 5: {
			string attendees[]        = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PartySeats().seating( vector <string>( attendees, attendees + ( sizeof attendees / sizeof attendees[0] ) ) ) );
		}*/
/*      case 6: {
			string attendees[]        = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), PartySeats().seating( vector <string>( attendees, attendees + ( sizeof attendees / sizeof attendees[0] ) ) ) );
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
