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
	i64 mask;
	int cost;
	state_t(i64 _mask, int _cost):
	mask(_mask), cost(_cost){}
	bool operator <(const state_t &x)const{
		return x.cost < cost;
	}
};

i64 encode(vector < vector <bool> > &v){
	i64 res = 0LL;
	for(int i=0,k=0; i<6; ++i){
		for(int j=0; j<6; ++j, ++k){
			if(v[i][j])res |= (1LL << i64(k));
		}
	}
	return res;
}

vector < vector <bool> > decode(i64 x){
	vector < vector <bool> >v(6, vector <bool>(6, false));
	for(int i=0, k=0; i<6; ++i){
		for(int j=0; j<6; ++j, ++k){
			if(x & (1LL << i64(k)))v[i][j] = true;
		}
	}
	return v;
}

const i64 start = (1LL << 28LL) | (1LL << 29LL) | (1LL << 34LL) | (1LL << 35LL);
const i64 fin = 3LL | (1LL << 6LL) | (1LL << 7LL);

void addState(priority_queue <state_t> &pq, map<i64, int> &memo, i64 mask, int cost){
	pair < map<i64, int>::iterator, bool> p = memo.insert(make_pair(mask,cost));
	if(!p.second && cost < p.first->second){
		p.first->second = cost;
		pq.push(state_t(mask,cost));
	}else if(p.second){
		pq.push(state_t(mask,cost));
	}
}

int f(vector <string> &board){
	priority_queue<state_t> pq;
	map <i64, int> memo;
	pq.push(state_t(start, 0));
	memo[start] = 0;
	int movi[] = {-1,1,0,0};
	int movj[] = {0,0,-1,1};
	while(!pq.empty()){
		state_t st = pq.top(); pq.pop();
		//printf("%lld %d\n", st.mask, st.cost);
		if(st.mask == fin)return st.cost;
		map<i64, int>::iterator it = memo.find(st.mask);
		if(it != memo.end() && it->second < st.cost)continue;
		vector < vector <bool> > v = decode(st.mask);
		for(int i=0; i<6; ++i){
			for(int j=0; j<6; ++j){
				if(v[i][j]){
					for(int k=0; k<4; ++k){
						int ni = i + movi[k], nj = j+movj[k],
							ni2 = ni + movi[k], nj2 = nj+movj[k];
						bool aux;
						if(ni >=0 && ni < 6 && nj >= 0 && nj < 6 && !v[ni][nj] && board[ni][nj] == '.'){
							aux = v[ni][nj];
							v[ni][nj] = v[i][j];
							v[i][j] = aux;
							i64 nextMask = encode(v);
							aux = v[ni][nj];
							v[ni][nj] = v[i][j];
							v[i][j] = aux;
							addState(pq, memo, nextMask, st.cost+1);
						}else if(ni2 >= 0 && ni2 < 6 && nj2 >= 0 && nj2 < 6 && !v[ni2][nj2] && board[ni2][nj2] == '.' && (v[ni][nj] || board[ni][nj] == 's')){
							aux = v[ni2][nj2];
							v[ni2][nj2] = v[i][j];
							v[i][j] = aux;
							i64 nextMask = encode(v);
							aux = v[ni2][nj2];
							v[ni2][nj2] = v[i][j];
							v[i][j] = aux;
							addState(pq, memo, nextMask, st.cost+1);
						}
					}
				}
			}
		}
	}
	return -1;
}

struct CornersGame {
	int countMoves(vector <string> board) {
		int res = f(board);
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
			string board[]            = {"......",   "......",  "......",  "......",  "......",  "......"};
			int expected              = 16;

			return verify_case( casenum, expected, CornersGame().countMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
		case 1: {
			string board[]            = {".....s",  "..s.r.",  "r.....",  ".srs..",  "..r...",  "......"};
			int expected              = 19;

			return verify_case( casenum, expected, CornersGame().countMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
		case 2: {
			string board[]            = {"......",  "......",  "....ss",  "....ss",  "...r..",  "...r.."};
			int expected              = -1;

			return verify_case( casenum, expected, CornersGame().countMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
		case 3: {
			string board[]            = {"...s.r",  "..r.s.",  "rr.s..",  "..s.rr",  "s.rr..",  ".s.s.."};
			int expected              = 54;

			return verify_case( casenum, expected, CornersGame().countMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			string board[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, CornersGame().countMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}*/
/*      case 5: {
			string board[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, CornersGame().countMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}*/
/*      case 6: {
			string board[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, CornersGame().countMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
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
