#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Customer
{
	int id;
	string name;
	Customer* next;
};