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

		using spTrade = std::shared_ptr<Trade>;
		using spOrderBook = std::shared_ptr<OrderBook>;

		class IOrderMatcher : public util::Observer<spOrder>
		{
		public:
			IOrderMatcher() = default;
			virtual ~IOrderMatcher() = default;
			virtual void Init() = 0;
			virtual void onEvent(spOrder&) = 0;

		};

		class OrderMatcher : public IOrderMatcher,  public util::SingletonBase<OrderMatcher>
		{
		public:
			OrderMatcher() = default;
			virtual ~OrderMatcher() = default;
			void Init() override;
			void onEvent(spOrder&) override;
		private:
			std::unordered_map<std::string, spOrderBook> _orderBookByInstrument;
			spTrade process(spOrder& order, spOrderBook& orderBook);


		};


	}
}
