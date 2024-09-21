#pragma once

#include <string>
#include <vector>
#include <fstream>

class ResultCache
{
	public:
		ResultCache();
		~ResultCache();

		void setFileName(std::string fileName);
		bool saveToFile();
		bool isFileNameSet();

		void appendExpression(std::string expression);
		void clearCache();

	private:
		std::string fileName;
		std::vector<std::string> resultCache;
};