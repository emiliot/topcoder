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

int memo[51][51][51];
bool mark[51][51][51];
int choice[51][51][51];

int f(vector <int> &tv, vector <int> &pv, vector <int> &exp, int skillBound, int tva, int pva, int k){
	if(tva >= skillBound && pva >= skillBound)return k;

	int &best = memo[tva][pva][k];
	if(mark[tva][pva][k])return best;
	mark[tva][pva][k] = true;

	best = INF;

	for(int i=0, n=(int)tv.size(); i<n; ++i){
		//discard some courses
		if((tv[i] <= tva && pv[i] <= pva) || k >= exp[i])continue;

		//check if we have the minimun requirements for the course
		if(tva >= tv[i] -1 && pva >= pv[i] -1 && k < exp[i]){
			int next = f(tv, pv, exp, skillBound, max(tva, tv[i]), max(pva, pv[i]), k+1);
			if(next < best){
				best = next;
				choice[tva][pva][k] = i;
			}
		}
	}

	return best;
}

vector <int> g(vector <int> &tv, vector <int> &pv, int tva, int pva, int k){
	vector <int> res;
	for(int i=0; i<k; ++i){
		int &ch = choice[tva][pva][i];
		res.push_back(ch);
		tva = max(tva, tv[ch]);
		pva = max(pva, pv[ch]);
	}

	return res;
}

class CsCourses {
public:
	vector <int> getOrder( vector <int> tv, vector <int> pv, vector <int> exp, int skillBound ) {
		memset(mark, false, sizeof(mark));
		memset(choice, -1, sizeof(choice));

		int months = f(tv, pv, exp, skillBound, 0, 0, 0);

		vector <int> res;
		if(months >= INF)return res;
		else res = g(tv, pv, 0, 0, months);

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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int theoreticalValue[]    = {1};
			int practicalValue[]      = {1};
			int expire[]              = {1};
			int skillBound            = 1;
			int expected__[]          = {0 };

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int theoreticalValue[]    = {1, 2, 1};
			int practicalValue[]      = {2, 1, 1};
			int expire[]              = {5, 5, 5};
			int skillBound            = 2;
			int expected__[]          = {2, 0, 1 };

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int theoreticalValue[]    = {1, 2, 1};
			int practicalValue[]      = {2, 1, 1};
			int expire[]              = {1, 1, 1};
			int skillBound            = 2;
			// int expected__[]       = empty, commented out for VC++;

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(), received__, clock()-start__);
		}
		case 3: {
			int theoreticalValue[]    = {1, 2, 1};
			int practicalValue[]      = {2, 1, 1};
			int expire[]              = {3, 2, 1};
			int skillBound            = 2;
			int expected__[]          = {2, 1, 0 };

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int theoreticalValue[]    = {1, 2, 3, 4, 5, 6, 7};
			int practicalValue[]      = {1, 2, 3, 4, 5, 6, 7};
			int expire[]              = {1, 2, 3, 4, 5, 6, 7};
			int skillBound            = 7;
			int expected__[]          = {0, 1, 2, 3, 4, 5, 6 };

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int theoreticalValue[]    = {0, 1, 2, 2, 1};
			int practicalValue[]      = {0, 0, 1, 2, 1};
			int expire[]              = {9, 9, 9, 9, 9};
			int skillBound            = 2;
			int expected__[]          = {4, 3 };

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int theoreticalValue[]    = ;
			int practicalValue[]      = ;
			int expire[]              = ;
			int skillBound            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int theoreticalValue[]    = ;
			int practicalValue[]      = ;
			int expire[]              = ;
			int skillBound            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int theoreticalValue[]    = ;
			int practicalValue[]      = ;
			int expire[]              = ;
			int skillBound            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = CsCourses().getOrder(vector <int>(theoreticalValue, theoreticalValue + (sizeof theoreticalValue / sizeof theoreticalValue[0])), vector <int>(practicalValue, practicalValue + (sizeof practicalValue / sizeof practicalValue[0])), vector <int>(expire, expire + (sizeof expire / sizeof expire[0])), skillBound);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
