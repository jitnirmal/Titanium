#include "FileReader.h"



namespace titanium {
	namespace IO {
		csvReader::csvReader(const std::string& fileName, const char delim) :
			_fileName(fileName),
			_delim(delim) {}

		std::vector<std::string> split(const std::string &s, char delim) {
			std::stringstream ss(s);
			std::string item;
			std::vector<std::string> elems;
			while (std::getline(ss, item, delim)) {
				elems.push_back(std::move(item));
			}
			return elems;
		}

		std::vector<std::vector<std::string>> csvReader::getDataAsVectorOFStringFields() {
			std::ifstream file(_fileName);
			std::vector<std::vector<std::string> > dataList;

			std::string line;
			// Iterate through each line and split the content using delimeter
			auto firstRecord = true;
			while (getline(file, line))
			{
				if (firstRecord)
				{
					// skip the header...
					firstRecord = false;
					continue;
				}
				dataList.push_back(split(line, _delim));
			}
			// Close the File
			file.close();
			return dataList;
		}

		static void TestCSVReader()
		{
			auto file = std::string{ "F:\\2018\\Coding\\Tester\\Files\\" };
			file = file.append("OrdersIn.csv");
			const auto delim = ',';
			auto reader = std::make_unique<csvReader>(file, delim);
			auto data = reader->getDataAsVectorOFStringFields();

		}
	} /*ordersInt*/
} /*titanium*/
