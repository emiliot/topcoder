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

string res = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const int INF = 0x3f3f3f3f;
struct InstantRunoff {
	string outcome(string candidates, vector <string> ballots) {
		vector <bool> alive(26,false);
		for(int i=0, n=candidates.size(); i<n; ++i)
			alive[candidates[i]-'A'] = true;

		for(int i=0, n=candidates.size(); i<n; ++i){
			vector <int> round(26, 0);
			for(int j=0, m=ballots.size(); j<m; ++j){
				if(ballots[j].size() <= 0)continue;
				if(alive[ballots[j][0]-'A'])round[ballots[j][0]-'A']++;
			}
			const int high = *max_element(round.begin(),round.end());
			int chigh = 0, indx = 0;
			for(int k = 0; k<26; ++k){
				if(alive[k] && round[k] == high)++chigh, indx = k;
			}
			if(chigh == 1 && 2*high > ballots.size())return res.substr(indx,1);

			int low = INF;
			for(int k = 0; k<26; ++k){
				if(alive[k]) low = min(low,round[k]);
			}
			for(int k=0; k<26; ++k){
				if(round[k] == low){
					alive[k] = false;
					for(int j=0, m=ballots.size(); j<m; ++j){
						while(ballots[j].size()>0 && (ballots[j][0] == 'A'+k || !alive[ballots[j][0]-'A'])){
							ballots[j].erase(0,1);
						}
					}
				}
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
			string candidates         = "ABC";
			string ballots[]          = {"ACB", "BCA", "ACB", "BCA", "CBA"};
			string expected           = "B";

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
		}
		case 1: {
			string candidates         = "DCBA";
			string ballots[]          = {"ACBD", "ACBD", "ACBD", "BCAD", "BCAD", "DBCA", "CBDA"};
			string expected           = "B";

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
		}
		case 2: {
			string candidates         = "ACB";
			string ballots[]          = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CBA", "CAB"};
			string expected           = "";

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
		}
		case 3: {
			string candidates         = "CAB";
			string ballots[]          = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CAB", "CAB"};
			string expected           = "A";

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
		}
		case 4: {
			string candidates         = "Z";
			string ballots[]          = {"Z"};
			string expected           = "Z";

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
		}

		// custom cases
      case 5: {
			string candidates         = "AHWMRNQDPI";
			string ballots[]          = {"WQAMIHPDNR", "INMDRAPQHW", "HRPINAMQWD", "MIRPDQNAWH", "IQNWRDHAPM", "WMPNDHRAIQ", "ANIHRPQWMD", "WHRAMPNIQD", "NDPQIAMHRW", "DIWAQPNMHR", "QAIMWNPRDH", "QWPMHDIRAN", "QANHPWIRDM", "DMPHAWRINQ", "IHRAPNWDMQ", "RDQANPHMIW", "RWAQNMHIDP", "NPAMQWRDHI", "HPDMWRNIQA", "AHRQMDNWIP", "PWQIMHNDAR", "HIPQADMWRN", "IQAPDNHMWR", "RQPMNDWIHA", "QIPNDRHAWM", "PDRAIWQMHN", "DIANQHPWMR", "DWAQNHIMRP", "HDPAIWNRMQ", "RQADIMNWPH", "DRNWHIMQAP", "WIMDHNAQPR", "QPIHNWARDM", "IWPNDRMAHQ", "NDAPWRQIHM", "MRPNHWQDIA", "QDPWHRINAM", "NMRWADIHPQ", "WARIPMQDNH", "PQAMIDRNHW", "MIHDAPWRNQ", "AMHPDNWIQR", "HIPRWMNQAD", "IPDNQWRMHA", "AMPDWHQNRI", "NRADHMPIQW", "HAMPRDIQWN", "RIMWPDANQH", "ADMIRHQPNW", "IDAWRNQMHP"};
			string expected           = "";

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
		}
/*      case 6: {
			string candidates         = ;
			string ballots[]          = ;
			string expected           = ;

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
		}*/
/*      case 7: {
			string candidates         = ;
			string ballots[]          = ;
			string expected           = ;

			return verify_case( casenum, expected, InstantRunoff().outcome( candidates, vector <string>( ballots, ballots + ( sizeof ballots / sizeof ballots[0] ) ) ) );
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
