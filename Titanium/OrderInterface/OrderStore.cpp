#include "OrderStore.h"
#include "OrderService.h"
#include "OrderEvtIn.h"
#include "FileReader.h"

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
			auto reader = std::make_unique<IO::csvReader>(_fileName, _delim);
			using FieldTuple = std::tuple<util::UID,std::string, std::string, std::string, std::string, std::string,double, long>;
			FieldTuple fields;
			auto data = reader->getDataAsTupleFields(fields);

		
			for (const auto& record : data)
			{

				auto so = std::make_shared<op::Order>();

				so->setUniqueId(std::get<0>(record));
				auto ClientOrderId = std::get<0>(record);
				so->orderDef().setSymbol(std::get<2>(record));

				auto tradingSide = std::get<3>(record);
				if (util::str_toupper(tradingSide) == "B")
				{
					so->orderDef().setSide(op::TradingSide::BUY);
				}
				else
				{
					so->orderDef().setSide(op::TradingSide::SELL);
				}

				auto orderType = std::get<4>(record);
				if (util::str_toupper(orderType) == "LMT")
				{
					so->orderDef().setType(op::OrderType::LIMIT);
				}
				else
				{
					// throw exception.. we dont handle other types now
				}


				auto txnType = std::get<5>(record);
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

				so->setMarketPrice(std::get<6>(record));
				so->setMarketQty(std::get<7>(record));

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
