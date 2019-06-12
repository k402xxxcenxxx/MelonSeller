#include "pch.h"
#include <iostream>
#include <thread>
using namespace std;


void BuyMelon(Customer* customer, Seller* seller) {

	// Check the name to avoid the same customer buying all the melons from the vendor
	if (seller->last_customer != customer->GetName() && seller->GetCount() > 0) {
		
		// held the key and lock seller, after this function will release the key
		lock_guard<mutex> mLock(seller->sell_lock);

		seller->SellMelon();
		customer->BuyMelon();

		//cout << customer->GetName() << " buys a melon." << endl;

		// record the name
		seller->last_customer = customer->GetName();
	}
}

void BuyMelons(Customer* customer, Seller* seller) {

	while (seller->GetCount() > 0) {

		BuyMelon(customer, seller);
	}
}

int main(int argc, char** argv)
{
	Seller broChao("BroChao", 1000000);

	Customer benson("Benson");
	Customer vince("Vince");

	thread mThread1(BuyMelons, &benson, &broChao);
	thread mThread2(BuyMelons, &vince, &broChao);

	mThread1.join();
	mThread2.join();

	cout << "Benson totally buys " << benson.GetCount() << " melons." << endl;
	cout << "Vince totally buys " << vince.GetCount() << " melons." << endl;

	return 0;
}