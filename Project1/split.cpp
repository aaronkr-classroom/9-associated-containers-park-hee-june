#include<algorithm> //find_if()
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 인수가 공백일 때는 true,그렇지 않을때는 false
bool space(char c)
{
	return isspace(c);
}
// 인수가 공백일 때는 true,그렇지 않을때는 false
bool not_space(char c)
{
	return !isspace(c);
}
vector<string>split(const string& str) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> ret;

	// for(iter i = str.begin(); i != str.end(); i++
	while (i != str.end()) {
		
		// 선행 공백을 무시
		// 지금 i위치부터 첫 번째 뛰어쓰기 아닌 문자 찾기
		i = find_if(i, str.end(), not_space);
		

		//다음 단어의 끝을 찾음
		//while 반복
		iter j = find_if(i, str.end(), space);
		

		if (i != str.end()) {
			ret.push_back(string(i, j));

		}
		i = j;
		
	}
	return ret;
}
