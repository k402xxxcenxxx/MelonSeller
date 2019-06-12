#pragma once
#include <string>
#include <mutex>

using namespace std;

class Seller
{
public:
	Seller(string seller_name, int melon_count) :
		name(seller_name), melon_count(melon_count) {};

	~Seller();

	mutex sell_lock;

	void SellMelon();
	string last_customer;

	inline string GetName() {
		return name;
	}
	inline int GetCount() {
		return melon_count;
	}

private:

	string name;
	int melon_count;

};

