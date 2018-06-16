#pragma once
#include "Order.h"
#include "OrderBook.h"
#include "Trade.h"
#include "Util.h"
#include <memory>
#include "Singleton.h"
namespace titanium {
	namespace op {

		using TradePtr = std::shared_ptr<Trade>;

		class IOrderMatcher
		{
		public:
			IOrderMatcher() = default;
			virtual ~IOrderMatcher() = default;

			virtual TradePtr process(Order& order,OrderBook& orderBook) = 0;


		};

		class OrderMatcher : public IOrderMatcher,  public util::SingletonBase<OrderMatcher>
		{
		public:
			OrderMatcher() = default;
			virtual ~OrderMatcher() = default;

			virtual TradePtr process(Order& order, OrderBook& orderBook) override;

		};


	}
}
