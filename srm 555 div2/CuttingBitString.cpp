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
const int INF = 0x3f3f3f3f;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}

int memo[60][60];
bool mark[60][60];
set <i64> five;
string s;

i64 buildNum(int a, int b){
	i64 res = 0;
	string aux = s.substr(a, b-a);
	for(int i=0, n=(int)aux.size(); i<n; ++i){
		if(aux[i] == '1')res += (1LL << (n-i-1));
	}
	return res;
}

int f(int a, int b){
	if(b - a <= 0)return 0;
	int &best = memo[a][b];
	if(mark[a][b])return best;
	mark[a][b] = true;

	best = -1;
	if(s[a]!='0' && five.find(buildNum(a,b))!= five.end()){
		best = 1;
		return best;
	}

	for(int k=a+1; k<b; ++k){
		if(s[k] == '0')continue;

		int na = f(a, k);
		int nb = f(k, b);

		if(na != -1 && nb != -1){
			if(best == -1)best = na+nb;
			else best = min(best, na+nb);
		}
	}
	return best;
}

class CuttingBitString {
public:
	int getmin( string S ) {
		for(i64 i=1LL; i<=(1LL << 51LL); i*=5)five.insert(i);

		memset(mark, false, sizeof(mark));
		s = S;
		int res = f(0, (int)S.size());
		return res;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string S                  = "101101101";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "1111101";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "00000";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "110011011";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "1000101011";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "111011100110101100101110111";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			string S                  = "1";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
