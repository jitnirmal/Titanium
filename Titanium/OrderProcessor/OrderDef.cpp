#include "OrderBook.h"

namespace titanium {
	namespace op {

		OrderDef::OrderDef()
		{
		}

		OrderDef::~OrderDef()
		{
		}

		std::string OrderDef::getTypeAsString() const noexcept
		{
			switch (_orderType)
			{
			case OrderType::LIMIT:
				return "LIMIT";
			default:
				return "UNKNOWN";
			}
		}
		std::string OrderDef::getSideAsString() const noexcept
		{
			switch (_side)
			{
			case TradingSide::BUY:
				return "BUY";
			default:
				return "SELL";
			}
		}
		std::ostream& operator<<(std::ostream& os, const OrderDef& orderDef)
		{
			os << " | side : " << orderDef.getSideAsString()
				<< " | OrderType : " << orderDef.getTypeAsString()
				<< " | Symbol : " << orderDef._symbol;
			return os;
		}

	}
}