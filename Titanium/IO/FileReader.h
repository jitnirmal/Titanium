#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <filesystem>
#include <type_traits>
#include <string>
#include <tuple>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = std::experimental::filesystem;

namespace titanium {
	namespace IO {

		class csvReader {
		private:
			std::string _fileName;
			const char _delim;
		private:
			template <std::size_t I = 0, typename Iterator, typename ...Ts>
			typename std::enable_if< (I == sizeof...(Ts)), void>::type
				parse(std::tuple<Ts...> &tuple, Iterator it)
			{
			};

			template <std::size_t I = 0, typename Iterator, typename ...Ts>
			typename std::enable_if< (I < sizeof...(Ts)), void>::type
				parse(std::tuple<Ts...> &tuple, Iterator it)
			{
				std::get<I>(tuple) = boost::lexical_cast<typename std::tuple_element<I, std::tuple<Ts...> >::type >(*it);
				parse<I + 1, Iterator, Ts...>(tuple, ++it);
			};

		

		public:
			csvReader(const std::string& fileName, const char delim = ',');
			std::vector<std::vector<std::string>> getDataAsVectorOFStringFields();
			
			template <typename ...Ts>
			std::vector<std::tuple<Ts...>> getDataAsTupleFields(std::tuple<Ts...> tuple);
		};

		template <typename ...Ts>
		std::vector<std::tuple<Ts...>> csvReader::getDataAsTupleFields(std::tuple<Ts...> tuple)
		{
			std::vector<std::tuple<Ts...>> OutDataVector;
			std::string delim =",";
			
			auto convertor = [&](const std::string& line) {
				std::vector<std::string> fields;
				boost::split(fields, line, boost::is_any_of(delim));
				parse(tuple, fields.begin());
				return tuple;
			};

			using istream_iterator = std::istream_iterator<std::string>;
			std::ifstream file(_fileName);
			std::vector<std::string> input;

			std::copy(istream_iterator(file), istream_iterator(),
				std::back_inserter(input));
			file.close();

			// remove the header
			input.erase(std::begin(input));

			std::transform(std::begin(input), std::end(input), std::back_inserter(OutDataVector),convertor);
			return OutDataVector;
		}

	
	} // ordersInt end
} // titanium end