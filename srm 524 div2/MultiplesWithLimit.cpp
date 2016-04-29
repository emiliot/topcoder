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

struct state_t{
	int k;
	string w;
	state_t(int _k, string _w):
	k(_k), w(all(_w)){}
};

struct MultiplesWithLimit {
	string minMultiples(int N, vector <int> forbiddenDigits) {
		string Digits = "";
		sort(all(forbiddenDigits));
		for(int i=0, j=0, n=forbiddenDigits.size(); j<10; ++j){
			if(i < n){
				if(forbiddenDigits[i] == j)++i;
				else Digits += j+'0';
			}else Digits += j+'0';
		}

		vector <string> memo(N, "");
		vector <int> v(N, 0);
		queue <state_t> q;
		q.push(state_t(0,""));
		while(!q.empty()){
			state_t st = q.front(); q.pop();

			for(int i=0, m=Digits.size(); i<m; ++i){
				if(st.w.size() > 0 || Digits[i] > '0'){
					string next = st.w + Digits[i];
					int nextState = (st.k * 10 + (Digits[i]-'0')) % N;
					if(v[nextState] == 0){
						v[nextState] = next.size();
						if(next.size() > 10)
							memo[nextState] = next.substr(0,5) + next.substr(next.size()-5,5);
						else
							memo[nextState] = next;
						q.push(state_t(nextState, next));
					}
				}
			}
		}

		if(v[0] == 0)return "IMPOSSIBLE";
		else if(v[0] >= 9){
			string res = memo[0].substr(0,3) + "..." + memo[0].substr(memo[0].size()-3,3);
			char buffer [100];
			sprintf(buffer, "(%d digits)", v[0]);
			istringstream iss(buffer);
			string aux = "", inp;
			iss >> aux;
			while(iss >> inp)aux+=" "+inp;
			return res+aux;
		}else return memo[0];
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
			int N                     = 8;
			int forbiddenDigits[]     = {2,3,4,5,6,7,8,9};
			string expected           = "1000";

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
		}
		case 1: {
			int N                     = 9;
			int forbiddenDigits[]     = {1,3,4,5,6,7,8,9};
			string expected           = "222...222(9 digits)";

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
		}
		case 2: {
			int N                     = 524;
			int forbiddenDigits[]     = {5,2,4};
			string expected           = "3668";

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
		}
		case 3: {
			int N                     = 10000;
			int forbiddenDigits[]     = {0};
			string expected           = "IMPOSSIBLE";

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
		}
		case 4: {
			int N                     = 1;
			int forbiddenDigits[]     = {0,1,2,3,4,5,6,7,8,9};
			string expected           = "IMPOSSIBLE";

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
		}

		// custom cases

      case 5: {
			int N                     = 2007;
			int forbiddenDigits[]     = {1, 2, 3, 4, 5, 6, 8, 9, 0};
			string expected           = "777...777(666 digits)";

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
		}
/*      case 6: {
			int N                     = 8;
			int forbiddenDigits[]     = {1,2, 8};
			string expected           = "";

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
		}*/
/*      case 7: {
			int N                     = ;
			int forbiddenDigits[]     = ;
			string expected           = ;

			return verify_case( casenum, expected, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof forbiddenDigits[0] ) ) ) );
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
