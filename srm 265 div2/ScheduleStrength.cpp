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

struct equipo{
	double strenght;
	string name;
	int w, l;
	equipo(string _name):
	name(_name){}
	bool operator <(const equipo &x)const{
		if(x.strenght > strenght)return true;
		else if(x.strenght < strenght)return false;
		else return x.name < name;
	}
};


struct ScheduleStrength {
	vector <string> calculate(vector <string> teams, vector <string> results){
		vector <equipo> v;
		for(int i=0, n=results.size(); i<n; ++i){
			v.push_back(equipo(teams[i]));
			v[i].w = 0, v[i].l=0;
			for(int j=0; j<n; ++j){
				if(results[i][j] == 'W')v[i].w++;
				else if(results[i][j] == 'L')v[i].l++;
			}
		}
		for(int i=0, n=results.size(); i<n; ++i){
			int w = 0, l=0;
			for(int j=0; j<n; ++j){
				if(results[i][j] == 'W' || results[i][j] == 'L'){
					w += v[j].w, l+= v[j].l;
				}
			}
			w -= v[i].l, l -= v[i].w;
			v[i].strenght = (double)(w)/(double)(w+l);
		}
		sort(all(v));
		reverse(all(v));
		vector <string> res(v.size());
		for(int i=0, n=v.size(); i<n; ++i)
			res[i] = v[i].name;
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
			string teams[]            = {"BEARS",  "GIANTS",  "COWBOYS",  "BRONCOS",  "DOLPHINS",  "LIONS"};
			string results[]          = {"-WLWW-",  "L-WL-W",  "WL---W",  "LW--L-",  "L--W--",  "-LL---"};
			string expected[]         = {"BEARS", "DOLPHINS", "BRONCOS", "COWBOYS", "GIANTS", "LIONS" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ScheduleStrength().calculate( vector <string>( teams, teams + ( sizeof teams / sizeof teams[0] ) ), vector <string>( results, results + ( sizeof results / sizeof results[0] ) ) ) );
		}
		case 1: {
			string teams[]            = {"BEARS",  "COWBOYS",  "GIANTS",  "PACKERS"} ;
			string results[]          = {"-LLW",  "W-WW",  "WL--",  "LL--"};
			string expected[]         = {"GIANTS", "BEARS", "COWBOYS", "PACKERS" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ScheduleStrength().calculate( vector <string>( teams, teams + ( sizeof teams / sizeof teams[0] ) ), vector <string>( results, results + ( sizeof results / sizeof results[0] ) ) ) );
		}
		case 2: {
			string teams[]            = {"AZTECS",  "COUGARS",  "COWBOYS",  "FALCONS",  "HORNEDFROGS",  "LOBOS",  "RAMS",  "REBELS",  "UTES"} ;
			string results[]          = {"---L-L--W",  "--LL-LWL-",  "-W--WWLLW",  "WW---L--W",  "--L--W-L-",  "WWLWL-LW-",  "-LW--W-L-",  "-WW-WLW--",  "L-LL-----"} ;
			string expected[]         = {"HORNEDFROGS", "COUGARS", "RAMS", "LOBOS", "REBELS", "UTES", "COWBOYS", "AZTECS", "FALCONS" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ScheduleStrength().calculate( vector <string>( teams, teams + ( sizeof teams / sizeof teams[0] ) ), vector <string>( results, results + ( sizeof results / sizeof results[0] ) ) ) );
		}
		case 3: {
			string teams[]            = {"E", "D", "C", "B", "Z"};
			string results[]          = { "--LLL", "---LL", "W---L", "WW---", "WWW--" };
			string expected[]         = {"D", "E", "C", "Z", "B" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ScheduleStrength().calculate( vector <string>( teams, teams + ( sizeof teams / sizeof teams[0] ) ), vector <string>( results, results + ( sizeof results / sizeof results[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			string teams[]            = ;
			string results[]          = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ScheduleStrength().calculate( vector <string>( teams, teams + ( sizeof teams / sizeof teams[0] ) ), vector <string>( results, results + ( sizeof results / sizeof results[0] ) ) ) );
		}*/
/*      case 5: {
			string teams[]            = ;
			string results[]          = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ScheduleStrength().calculate( vector <string>( teams, teams + ( sizeof teams / sizeof teams[0] ) ), vector <string>( results, results + ( sizeof results / sizeof results[0] ) ) ) );
		}*/
/*      case 6: {
			string teams[]            = ;
			string results[]          = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ScheduleStrength().calculate( vector <string>( teams, teams + ( sizeof teams / sizeof teams[0] ) ), vector <string>( results, results + ( sizeof results / sizeof results[0] ) ) ) );
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
