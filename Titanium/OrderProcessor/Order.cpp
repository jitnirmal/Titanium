#include "Order.h"

namespace titanium {
	namespace op {
		Order::Order()
		{

		}
		Order::~Order()
		{

		}
		OrderDef& Order::orderDef()
		{
			return _orderDef;
		}

		bool IdComparator::operator()(const spOrder x, const spOrder y) const
		{
			return (x->_uniqueID < y->_uniqueID);
		}
		
		std::string Order::getTxnTypeAsString() const noexcept
		{
			switch (_txnType)
			{
			case TxnType::NEW:
					return "NEW";
			case TxnType::AMEND:
				return "AMEND";
			default :
				return "CANCEL";
			}
		}
	
	

		std::ostream& operator<<(std::ostream& os, const Order& order)
		{
			os << " UniqueID : " << order._uniqueID
				<< " | MarketQty : " << order._marketQty
				<< " | MarketPrice : " << order._marketPrice
				<< " | TxnType : " << order.getTxnTypeAsString()
				<<  order._orderDef;
			return os;
		}

	}
}