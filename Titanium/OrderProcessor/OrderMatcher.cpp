#include "OrderMatcher.h"
#include "OrderService.h"

namespace titanium {
	namespace op {

		void OrderMatcher::Init() {
			OrderService::Instance().addObserver(*this);
		}

		void OrderMatcher::onEvent(spOrder& spOdr)
		{
			auto symbol = spOdr->orderDef().getSymbol();
			auto obIter = _orderBookByInstrument.find(symbol);

			spOrderBook spOrdBook;
			if (obIter != _orderBookByInstrument.end())
			{
				spOrdBook = obIter->second;
			}
			else
			{
				spOrdBook = std::make_shared<OrderBook>();
				_orderBookByInstrument[symbol] = spOrdBook;
			}

			process(spOdr, spOrdBook);
		}


		spTrade OrderMatcher::process(spOrder& spMktOrder, spOrderBook& spOrdBook)
		{
			
			long tradedQty{ 0 };
			long remainingQty { 0 };
			double tradedPrice { 0.0 };
			bool matched{ false };

			const OrderSet& orderSet = (spMktOrder->orderDef().getSide() == TradingSide::BUY ? spOrdBook->buyOrders() : spOrdBook->sellOrders());
			
			// Match with other side
			for (auto& obOrder : orderSet)
			{
				if (obOrder->getMarketPrice() == spMktOrder->getMarketPrice())
				{
					tradedPrice = obOrder->getMarketPrice();
					remainingQty = obOrder->getMarketQty() - spMktOrder->getMarketQty();

					if (remainingQty > 0)
					{
						// mkt order < oB matched order
						obOrder->setMarketQty(remainingQty);
						obOrder->SetAlive(true);
						spMktOrder->setMarketQty(0);
						spMktOrder->SetAlive(false);
						tradedQty = spMktOrder->getMarketQty();
						std::cout << "trade : partial qty consumed " << *spMktOrder << std::endl;
					}
					else if(remainingQty == 0)
					{
						// mkt order == oB matched order
						obOrder->setMarketQty(0);
						obOrder->SetAlive(false);
						spMktOrder->setMarketQty(0);
						spMktOrder->SetAlive(false);
						tradedQty = spMktOrder->getMarketQty();
						spOrdBook->removeOrder(obOrder);
						std::cout << "trade : full qty consumed " << *spMktOrder << std::endl;
						
					}
					else
					{
						// mkt order > oB matched order
						obOrder->setMarketQty(0);
						obOrder->SetAlive(false);
						spMktOrder->setMarketQty(abs(remainingQty));
						spMktOrder->SetAlive(true);
						tradedQty = obOrder->getMarketQty();
						spOrdBook->removeOrder(obOrder);
						spOrdBook->addOrder(spMktOrder);
						std::cout << "trade : full qty consumed with order insert" << *spMktOrder << std::endl;
					}
					matched = true;
					break;
				}
			}

			if (matched == false)
			{
				spOrdBook->addOrder(spMktOrder);
				std::cout << "new order in OB " << *spMktOrder << std::endl;
			}
			auto sptrade = std::make_shared<Trade>(tradedQty, tradedPrice, spMktOrder);
			return sptrade;
		}

	}
}