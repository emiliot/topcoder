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

struct team{
	char T;
	int pos, sixth;
	team(char _T, int _pos, int _sixth):
	T(_T), pos(_pos), sixth(_sixth){}
};

bool f(const team a, const team b){
	if(a.pos < b.pos)return true;
	else if(b.pos < a.pos)return false;
	else{
		if(a.sixth && b.sixth)return a.sixth < b.sixth;
		if(a.sixth && !b.sixth)return true;
		else if(!a.sixth && b.sixth)return false;
		return a.T < b.T;
	}
}

struct CrossCountry {
	string scoreMeet(int numTeams, string s) {
		vector <int> finish(numTeams,0);
		vector <int> score(numTeams,0);
		vector <int> sixth(numTeams,0);
		for(int i=0, n=s.size(); i<n; ++i){
			if(finish[s[i]-'A'] < 5)score[s[i]-'A']+=i+1, ++finish[s[i]-'A'];
			else if(finish[s[i]-'A'] == 5)sixth[s[i]-'A'] = i+1, finish[s[i]-'A']++;
		}
		vector <team> v;
		for(int i=0; i<numTeams; ++i){
			if(finish[i] >= 5)v.push_back(team(i+'A',score[i],sixth[i]));
		}
		string res;
		sort(v.begin(),v.end(),f);
		for(int i=0, n=v.size(); i<n; ++i)
			res += v[i].T;
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
			int numTeams              = 2;
			string finishOrder        = "AABBABBABBA";
			string expected           = "AB";

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
		}
		case 1: {
			int numTeams              = 3;
			string finishOrder        = "CCCBBBBBAAACC";
			string expected           = "BC";

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
		}
		case 2: {
			int numTeams              = 4;
			string finishOrder        = "ABDCBADBDCCDBCDBCAAAC";
			string expected           = "BDCA";

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
		}
		case 3: {
			int numTeams              = 10;
			string finishOrder        = "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG";
			string expected           = "BCDAHEG";

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
		}
		case 4: {
			int numTeams              = 3;
			string finishOrder        = "BABCAABABAB";
			string expected           = "AB";

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
		}

		// custom cases

      case 5: {
			int numTeams              = 3;
			string finishOrder        = "ABBABAACBBAB";
			string expected           = "BA";

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
		}
/*      case 6: {
			int numTeams              = ;
			string finishOrder        = ;
			string expected           = ;

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
		}*/
/*      case 7: {
			int numTeams              = ;
			string finishOrder        = ;
			string expected           = ;

			return verify_case( casenum, expected, CrossCountry().scoreMeet( numTeams, finishOrder ) );
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
