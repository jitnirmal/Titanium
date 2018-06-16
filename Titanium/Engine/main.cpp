#include <iostream>
#include "Order.h"
#include "MData.h"
#include "OrderStore.h"
int main()
{
	using store = titanium::ordersInt::OrderStore;
	auto file = std::string{ "F:\\2018\\Coding\\Tester\\Files\\" };
	file = file.append("OrdersIn.csv");
	const auto delim = ',';

	auto sp = std::make_shared<int>(300);
	
	try {
		auto oStore = std::make_unique<store>(file, delim);
		oStore->getOrderStoreFromFile();
		oStore->Print();
		
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception caught building Order Store..." << ex.what()<< std::endl;
	}
	catch (...)
	{
		std::cout << "Exception caught building Order Store..." << std::endl;
	}
	std::cout << "Order Manager Testing" << std::endl;
	return true;
}
