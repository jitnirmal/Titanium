#pragma once
#include <iostream>
#include "ObjectId.h"
#include "OrderBook.h"
#include "OrderMatcher.h"
#include <set>
#include <iostream>
#include "Service.h"
#include "Event.h"
#include "Singleton.h"
#include <unordered_map>

namespace titanium {
	namespace op {

		class OrderService : public core::Service, public util::SingletonBase<OrderService>
		{
		public:
			virtual void onEvent(core::IEvent* event) override;
		private:
			std::unordered_map<std::string, OrderBook> _orderBookByInstrument;
		};
	}
}
