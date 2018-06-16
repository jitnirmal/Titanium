#include "OrderService.h"
#include "OrderEvtIn.h"

namespace titanium {
	namespace op {
		void OrderService::onEvent(core::IEvent* event)
		{
		//	std::cout << typeid(event).name() << std::endl;
			auto OrderEvt = static_cast<ordersInt::OrderEvtIn*>(event);
			auto order = *(OrderEvt->Data);
			auto symbol = order.orderDef().getSymbol();
			auto obIter = _orderBookByInstrument.find(symbol);
			
			OrderBook* ob = nullptr;
			if (obIter != _orderBookByInstrument.end())
			{
				ob = &obIter->second;
			}
			else
			{
				ob = new OrderBook();
				_orderBookByInstrument[symbol] = *ob;
			}
			OrderMatcher::Instance().process(order, *ob);
		}
	}
}