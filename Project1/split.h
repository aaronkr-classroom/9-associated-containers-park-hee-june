#pragma once
#ifndef GUARD_split_h
#define GUARD_split_h

#include<algorithm> //find_if()
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 인수가 공백일 때는 true,그렇지 않을때는 false
bool space(char c);  

// 인수가 공백일 때는 true,그렇지 않을때는 false
bool not_space(char c);

vector<string>split(const string&);
	

#endif