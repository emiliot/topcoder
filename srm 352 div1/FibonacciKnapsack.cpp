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

map <i64, i64> memo[60];
vector <i64> wSum, pSum;

i64 f(vector < pair <i64, i64> > &v, int i, i64 w){
	if(i >= (int) v.size())return 0LL;
	if(wSum[i] <= w)return pSum[i];
	
	pair < map<i64, i64>::iterator, bool > best = memo[i].insert(make_pair(w, 0LL));
	if(!best.second){
		//printf("DEBUG: return best %lld\n", best.first->second);
		return best.first->second;
	}
	
	best.first->second = f(v, i+1, w);
	if(v[i].first <= w){
		best.first->second = max(best.first->second , f(v, i+1, w-v[i].first) + v[i].second);
	}
	return best.first->second;
}

bool func(const pair <i64, i64> &a, const pair <i64, i64> &b){
	if(a.first > b.first)return true;
	else if(b.first > a.first)return false;
	else return a.second > b.second;
}

class FibonacciKnapsack {
public:
	long long maximalCost( vector <string> items, string C ) {
		//clear memo
		for(int i=0, n=(int)items.size(); i<=n; ++i)
			memo[i].clear();
		
		//start the accumulate vectors
		wSum = vector <i64>(items.size());
		pSum = vector <i64>(items.size());
		
		vector < pair<i64, i64> > v(items.size());
		for(int i=0, n=(int)items.size(); i<n; ++i){
			istringstream iss (items[i]);
			iss >> v[i].first >> v[i].second;
			//printf("%lld %lld\n", v[i].first, v[i].second);
		}
		
		istringstream iss(C);
		i64 w; iss >> w;
		
		sort(all(v), func);
		
		wSum[items.size()-1] = v[items.size()-1].first;
		pSum[items.size()-1] = v[items.size()-1].second;
		
		for(int i=(int)items.size()-2; i>=0; --i){
			wSum[i] = wSum[i+1] + v[i].first;
			pSum[i] = pSum[i+1] + v[i].second;
		}
		
		i64 res = f(v, 0, w);
		
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			string items[]            = {"5 555", "8 195", "13 651"};
			string C                  = "15";
			long long expected__      = 750;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string items[]            = {"5 555", "8 195", "13 751"};
			string C                  = "15";
			long long expected__      = 751;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string items[]            = {"55 1562", "5 814", "55 1962", "8 996", "2 716", "34 1792"};
			string C                  = "94";
			long long expected__      = 4568;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string items[]            = {"13 89"};
			string C                  = "1";
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string items[]            = {"27777890035288 9419696870097445", 
 "53316291173 6312623457097563", 
 "165580141 8848283653257131"};
			string C                  = "27777900000000";
			long long expected__      = 15160907110354694LL;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string items[]            = {"1 1", "3 3", "8 8", "21 22", "55 58", "144 154", "377 398", "987 1078", "2584 2767", "6765 6246", "17711 17357", "46368 49904", "121393 111673", "317811 315134", "832040 852003", "2178309 2179780", "5702887 5561401", "14930352 13536842", "39088169 36258843", "102334155 94095856", "267914296 263305016", "701408733 686898834", "1836311903 1873835344", "4807526976 4459950680", "12586269025 13081701305", "32951280099 30406291095", "86267571272 78981321516", "225851433717 213523573373", "591286729879 638564057352", "1548008755920 1425704823028", "4052739537881 4064579961123", "10610209857723 10390053437847", "27777890035288 28272247627944", "72723460248141 67233497970436", "190392490709135 174480261235311", "498454011879264 450890031951922", "1304969544928657 1177956759447242", "3416454622906707 3076040435502997", "8944394323791464 8053096735146361", "2 2", "5 5", "13 14", "34 35", "89 84", "233 243", "610 593", "1597 1556", "4181 3995", "10946 10367", "28657 29903"};
			string C                  = "9001563299090000";
			long long expected__      = 8098231314967143;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string items[]            = ;
			string C                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string items[]            = ;
			string C                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FibonacciKnapsack().maximalCost(vector <string>(items, items + (sizeof items / sizeof items[0])), C);
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
