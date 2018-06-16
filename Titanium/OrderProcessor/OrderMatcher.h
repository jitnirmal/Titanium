#pragma once
#include "Order.h"
#include "OrderBook.h"
#include "Trade.h"
#include <memory>

namespace titanium {
	namespace op {

		using TradePtr = std::shared_ptr<Trade>;
		class IOrderMatcher
		{
		public:
			IOrderMatcher();
			virtual ~IOrderMatcher();

			virtual TradePtr match(Order& order,OrderBook& orderBook) = 0;


		};

		class OrderMatcher : public IOrderMatcher
		{
		public:
			OrderMatcher();
			virtual ~OrderMatcher();

			virtual TradePtr match(Order& order, OrderBook& orderBook) override;

		};


	}
}
