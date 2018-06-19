#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "OrderDef.h"
#include "OrderEvtIn.h"
#include "util.h"
#include <memory>


namespace titanium {
	namespace ordersInt {

		class OrderStore {
		public:
			OrderStore(const std::string& fileName, const char delim = ',');
			~OrderStore() = default;
			void GetOrderStoreFromFile();
			void PostOrders();
			friend std::ostream& operator<<(std::ostream& os, const OrderStore& ostore);
			
		private:
			std::vector<ShOrderPtr> _store;
			std::string _fileName;
			const char _delim;
		};

		
	
		
	}
}
