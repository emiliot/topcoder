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

int dist[52][52];

int memo[1 << 12][52];
bool mark[1 << 12][52];

int f(vector < pair <int, int> > &v, int mask, int k){
	if(mask == (1 << (int)v.size())-1){
		return dist[k][0];
	}

	int &best = memo[mask][k];
	if(mark[mask][k])return best;
	mark[mask][k] = true;
	best = INF;

	for(int i=0, n=(int)v.size(); i<n; ++i){
		if(!(mask & (1 << i))){
			int cost = dist[k][v[i].first] + dist[v[i].first][v[i].second] + f(v, mask | (1 << i), v[i].second);
			//printf("DEBUG cost: %d %d %d\n", dist[k][v[i].first], dist[v[i].first][v[i].second], f(v, mask | (1 << i), v[i].second));
			best = min(best, cost);
		}
	}

	return best;
}

class TaxiManager {
public:
	int schedule( vector <string> roads, vector <string> customers ) {
		memset(dist, INF, sizeof(dist));
		for(int i=0, n=(int)roads.size(); i<n; ++i){
			for(int j=0; j<n; ++j){
				if(i != j && roads[i][j] == '0')dist[i][j] = INF;
				else dist[i][j] = roads[i][j]-'0';
			}
		}

		for(int k=0, n=(int)roads.size(); k<n; ++k){
			for(int i=0; i<n; ++i){
				for(int j=0; j<n; ++j){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		vector < pair <int, int> >v(customers.size());
		for(int i=0, n=(int)customers.size(); i<n; ++i){
			istringstream iss(customers[i]);
			iss >> v[i].first >> v[i].second;
		}

		memset(mark, false, sizeof(mark));

		int res = INF;
		for(int i=0, n=(int)customers.size(); i<(1 << n); ++i){
			int a = f(v, i, 0), b = f(v, (1 << n) - 1 - i, 0);
			//printf("DEBUG: %d %d\n", a, b);
			res = min(res, max(a,b));
		}


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
			string roads[]            = {"020200"
,"202020"
,"020002"
,"200020"
,"020202"
,"002020"};
			string customers[]        = {"5 3","2 4","1 5","3 2"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = TaxiManager().schedule(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string roads[]            = 
{"00020251090265906661"
,"00763002550100090081"
,"06003699000080062771"
,"00000710460400035310"
,"50000039119198350060"
,"66060004050810046028"
,"02333108565000200880"
,"40212560000209205231"
,"02601150098329905062"
,"00210383709951005203"
,"10111087340780827070"
,"05065800003095040140"
,"15604020082000100090"
,"83430030070580600750"
,"10588355007006001150"
,"14400080790005400536"
,"23400990400933060004"
,"11053016300602000090"
,"90040920084059282502"
,"61300007077904050900"};
			string customers[]        = {"0 19","4 16","15 16","4 18","2 7","9 15","11 6","7 13","19 13","12 19","14 12","16 1"};
			int expected__            = 33;

			clock_t start__           = clock();
			int received__            = TaxiManager().schedule(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string roads[]            = 
{"095222800320504"
,"107600288090501"
,"760973530769345"
,"963093337510830"
,"338404069255826"
,"291700050155264"
,"002783031709004"
,"404730701707712"
,"068870030090995"
,"320025180036103"
,"468695042801904"
,"233626561000105"
,"070014432197086"
,"887301000143802"
,"230852749990330"};
			string customers[]        = {"3 6","0 4","2 7","9 7","13 9","1 6","7 13","14 2","8 7","10 1","11 13","7 12"};
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = TaxiManager().schedule(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string roads[]            = {"00401","50990","00062","08008","03000"};
			string customers[]        = {"2 4"};
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = TaxiManager().schedule(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string roads[]            = ;
			string customers[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaxiManager().schedule(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string roads[]            = ;
			string customers[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaxiManager().schedule(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string roads[]            = ;
			string customers[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaxiManager().schedule(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
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
