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

bool table[1 << 10];
bool mark[1 << 10][1 << 10][2];
bool memo[1 << 10][1 << 10][2];

const int Target = 15;

int getSum(int mask){
	int res = 0;
	for(int i=0; i<(1 << 10); ++i)
		if(mask & (1 << i))res += i;
	return res;
}

void f(){
	table[(1 << 1)|(1 << 6)|(1 << 8)] = true;
	table[(1 << 1)|(1 << 5)|(1 << 9)] = true;
	table[(1 << 2)|(1 << 6)|(1 << 7)] = true;
	table[(1 << 2)|(1 << 5)|(1 << 8)] = true;
	table[(1 << 2)|(1 << 4)|(1 << 9)] = true;
	table[(1 << 3)|(1 << 5)|(1 << 7)] = true;
	table[(1 << 3)|(1 << 4)|(1 << 8)] = true;
	table[(1 << 4)|(1 << 5)|(1 << 6)] = true;

	for(int mask=1; mask<(1<<10); ++mask){
		for(int i=0; i<10; ++i){
			if(mask & (1 << i)){
				int pMask = mask & (~(1 << i));
				if(table[pMask])table[mask] = true;
			}
		}
	}
}

string getNumber(int k){
	char x = '0'+(char)(k);
	string res = "";
	res += x;
	return res;
}

bool g(int dealer, int player, bool prev){
	
	//memoization
	bool &winner = memo[dealer][player][prev];
	if(mark[dealer][player][prev])return winner;
	mark[dealer][player][prev] = true;
	
	//get the possiblemoves
	int possibleMoves = (1 << 10)-1;
	for(int i=0; i<10; ++i){
		if((dealer & (1 << i)) || (player & (1 << i)))possibleMoves &= (~(1 << i));
	}

	//if last play was made by the player
	if(prev){
		if(table[player])winner = true; //the player wins with the last move
		else{
			//make the play for the dealer
			for(int i=1; i<10; ++i){
				if(possibleMoves & (1 << i)){
					bool next = g(dealer | (1 << i), player, false);
					if(!next){
						//dealer wins
						winner = false;
						return winner;
					}
				}
			}
			//player wins
			winner = true;
		}
	}else{
		if(table[dealer])winner = false; //the dealer wins with the last move
		else{
			//make the play for the player
			for(int i=1; i<10; ++i){
				if(possibleMoves & (1 << i)){
					bool next = g(dealer, player | (1 << i), true);
					if(next){
						//player wins
						winner = true;
						return winner;
					}
				}
			}
			//dealer wins
			winner = false;
		}
	}

	return winner;
}

struct Fifteen {
	string outcome(vector <int> moves) {
		memset(table, false, sizeof(table));
		f(); //fill the table

		memset(mark, false, sizeof(mark));
		int possibleMoves = (1 << 10)-1, dealer = 0, player = 0;

		for(int i=0, n=(int)moves.size(); i<n; ++i){
			if(i % 2 == 0){
				dealer |= (1 << moves[i]);
			}else{
				player |= (1 << moves[i]);
			}
			possibleMoves &= (~(1 << moves[i]));
		}

		for(int i=1; i<10; ++i){
			if(possibleMoves & (1 << i)){
				//player's turn
				bool res = g(dealer, player | (1 << i), true);
				if(res)return "WIN " + getNumber(i);
			}
		}

		return "LOSE";
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
			int moves[]               = {7, 5, 9, 6, 8, 1, 2};
			string expected           = "WIN 4";

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}
		case 1: {
			int moves[]               = {4, 8, 6, 5, 2};
			string expected           = "LOSE";

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}
		case 2: {
			int moves[]               = {2, 4, 7, 6, 9, 8, 5};
			string expected           = "WIN 1";

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}
		case 3: {
			int moves[]               = {9, 2, 1, 6, 3, 4, 8};
			string expected           = "WIN 5";

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}
		case 4: {
			int moves[]               = {1};
			string expected           = "LOSE";

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}
		case 5: {
			int moves[]               = {6, 3, 7, 8, 1};
			string expected           = "WIN 2";

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			int moves[]               = ;
			string expected           = ;

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}*/
/*      case 7: {
			int moves[]               = ;
			string expected           = ;

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
		}*/
/*      case 8: {
			int moves[]               = ;
			string expected           = ;

			return verify_case( casenum, expected, Fifteen().outcome( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) ) );
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
