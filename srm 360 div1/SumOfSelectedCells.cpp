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
const int INF = 0x3f3f3f3f;
int memo[1 << 21];
bool mark[1 << 21];
int X, N,M;
int f(const vector < vector <int> > &v,int row, int mask){
	if(row >= N)return 0;
	int &best = memo[mask];
	if(mark[mask])return best;
	mark[mask] = true;
	best = -1;
	if(row == 0){
		for(int j=0; j<M; ++j){
			if(!(mask & (1 << (20-j)))){
				const int sum = f(v,row+1,mask | (1 << (20-j)));
				if(sum + v[row][j] != X)return -1;
				best = sum + v[row][j];
			}
		}
	}else{
		int j;
		for(j=0; j<M && best <0; ++j){
			if(!(mask & (1 << (20-j)))){
				const int sum = f(v,row+1,mask | (1 << (20-j)));
				if(sum < 0){
					best = -1;
					return best;
				}
				best = sum + v[row][j];
			}
		}
		for(;j<M;++j){
			if(!(mask & (1 << (20-j)))){
				const int sum = f(v,row+1,mask | (1 << (20-j)));
				if(sum < 0 || sum+v[row][j]!=best){
					best = -1;
					return best;
				}
			}
		}
	}
	return best;
}
vector < vector <int> > transpose(vector < vector <int> > v){
	vector < vector <int> > res(v[0].size(), vector<int> (v.size()));
	for(int i=0, n=v.size(); i<n; ++i){
		for(int j=0, m=v[i].size(); j<m; ++j)
			res[j][i] = v[i][j];
	}
	return res;
}

struct SumOfSelectedCells {
	string hypothesis(vector <string> table) {
		vector < vector <int> > v(table.size());
		for(int i=0, n=v.size(); i<n; ++i){
			istringstream iss(table[i]);
			for(int x; iss >> x; v[i].push_back(x)); //zyx3d told me this trick
		}
		if(v[0].size() < v.size())v = transpose(v);
		X = 0;
		for(int i=0,n=min(v.size(),v[0].size()); i<n; ++i)
			X+=v[i][i];
		N = v.size(),M = v[0].size();
		memset(memo,true,sizeof(memo));
		memset(mark,false,sizeof(mark));
		if(f(v,0,0)==X)
			return ("CORRECT");
		else
			return ("INCORRECT");
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
			string table[]            = {"5 6 6"};
			string expected           = "INCORRECT";

			return verify_case( casenum, expected, SumOfSelectedCells().hypothesis( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
		case 1: {
			string table[]            = {"11 12 13 14",  "21 22 23 24",  "31 32 33 34",  "41 42 43 44"};
			string expected           = "CORRECT";

			return verify_case( casenum, expected, SumOfSelectedCells().hypothesis( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
		case 2: {
			string table[]            = {"3 7",  "3 7",  "3 7"};
			string expected           = "CORRECT";

			return verify_case( casenum, expected, SumOfSelectedCells().hypothesis( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
		case 3: {
			string table[]            = {"1 2 3",  "4 5 6",  "9 8 7"};
			string expected           = "INCORRECT";

			return verify_case( casenum, expected, SumOfSelectedCells().hypothesis( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}

		// custom cases

     case 4: {
			string table[]            = {"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"};
			string expected           = "INCORRECT";

			return verify_case( casenum, expected, SumOfSelectedCells().hypothesis( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}
/*      case 5: {
			string table[]            = ;
			string expected           = ;

			return verify_case( casenum, expected, SumOfSelectedCells().hypothesis( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
		}*/
/*      case 6: {
			string table[]            = ;
			string expected           = ;

			return verify_case( casenum, expected, SumOfSelectedCells().hypothesis( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ) ) );
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
