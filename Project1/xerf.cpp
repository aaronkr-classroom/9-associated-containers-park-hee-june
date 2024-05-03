//xerf.cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"



using namespace std;

//입력에서 각 단어가 등장한 모든 행을 찾음.
map<string, vector <int> > xref(
	istream& in,
	vector<string> find_words(const string&) = split
){
	string line;
	int line_num = 0;
	map<string, vector<int>>ret;

	while (getline(in, line)) {
		++line_num;
		// 입력한 행을 단어로 나눔
		vector<string> words = find_words(line);


		//현재행에 등장한 모든 단어를 저장
		for (vector<string>::const_iterator it = words.begin();
			it != words.end(); ++it) {
			ret[*it].push_back(line_num);
		}
	}
	return ret;
}

int main() {
	// 기본 인수인 split 함수를 사용하여 xref 함수를 호출
	map<string, vector<int>> ret = xref(cin);

	//결과를 출력
	for (map<string, vector<int>>::const_iterator it = ret.begin();
		it != ret.end(); ++it) {

		cout << "\"" << it->first << "\" is on line(s): ";

		vector<int>::const_iterator line_it = it->second.begin();

		cout << *line_it;
		++line_it;

		while (line_it != it->second.end()) {
			cout << "," << *line_it;
			++line_it;


		}
		//각 단어를 다음 단어와 구분하려고 새로운 행을 출력
		cout << endl;

	}
	return 0;
}