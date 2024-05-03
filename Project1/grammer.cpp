// grammer.cpp
#include <iostream>// find()
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include  <vector>
#include <string>
#include "split.h"
#include <map>
using namespace std;

//["dog","cat","cup","table"]


typedef vector<string> Rule;
//["hat","car"]+["dog","cat"]
typedef vector<Rule>  Rule_collection;

typedef map<string, Rule_collection> Grammar;

//주어진 입력 스트림으로 문법 테이블을 읽음
Grammar read_grammar(istream& in) {
	Grammar ret;
	string line;

	while (getline(in, line)) {

		vector<string> entry = split(line);
		if (!entry.empty()) {
			ret[entry[0]].push_back(Rule(entry.begin()+1, entry.end()));
		}
	}
	return ret;
}
bool bracketed(const string& s) {
	return s.size() > 1
		&& s[0] == '<' && s[s.size() - 1] == '>';
}
//[0,n) 범위에서 임의 정수 하나를 반환
int nrand(int n) {
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("nrand is out of range!");

	const int bucket_size = RAND_MAX / n;
	int r;
	do r = rand() / bucket_size;
	while (r >= n);

	return r;

}
void gen_aux(const Grammar& g, const string& word,
	vector<string>& ret) {
	if (!bracketed(word))
		ret.push_back(word);
	else {
		Grammar::const_iterator it = g.find(word);

		if (it == g.end())
			throw logic_error("Empty rule!");

		const Rule_collection& c = it->second;

		const Rule& r = c[nrand(c.size())];

		//선택한 규칙을 재귀적으로 확장\
		
	for(Rule::const_iterator i = r.begin();
		i != r.end(); ++i){
			gen_aux(g,*i,ret);
		}


	}
}

vector<string> gen_sent(const Grammar& g) {
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}
int main() {
	// 문장 생성
	vector<string> sentence = gen_sent(read_grammar(cin));

	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}
	while (it != sentence.end()) {
		cout << " " << *it;
		++it; 
	}
	cout << endl;
	return 0;
}
