#include <iostream>
#include "Order.h"
#include "MData.h"
#include "OrderStore.h"
#include "OrderService.h"
#include <chrono>
#include <thread>

int main()
{
	using store = titanium::ordersInt::OrderStore;
	auto file = std::string{ "F:\\2018\\Coding\\Tester\\Files\\" };
	file = file.append("OrdersIn.csv");
	const auto delim = ',';

	titanium::op::OrderService::Instance().start();
	titanium::op::OrderMatcher::Instance().Init();
	

	try {
		auto oStore = std::make_unique<store>(file, delim);
		oStore->GetOrderStoreFromFile();
		oStore->PostOrders();
	//	std::cout << *oStore << std::endl;
		
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
	
	using namespace std::chrono_literals;
	while (true)
	{
		std::this_thread::sleep_for(3s);
	}

	return 0;
}
