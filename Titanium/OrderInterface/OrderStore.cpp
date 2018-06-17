#include "OrderStore.h"
#include "OrderService.h"
#include "OrderEvtIn.h"

namespace titanium {
	namespace ordersInt {
		OrderStore::OrderStore(const std::string& fileName, const char delim) 
			:_fileName(fileName),
			_delim(delim) {}
		
		

		void OrderStore::PostOrders()
		{
			for (auto& spOrder : _store)
			{
				auto& os = op::OrderService::Instance();
				auto spEvt = std::make_shared<ordersInt::OrderEvtIn>(spOrder);
				os.post(boost::bind(&core::Service::onEvent, &os, spEvt));
			}
		}
		void OrderStore::GetOrderStoreFromFile()
		{

			//UniqueID	ClientOrderId	Symbol	 TradingSide	OrderType	TxnType	MarketPrice	MarketQty
			_store.clear();
			auto reader = std::make_unique<csvReader>(_fileName, _delim);
			auto data = reader->getData();

			auto firstRecord = true;
			for (const auto& row : data)
			{
				if (firstRecord)
				{
					firstRecord = false;
					continue;
				}
				auto so = std::make_shared<op::Order>();
				for (const auto& field : row)
				{
					std::cout << field << " ";
					std::cout << field << " ";
					auto uniqueID = std::stoll(row[0]);
					so->setUniqueId(uniqueID);

					auto ClientOrderId = row[1];

					auto symbol = row[2];
					so->orderDef().setSymbol(symbol);

					auto tradingSide = row[3];
					if (util::str_toupper(tradingSide) == "B")
					{
						so->orderDef().setSide(op::TradingSide::BUY);
					}
					else
					{
						so->orderDef().setSide(op::TradingSide::SELL);
					}

					auto orderType = row[4];
					if (util::str_toupper(orderType) == "LMT")
					{
						so->orderDef().setType(op::OrderType::LIMIT);
					}
					else
					{
						// throw exception.. we dont handle other types now
					}


					auto txnType = row[5];
					if (util::str_toupper(txnType) == "N")
					{
						so->setTxnType(op::TxnType::NEW);
					}
					else if (util::str_toupper(txnType) == "A")
					{
						so->setTxnType(op::TxnType::AMEND);
					}
					else
					{
						so->setTxnType(op::TxnType::CANCEL);
					}

					auto marketPrice = std::stod(row[6]);
					so->setMarketPrice(marketPrice);

					auto marketQty = std::stol(row[7]);
					so->setMarketQty(marketQty);
				}
				_store.push_back(so);
				std::cout << std::endl;
			}

		}

		std::ostream& operator<<(std::ostream& os, const OrderStore& orderStore)
		{
			for (const auto& spOrder : orderStore._store)
			{
				std::cout << *spOrder << std::endl;
			}
			return os;
		}

	}
}
