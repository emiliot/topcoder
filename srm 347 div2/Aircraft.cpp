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

vector <i64> crossP(vector <i64> &v, vector <i64> &x){
	vector <i64> res(3);
	res[0] = x[1] * v[2] - x[2] * v[1];
	res[1] = x[2] * v[0] - x[0] * v[2];
	res[2] = x[0] * v[1] - x[1] * v[0];
	return res;
}

i64 dotP(vector <i64> &v, vector <i64> &x){
	i64 res = 0LL;
	for(int i=0, n=(int)v.size(); i<n; ++i){
		res += v[i] * x[i];
	}
	return res;
}

class Aircraft {
public:
	string nearMiss( vector <int> p1, vector <int> v1, vector <int> p2, vector <int> v2, int R ) {
		vector <i64> v(3), x(3);
		for(int i=0, n=3; i<n; ++i){
			v[i] = v2[i] - v1[i];
			x[i] = p2[i] - p1[i];
		}

		//calculate the left side of the inequation (x cross v) ^ 2 <= (v^2) * R^2
		vector <i64> prod = crossP(v,x);
		i64 p = dotP(prod, prod);

		//the right side
		i64 q = dotP(v, v) * R * R;

		//test if it fails
		if(p > q)return "NO";

		//test if they are already in an undermiss situation
		i64 now = dotP(x,x);
		if(now <= R*R)return "YES";

		//test if they will nearmiss in the future
		i64 z = dotP(x, v);
		if(z >= 0LL)return "NO";
		else return "YES";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int p1[]                  = {15,50,5};
			int v1[]                  = {25,1,0};
			int p2[]                  = {161,102,9};
			int v2[]                  = {-10,-10,-1};
			int R                     = 10;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int p1[]                  = {0,0,0};
			int v1[]                  = {2,2,0};
			int p2[]                  = {9,0,5};
			int v2[]                  = {-2,2,0};
			int R                     = 5;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int p1[]                  = {0,0,0};
			int v1[]                  = {-2,2,0};
			int p2[]                  = {9,0,5};
			int v2[]                  = {2,2,0};
			int R                     = 5;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int p1[]                  = {-2838,-7940,-2936};
			int v1[]                  = {1,1,-2};
			int p2[]                  = {532,3850,9590};
			int v2[]                  = {1,0,-3};
			int R                     = 3410;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int p1[]                  = {-8509,9560,345};
			int v1[]                  = {-89,-33,62};
			int p2[]                  = {-5185,-1417,2846};
			int v2[]                  = {-58,24,26};
			int R                     = 8344;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int p1[]                  = {-7163,-371,-2459};
			int v1[]                  = {-59,-41,-14};
			int p2[]                  = {-2398,-426,-5487};
			int v2[]                  = {-43,27,67};
			int R                     = 5410;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int p1[]                  = {1774,-4491,7810};
			int v1[]                  = {-12,19,-24};
			int p2[]                  = {2322,3793,9897};
			int v2[]                  = {-12,19,-24};
			int R                     = 10000;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int p1[]                  = {3731,8537,5661};
			int v1[]                  = {-70,71,32};
			int p2[]                  = {8701,-1886,-5115};
			int v2[]                  = {28,-13,7};
			int R                     = 9766;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int p1[]                  = ;
			int v1[]                  = ;
			int p2[]                  = ;
			int v2[]                  = ;
			int R                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int p1[]                  = ;
			int v1[]                  = ;
			int p2[]                  = ;
			int v2[]                  = ;
			int R                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int p1[]                  = ;
			int v1[]                  = ;
			int p2[]                  = ;
			int v2[]                  = ;
			int R                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Aircraft().nearMiss(vector <int>(p1, p1 + (sizeof p1 / sizeof p1[0])), vector <int>(v1, v1 + (sizeof v1 / sizeof v1[0])), vector <int>(p2, p2 + (sizeof p2 / sizeof p2[0])), vector <int>(v2, v2 + (sizeof v2 / sizeof v2[0])), R);
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
