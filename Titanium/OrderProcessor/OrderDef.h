#pragma once
#include "Instrument.h"
#include <string>

namespace titanium {
	namespace op {

		
		enum class TxnType
		{
			NEW,
			AMEND,
			CANCEL
		};

		enum class OrderType
		{
			LIMIT,
			LIMIT_ON_OPEN,
			LIMIT_ON_CLOSE,
			MARKET,
			MARKET_ON_OPEN,
			MARKET_ON_CLOSE,
			IOC
		};

		
		enum class TradingSide 
		{
			BUY = 1,
			SELL = 2
		};


		class OrderDef
		{
		public:
			OrderDef()=default;
			~OrderDef() = default;

			//void setInstrument(const product::);
			//const product::Instrument*		getInstrument() const;

			void setSide(TradingSide side);
			TradingSide getSide() const;

			void setType(OrderType orderType);
			OrderType getType() const;

			void setSymbol(const std::string& value);
			std::string getSymbol() const;

			std::string getSideAsString() const noexcept;
			std::string getTypeAsString() const noexcept;
					
			friend std::ostream& operator<<(std::ostream& os, const OrderDef& orderDef);

		private:
			TradingSide			_side;
			OrderType	    	_orderType;
			std::string			_orderId;
			std::string			_symbol; // should be replaced by INstrument*
			//const			Instrument* _instrument;
		};

		inline TradingSide OrderDef::getSide() const
		{
			return _side;
		}

		inline void OrderDef::setSide(TradingSide side)
		{
			_side = side;
		}

		inline OrderType OrderDef::getType() const
		{
			return _orderType;
		}

		inline void OrderDef::setType(OrderType orderType)
		{
			_orderType = orderType;
		}
	

		inline std::string OrderDef::getSymbol() const
		{
			return _symbol;
		}

		inline void OrderDef::setSymbol(const std::string& value)
		{
			_symbol = value;
		}
		
	

	}
}
