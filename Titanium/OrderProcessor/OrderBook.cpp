#include "OrderBook.h"

namespace titanium {
	namespace op {

		void OrderBook::addOrder(const spOrder& order)
		{
			OrderSet& orderSet = (order->orderDef().getSide() == TradingSide::BUY ? _buyOrders : _sellOrders);
			orderSet.insert(order);
			//order->addObserver(*this);
		}

		void OrderBook::removeOrder(const spOrder& order)
		{
			OrderSet& orderSet = (order->orderDef().getSide() == TradingSide::BUY ? _buyOrders : _sellOrders);
			orderSet.erase(order);
		}
	}
}