// Paste me into the FileEdit configuration dialog

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
const int INF = 0x3f3f3f3f;

int memo[51][51][51][4][3];
bool mark[51][51][51][4][3];

int f(vector <int> &v, vector <int> &csum, int a, int b, int c, int prev, int k){
	const int n = a + b + c;
	
	if(a > csum[0] || b > csum[1] || c > csum[2])return -INF;
	if(k > 2)return -INF;

	if(n >= (int)v.size())return 0;

	int &best = memo[a][b][c][prev+1][k];
	if(mark[a][b][c][prev+1][k])return best;
	mark[a][b][c][prev+1][k] = true;
	best = -INF;

	//try to put a box with color "color" in the position n
	for(int color = 0; color < 3; ++color){
		//if the color at position n is the same as "color"
		//no changes needed, so 1 more box remain in this position
		int next = v[n] == color ? 1 : 0;

		//add to next the function call
		next += f(v, csum, a + (color==0?1:0), b + (color==1? 1:0), c + (color==2?1:0),
			color, color == prev? k+1:1);

		//choose the best
		best = max(best, next);
	}

	return best;
}

class BoxesArrangement {
public:
	int maxUntouched( string boxes ) {
		vector <int> v(boxes.size(), 0), csum(3, 0);
		for(int i=0, n=(int)boxes.size(); i<n; ++i){
			v[i]=(int)boxes[i]-'A';
			csum[v[i]]++;
		}
		
		memset(mark, false, sizeof(mark));
		const int res = f(v, csum, 0, 0, 0, -1, 0);
		
		if(res >= 0)return res;
		return -1;
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
			string boxes              = "AAABBBCCC";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string boxes              = "AAAAAAAACBB";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string boxes              = "CCCCCB";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string boxes              = "BAACAABAACAAA";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string boxes              = "CBBABA";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string boxes              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string boxes              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string boxes              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxesArrangement().maxUntouched(boxes);
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
