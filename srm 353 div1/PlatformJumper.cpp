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

struct platform{
	int x, y, coins;
	bool operator <(const platform &other)const{
		return y < other.y;
	}
};

int memo[100];
bool mark[100];
i64 hs, gr;

bool ok(platform &a, platform &b){
	if(a.y <= b.y)return false;
	i64 dx = abs(a.x - b.x);
	i64 dy = abs(a.y - b.y);
	return gr * dx * dx <= 2*hs*hs*dy;
}

int f(vector <platform> &v, vector < vector <int> >&graph, int i){
	if(graph[i].size() <= 0)return 0;
	
	int &best = memo[i];
	if(mark[i])return best;
	mark[i] = true;
	
	best = 0;
	for(int k=0, n=(int)graph[i].size(); k<n; ++k){
		int next = f(v, graph, graph[i][k]) + v[graph[i][k]].coins;
		best = max(best, next);
	}
	
	return best;
}

class PlatformJumper {
public:
	int maxCoins( vector <string> platforms, int hspd, int g ) {
		hs = hspd;
		gr = g;
		
		vector <platform> v(platforms.size());
		for(int i=0, n=(int)platforms.size(); i<n; ++i){
			istringstream iss(platforms[i]);
			iss >> v[i].x >> v[i].y >> v[i].coins;
		}
		
		vector < vector < int > >graph(platforms.size());
		for(int i=0, n=(int)graph.size(); i<n; ++i){
			for(int j=0; j<n; ++j){
				if(i == j)continue;
				if(ok(v[i], v[j])){
					graph[i].push_back(j);
				}
			}
		}
		
		int best = 0;
		memset(mark, false, sizeof(mark));
		for(int i=0, n=(int)graph.size(); i<n; ++i){
			best = max(best, f(v, graph, i) + v[i].coins);
		}
		
		/*for(int i=0, n=(int)graph.size(); i<n; ++i){
			printf("%d", (int)graph[i].size());
			for(int j=0, m=graph[i].size(); j<m; ++j){
				printf(" %d", graph[i][j]);
			}
			printf("\n");
		}*/
		
		return best;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = 4, bool quiet = false) {
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
			string platforms[]        = {"3 10 7", "5 15 7", "8 9 12" };
			int v                     = 2;
			int g                     = 10;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = PlatformJumper().maxCoins(vector <string>(platforms, platforms + (sizeof platforms / sizeof platforms[0])), v, g);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string platforms[]        = {"0 0 1", "2 4 1", "4 0 1"};
			int v                     = 1;
			int g                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PlatformJumper().maxCoins(vector <string>(platforms, platforms + (sizeof platforms / sizeof platforms[0])), v, g);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string platforms[]        = {"0 0 1", "5000 5000 10"};
			int v                     = 100;
			int g                     = 87;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = PlatformJumper().maxCoins(vector <string>(platforms, platforms + (sizeof platforms / sizeof platforms[0])), v, g);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 3: {
			string platforms[]        = {"0 0 1", "2 4 1", "4 0 2"};
			int v                     = 2;
			int g                     = 9;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PlatformJumper().maxCoins(vector <string>(platforms, platforms + (sizeof platforms / sizeof platforms[0])), v, g);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 4: {
			string platforms[]        = ;
			int v                     = ;
			int g                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlatformJumper().maxCoins(vector <string>(platforms, platforms + (sizeof platforms / sizeof platforms[0])), v, g);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			string platforms[]        = ;
			int v                     = ;
			int g                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlatformJumper().maxCoins(vector <string>(platforms, platforms + (sizeof platforms / sizeof platforms[0])), v, g);
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
