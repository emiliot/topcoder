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

class AzimuthMonitoring {
public:
	int getAzimuth( vector <string> v ) {
		int deg = 0;
		
		for(int i=0, n=(int)v.size(); i<n; ++i){
			int x;
			string cmd;

			istringstream iss(v[i]);
			iss >> cmd;
			if(cmd == "LEFT"){
				if(v[i] == cmd)x = 270;
				else {
					iss >> x;
					x = 360 - x;
				}
			}else if(cmd == "RIGHT"){
				if(v[i] == cmd)x = 90;
				else iss >> x;
			}else if(cmd == "TURN"){
				x = 180;
			}else if(cmd == "HALT"){
				break;
			}

			deg = ((deg % 360) + (x % 360)) % 360;
		}

		return deg;
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
			string instructions[]     = {"RIGHT"};
			int expected__            = 90;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string instructions[]     = {"LEFT", "LEFT", "TURN AROUND"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string instructions[]     = {"LEFT 5", "RIGHT 10", "LEFT 15", "RIGHT 20", "LEFT 25", "RIGHT 30", "LEFT 35", "RIGHT 40"};
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string instructions[]     = {"RIGHT 59", "RIGHT", "RIGHT", "HALT", "LEFT", "LEFT", "LEFT"};
			int expected__            = 239;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string instructions[]     = {"TURN AROUND", "HALT", "LEFT 5", "HALT", "LEFT 5", "HALT"};
			int expected__            = 180;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string instructions[]     = {"LEFT", "LEFT", "LEFT", "LEFT", "LEFT", "HALT"};
			int expected__            = 270;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string instructions[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string instructions[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string instructions[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AzimuthMonitoring().getAzimuth(vector <string>(instructions, instructions + (sizeof instructions / sizeof instructions[0])));
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
