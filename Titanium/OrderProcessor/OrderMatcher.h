#pragma once
#include "Order.h"
#include "OrderBook.h"
#include "Trade.h"
#include "Util.h"
#include <memory>
#include "Observer.h"
#include "Singleton.h"
#include <unordered_map>
namespace titanium {
	namespace op {

		using TradePtr = std::shared_ptr<Trade>;

		class IOrderMatcher : public util::Observer<op::Order>
		{
		public:
			IOrderMatcher() = default;
			virtual ~IOrderMatcher() = default;

			virtual void onEvent(Order&) = 0;

		};

		class OrderMatcher : public IOrderMatcher,  public util::SingletonBase<OrderMatcher>
		{
		public:
			OrderMatcher() = default;
			virtual ~OrderMatcher() = default;

			virtual void onEvent(Order&) override;

			void Init();
		private:
			std::unordered_map<std::string, OrderBook> _orderBookByInstrument;
			TradePtr process(Order& order, OrderBook& orderBook);


		};


	}
}
