#pragma once
#ifndef GUARD_split_h
#define GUARD_split_h

#include<algorithm> //find_if()
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// �μ��� ������ ���� true,�׷��� �������� false
bool space(char c);  

// �μ��� ������ ���� true,�׷��� �������� false
bool not_space(char c);

vector<string>split(const string&);
	

#endif