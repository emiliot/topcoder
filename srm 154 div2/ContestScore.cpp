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

double eps = 1e-9;

struct team{
	vector <double> scores;
	vector <int> ranks;
	double cscore;
	int crank;
	string name;
	team(){
		cscore = 0.0;
		crank = 0;
	}
	bool operator <(const team &x)const{
		if(crank < x.crank)return true;
		else if(x.crank < crank)return false;
		else if(fabs(x.cscore - cscore) < eps)return name < x.name;
		else if(cscore > x.cscore)return true;
		else if(x.cscore > cscore)return false;
		else return name < x.name;
	}
};

string f(double x){
	char buffer[20];
	sprintf(buffer, "%.1lf", x);
	return string(buffer);
}
string g(int x){
	char buffer[20];
	sprintf(buffer, "%d", x);
	return string(buffer);
}

struct ContestScore {
	vector <string> sortResults(vector <string> data) {
		vector <team> v;
		for(int i=0, n=data.size(); i<n; ++i){
			istringstream iss(data[i]);
			team next;
			iss >> next.name;
			double score;
			while(iss >> score){
				next.scores.push_back(score);
				next.cscore += score;
			}
			v.push_back(next);
		}
		//get the rank per team
		if(v.size() > 0){
			for(int i=0, n=v[0].scores.size(); i<n; ++i){
				vector < pair <double, int> >nextScore(v.size());
				for(int j=0, m=v.size(); j<m; ++j){
					nextScore[j].first = v[j].scores[i];
					nextScore[j].second = j;
				}
				sort(all(nextScore));
				reverse(all(nextScore));
				for(int j=0, r=1, m=v.size(); j<m;){
					double x = nextScore[j].first;
					v[nextScore[j].second].ranks.push_back(r);
					v[nextScore[j].second].crank += r;
					int k = j+1;
					for(; k<m && fabs(nextScore[k].first - x) < eps; ++k){
						v[nextScore[k].second].ranks.push_back(r);
						v[nextScore[k].second].crank += r;
					}
					j=k;
					r=j+1;
				}
			}
		}
		sort(all(v));
		vector <string> res(v.size(), "");
		for(int i=0, n=v.size(); i<n; ++i){
			res[i] = v[i].name + ' ' + g(v[i].crank) + ' ' + f(v[i].cscore);
		}
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case( int casenum, const vector <string> &expected, const vector <string> &received ) { 
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
			string data[]             = {"A 90.7 92.9 87.4",  "B 90.5 96.6 88.0",  "C 92.2 91.0 95.3"};
			string expected[]         = { "C 5 278.5",  "B 6 275.1",  "A 7 271.0" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
		case 1: {
			string data[]             = {"STANFORD 85.3 90.1 82.6 84.6 96.6 94.5 87.3 90.3",  "MIT 95.5 83.9 80.4 85.5 98.7 98.3 96.7 82.7",  "PRINCETON 99.2 79.1 87.6 85.1 93.6 96.4 86.0 90.6",  "HARVARD 83.6 92.0 85.5 94.3 97.5 91.5 92.5 83.0",  "YALE 99.5 92.6 86.2 82.0 96.4 92.6 84.5 78.6",  "COLUMBIA 97.2 87.6 81.7 93.7 88.0 86.3 95.9 89.6",  "BROWN 92.2 95.8 92.1 81.5 89.5 87.0 95.5 86.4",  "PENN 96.3 80.7 81.2 91.6 85.8 92.2 83.9 87.8",  "CORNELL 88.0 83.7 85.0 83.8 99.8 92.1 91.0 88.9"};
			string expected[]         = { "PRINCETON 34 717.6",  "MIT 36 721.7",  "HARVARD 38 719.9",  "COLUMBIA 39 720.0",  "STANFORD 39 711.3",  "YALE 40 712.4",  "BROWN 41 720.0",  "CORNELL 42 712.3",  "PENN 51 699.5" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
		/*case 2: {
			string data[]             = {};
			string expected[]         = { };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}*/
		case 3: {
			string data[]             = {"AA 90.0 80.0 70.0 60.0 50.0 40.0",  "BBB 80.0 70.0 60.0 50.0 40.0 90.0",  "EEE 70.0 60.0 50.0 40.0 90.0 80.0",  "AAA 60.0 50.0 40.0 90.0 80.0 70.0",  "DDD 50.0 40.0 90.0 80.0 70.0 60.0",  "CCC 40.0 90.0 80.0 70.0 60.0 50.0"};
			string expected[]         = { "AA 21 390.0",  "AAA 21 390.0",  "BBB 21 390.0",  "CCC 21 390.0",  "DDD 21 390.0",  "EEE 21 390.0" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
		case 4: {
			string data[]             = {"A 00.1", "B 05.2", "C 29.0","D 00.0"};
			string expected[]         = { "C 1 29.0",  "B 2 5.2",  "A 3 0.1",  "D 4 0.0" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}

		// custom cases

      case 5: {
			string data[]             = {"CROATIA 91.3 81.3 82.4 89.2 90.1 94.3 81.9 86.2", "HUNGARY 82.7 86.2 89.0 88.9 86.3 87.6 87.0 79.0", "SWEDEN 96.8 83.7 80.1 79.5 97.0 91.8 83.9 87.0", "CHINA 96.2 82.8 76.0 82.3 86.6 75.6 98.6 76.1", "NORWAY 90.4 96.0 83.8 89.0 99.6 79.3 77.2 96.5", "POLAND 87.7 84.0 96.2 99.1 86.7 80.6 76.0 77.0", "UKRAINE 90.5 82.2 98.8 99.8 98.5 77.3 94.5 99.7", "GERMANY 99.5 95.3 75.6 78.9 91.6 94.9 86.2 80.4", "FRANCE 95.1 97.7 83.2 88.9 75.8 80.9 89.4 78.0", "AUSTRALIA 90.7 84.0 90.2 75.9 94.4 96.8 91.7 82.8", "DENMARK 88.9 79.4 76.3 75.3 81.8 97.1 84.1 83.6", "SINGAPORE 94.9 87.4 78.6 90.1 81.4 80.1 85.1 83.5", "NETHERLAND 91.9 93.8 77.5 93.6 98.6 77.3 85.0 80.9", "RUSSIANFED 75.8 88.2 77.2 76.0 88.2 81.0 93.5 97.1", "NEWZEALAND 75.9 98.8 83.3 83.4 78.5 87.0 93.9 93.7", "IRELAND 82.9 92.6 83.5 93.0 99.0 92.8 87.2 98.3", "MEXICO 76.2 88.9 89.8 88.8 81.5 79.1 90.2 88.4", "VENEZUELA 78.3 79.5 99.9 77.0 93.1 89.8 81.1 91.8", "IRAN 85.4 89.1 75.6 89.0 78.0 78.8 90.4 85.8", "BULGARIA 95.6 99.0 84.2 92.8 94.3 81.1 95.1 80.0", "ROMANIA 78.9 77.2 97.4 82.1 83.4 90.1 99.5 90.0", "CANADA 88.6 87.9 89.4 97.5 87.8 83.4 75.8 83.7", "BRAZIL 80.8 79.7 77.2 99.1 96.1 82.9 88.3 88.7", "UNITEDKING 85.3 96.9 82.8 83.7 93.5 96.5 76.9 96.4", "UNITEDSTAT 89.3 81.4 87.3 99.6 95.7 79.0 77.6 84.1", "SPAIN 93.8 87.8 98.9 92.2 85.2 84.9 92.3 91.4", "MALAYSIA 81.7 96.5 77.4 78.7 76.8 82.6 98.9 90.7", "INDIA 96.2 91.6 96.7 85.9 94.9 89.4 75.3 91.2", "PORTUGAL 77.6 75.7 82.3 75.8 83.3 85.8 96.5 97.3", "COLOMBIA 75.5 83.2 96.0 76.5 88.3 75.7 95.9 93.3"};
			string expected[]         = {"IRELAND 77 729.3", "UKRAINE 78 741.3", "BULGARIA 87 722.1", "SPAIN 89 726.5", "INDIA 94 721.2", "NORWAY 100 711.8", "UNITEDKING 106 712.0", "AUSTRALIA 110 706.5", "SWEDEN 115 699.8", "NEWZEALAND 119 694.5", "GERMANY 120 702.4", "NETHERLAND 120 698.6", "ROMANIA 122 698.6", "CROATIA 124 696.7", "CANADA 126 694.1", "UNITEDSTAT 128 694.0", "BRAZIL 128 692.8", "VENEZUELA 132 690.5", "FRANCE 132 689.0", "MALAYSIA 135 683.3", "HUNGARY 138 686.7", "POLAND 140 687.3", "COLOMBIA 141 684.4", "MEXICO 141 682.9", "RUSSIANFED 142 677.0", "SINGAPORE 144 681.1", "PORTUGAL 148 674.3", "IRAN 154 672.1", "CHINA 155 674.2", "DENMARK 167 666.5"};

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
      case 6: {
			string data[]             = {"AAA 85.7 98.1 86.4 46.9 01.8 88.2 04.6 54.5", "AAAAAA 37.3 15.5 96.1 67.1 75.8 42.4 32.7 20.7", "AAAAAAA 71.4 18.4 09.8 39.3 54.2 57.5 73.4 63.6", "AAAAA 31.7 30.0 39.0 68.5 42.1 88.2 54.6 41.0", "AA 76.5 98.1 15.3 88.7 01.8 54.7 94.1 54.5", "AAAAAAAA 35.3 33.1 86.4 18.5 65.8 47.3 00.7 84.4", "AAAAAAAAAA 65.4 19.4 22.2 46.9 39.6 37.4 63.5 54.2", "AAAA 71.2 80.0 50.2 72.5 70.8 31.1 02.3 17.0", "A 72.5 38.9 12.0 98.5 85.1 94.6 95.0 98.2", "AAAAAAAAA 31.1 45.8 24.4 68.4 23.1 12.0 04.6 94.9"};
			string expected[]         = {"A 22 594.8", "AA 34 483.7", "AAA 34 466.2", "AAAA 46 395.1", "AAAAA 46 395.1", "AAAAAA 48 387.6", "AAAAAAA 48 387.6", "AAAAAAAA 49 371.5", "AAAAAAAAA 52 304.3", "AAAAAAAAAA 54 348.6"};

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}
/*      case 7: {
			string data[]             = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ContestScore().sortResults( vector <string>( data, data + ( sizeof data / sizeof data[0] ) ) ) );
		}*/
		default:
			return -1;
		}
	}
}

int main() {
  moj_harness::run_test(6);
} 
// END CUT HERE
