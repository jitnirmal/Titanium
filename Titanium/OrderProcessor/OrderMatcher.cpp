#include "OrderMatcher.h"

namespace titanium {
	namespace op {

		TradePtr OrderMatcher::process(Order& mktOrder, OrderBook& orderBook)
		{
			
			long tradedQty{ 0 };
			long remainingQty { 0 };
			double tradedPrice { 0.0 };
			bool matched{ false };

			const OrderSet& orderSet = (mktOrder.orderDef().getSide() == TradingSide::BUY ? orderBook.buyOrders() : orderBook.sellOrders());
			
			// Match with other side
			for (auto& obOrder : orderSet)
			{
				if (obOrder->getMarketPrice() == mktOrder.getMarketPrice())
				{
					tradedPrice = obOrder->getMarketPrice();
					remainingQty = obOrder->getMarketQty() - mktOrder.getMarketQty();

					if (remainingQty > 0)
					{
						// mkt order < oB matched order
						obOrder->setMarketQty(remainingQty);
						obOrder->SetAlive(true);
						mktOrder.setMarketQty(0);
						mktOrder.SetAlive(false);
						tradedQty = mktOrder.getMarketQty();
					}
					else if(remainingQty == 0)
					{
						// mkt order == oB matched order
						obOrder->setMarketQty(0);
						obOrder->SetAlive(false);
						mktOrder.setMarketQty(0);
						mktOrder.SetAlive(false);
						tradedQty = mktOrder.getMarketQty();
						orderBook.removeOrder(obOrder);
						
					}
					else
					{
						// mkt order > oB matched order
						obOrder->setMarketQty(0);
						obOrder->SetAlive(false);
						mktOrder.setMarketQty(abs(remainingQty));
						mktOrder.SetAlive(true);
						tradedQty = obOrder->getMarketQty();
						orderBook.removeOrder(obOrder);
						orderBook.addOrder(&mktOrder);
					}
					matched = true;
					break;
				}
			}

			if (matched == false)
			{
				orderBook.addOrder(&mktOrder);
			}
			auto tradePtr = std::make_shared<Trade>(tradedQty, tradedPrice, &mktOrder);
			return tradePtr;
		}

	}
}