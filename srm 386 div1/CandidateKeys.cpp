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

bool memo[1 << 12];

bool ok(const vector <string> &v, int mask){
	set <string> keys;
	for(int i=0, n=v.size(); i<n; ++i){
		string next = "";
		for(int j=0, m=v[i].size(); j<m; ++j){
			if(mask &(1 << j)){
				next += v[i][j];
			}
		}
		if(!keys.insert(next).second)return false;
	}
	return keys.size() == v.size();
}

struct CandidateKeys {
	vector <int> getKeys(vector <string> table) {
		memset(memo, false ,sizeof(memo));
		
		vector <int> res(2, 0);
		for(int i=1, n=table[0].size(); i<(1 << n); ++i){
			if(ok(table,i)){
				memo[i] = true;
				bool candidate = true;
				int size = 0;
				for(int j=0; j<n; ++j){
					if(i & (1 << j)){
						++size;
						int before = i & ~(1 << j);
						if(memo[before]){
							candidate = false;
						}
					}
				}
				if(candidate){
					res[0] = res[0] != 0? min(res[0],size) : size;
					res[1] = max(res[1], size);
				}
			}
		}
		if(res[0] == 0)res.clear();
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
			string table[]            = { "ABC", "ABC", "ABC" };
			int expected[]            = {0,0};

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
		case 1: {
			string table[]            = { "ABC", "ABD", "ABE" };
			int expected[]            = {1, 1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
		case 2: {
			string table[]            = { "ABC", "ACD", "BBE" };
			int expected[]            = {1, 2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
		case 3: {
			string table[]            = {"A","B"};
			int expected[]            = {1, 1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
		case 4: {
			string table[]            = { "AABB", "BABA", "CAAB", "DAAA", "EBBB", "FBBA", "GBAB", "HBAA" };
			int expected[]            = {1, 3 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string table[]            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}*/
/*      case 6: {
			string table[]            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}*/
/*      case 7: {
			string table[]            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CandidateKeys().getKeys( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
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
