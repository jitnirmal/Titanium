#include <iostream>
#include <vector>
#include "Order.h"
#include "OrderDef.h"
#include "FileReader.h"
#include "util.h"
#include <memory>

namespace titanium {
	namespace ordersInt {

		using shOrderPtr = std::shared_ptr<op::Order>;

		class OrderStore {
		public:
			OrderStore(const std::string& fileName, const char delim = ',') :
				_fileName(fileName),
				_delim(delim) {}
			
			void getOrderStoreFromFile()
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
						if(util::str_toupper(tradingSide) == "B")
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

						auto marketQty = std::stoll(row[7]);
						so->setMarketQty(marketQty);
					}
					_store.push_back(so);
					std::cout << std::endl;
				}


			}
			void Print()
			{
				for (const auto& order : _store)
				{
					std::cout << *order << std::endl;
				}
			}
		private:
			std::vector<shOrderPtr> _store;
			std::string _fileName;
			const char _delim;
		};
	
		
	}
}
