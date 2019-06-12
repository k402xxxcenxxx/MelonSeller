#pragma once
#include <string>

using namespace std;

class Customer
{
public:
	Customer(string customer_name) :
		name(customer_name) {};

	~Customer();

	void BuyMelon();

	inline string GetName() {
		return name;
	}

	inline int GetCount() {
		return melon_count;
	}

private:
	string name;
	int melon_count = 0;
};

