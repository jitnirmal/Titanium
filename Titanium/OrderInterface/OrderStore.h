#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "OrderDef.h"
#include "FileReader.h"
#include "util.h"
#include <memory>


namespace titanium {
	namespace ordersInt {

		using shOrderPtr = std::shared_ptr<op::Order>;

		class OrderStore {
		public:
			OrderStore(const std::string& fileName, const char delim = ',');
			~OrderStore() = default;
			void GetOrderStoreFromFile();
			friend std::ostream& operator<<(std::ostream& os, const OrderStore& ostore);
			
		private:
			std::vector<shOrderPtr> _store;
			std::string _fileName;
			const char _delim;
		};

		
	
		
	}
}
