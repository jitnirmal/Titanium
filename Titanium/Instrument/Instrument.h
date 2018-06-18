#include <iostream>

namespace titanium {
	namespace product {

		enum class InstrumentType : int16_t
		{
			STOCK,
			FUTURE,
			OPTION
		};

		class Instrument
		{
		public:
			

			Instrument()= default;
			virtual ~Instrument() =default;

			void setName(const std::string&);
			const std::string& getName() const;

			void setupMarket(const std::string& market);
			const std::string& getMarket() const;

			InstrumentType getType() const { return _type; }

		protected:
			std::string			_name;
			std::string			_market;
			InstrumentType		_type = { InstrumentType::STOCK };
		};

		inline void Instrument::setName(const std::string&  name)
		{
			_name = name;
		}

		inline const std::string& Instrument::getName() const
		{
			return _name;
		}

	
		inline void Instrument::setupMarket(const std::string& market)
		{
			_market = market;
		}

		inline const std::string& Instrument::getMarket() const
		{
			return _market;
		}

	

	}
}
