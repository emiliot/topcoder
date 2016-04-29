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

struct dat{
	int m, d;
	dat(int _m, int _d):
	m(_m), d(_d){}
	bool operator <(const dat &x)const{
		if(m < x.m)return true;
		else if(x.m < m)return false;
		else if(d < x.d)return true;
		else return false;
	}
	string getDate(){
		string res;
		char buffer[10];
		sprintf(buffer, "%02d/%02d",m,d);
		res = buffer;
		return res;
	}
};

struct Birthday {
	string getNext(string date, vector <string> birthdays) {
		date[2] = ' ';
		istringstream aux(date);
		int mon, day; aux >> mon >> day;
		dat today(mon, day);
		vector <dat> v;
		for(int i=0, n=birthdays.size(); i<n; ++i){
			birthdays[i][2] = ' ';
			istringstream iss(birthdays[i]);
			iss >> mon >> day;
			v.push_back(dat(mon, day));
		}
		v.push_back(today);
		sort(all(v));
		for(int i=0, n=v.size(); i<n; ++i){
			if(v[i].m == today.m && v[i].d == today.d){
				return v[(i+1)%n].getDate();
			}
		}
		return "";
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
			string date               = "06/17";
			string birthdays[]        = {"02/17 Wernie", "10/12 Stefan"};
			string expected           = "10/12";

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
		}
		case 1: {
			string date               = "06/17";
			string birthdays[]        = {"10/12 Stefan"};
			string expected           = "10/12";

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
		}
		case 2: {
			string date               = "02/17";
			string birthdays[]        = {"02/17 Wernie", "10/12 Stefan"};
			string expected           = "02/17";

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
		}
		case 3: {
			string date               = "12/24";
			string birthdays[]        = {"10/12 Stefan"};
			string expected           = "10/12";

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
		}
		case 4: {
			string date               = "01/02";
			string birthdays[]        = {"02/17 Wernie",  "10/12 Stefan",  "02/17 MichaelJordan",  "10/12 LucianoPavarotti",  "05/18 WilhelmSteinitz"};
			string expected           = "02/17";

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string date               = ;
			string birthdays[]        = ;
			string expected           = ;

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
		}*/
/*      case 6: {
			string date               = ;
			string birthdays[]        = ;
			string expected           = ;

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
		}*/
/*      case 7: {
			string date               = ;
			string birthdays[]        = ;
			string expected           = ;

			return verify_case( casenum, expected, Birthday().getNext( date, vector <string>( birthdays, birthdays + ( sizeof birthdays / sizeof birthdays[0] ) ) ) );
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
