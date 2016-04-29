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

int memo[60][60];
bool mark[60][60];
bool mark2[60][60];
int memo2[60][60];
const int INF = 0x3f3f3f3f;
int f(const string &eq, const vector<int>&v, int i, int j);

int g(const string &eq, const vector<int>&v, int i, int j){
	if(i>=j)return 0;
	int &best = memo2[i][j];
	if(mark2[i][j])return best;
	mark2[i][j] = true;
	if(eq[i]=='+')best = g(eq,v,i+1,j)+v[i];
	else{
		for(int k=i; k<=j; ++k){
			const int aux = g(eq,v,k,j) - (f(eq,v,i+1,k)+v[i]);
			best = max(best,aux);
		}
		best = max(best, -(f(eq,v,i+1,j)+v[i]));
	}
	return best;
}

int f(const string &eq,const vector<int> &v, int i, int j){
	if(i>=j)return 0;
	int &best = memo[i][j];
	if(mark[i][j])return best;
	mark[i][j] = true;
	if(eq[i]=='+')best = f(eq,v,i+1,j)+v[i];
	else {
		for(int k=i; k<=j; ++k){
			const int aux = f(eq,v,k,j) - (g(eq,v,i+1,k)+v[i]);
			best = min(best,aux);
		}
		best = min(best, -(g(eq,v,i+1,j)+v[i]));
	}
	return best;
}

struct LostParentheses {
	int minResult(string e) {
		vector <int> v;
		string eq; eq+= '+';
		for(int i=0, n=e.size(),j; i<n; ++i){
			if(e[i] == '+' || e[i] == '-'){
				eq += e[i];
				continue;
			}
			int aux=0;
			for(j=i; j<n && e[j]>= '0' && e[j]<='9'; ++j)
				(aux*=10)+=e[j]-'0';
			v.push_back(aux);
			i = j-1;
		}
		memset(mark,false,sizeof(mark));
		memset(mark2,false,sizeof(mark2));
		return f(eq,v,0,eq.size());
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
	
	int verify_case( int casenum, const int &expected, const int &received ) { 
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
			string e                  = "55-50+40";
			int expected              = -35;

			return verify_case( casenum, expected, LostParentheses().minResult( e ) );
		}
		case 1: {
			string e                  = "10+20+30+40";
			int expected              = 100;

			return verify_case( casenum, expected, LostParentheses().minResult( e ) );
		}
		case 2: {
			string e                  = "00009-00009";
			int expected              = 0;

			return verify_case( casenum, expected, LostParentheses().minResult( e ) );
		}

		// custom cases
		case 3: {
			string e                  = "50980-46441-24363-78452+26293+52584-94259-46416+29";
			int expected              = -317857;

			return verify_case( casenum, expected, LostParentheses().minResult( e ) );
		}
/*      case 4: {
			string e                  = ;
			int expected              = ;

			return verify_case( casenum, expected, LostParentheses().minResult( e ) );
		}*/
/*      case 5: {
			string e                  = ;
			int expected              = ;

			return verify_case( casenum, expected, LostParentheses().minResult( e ) );
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
