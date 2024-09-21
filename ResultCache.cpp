#include "pch.h"
#include "ResultCache.h"


ResultCache::ResultCache()
{

}

ResultCache::~ResultCache()
{

}

bool ResultCache::saveToFile()
{
	// Open output file and append the new data to the end.
	std::fstream outputFile(this->fileName, std::ios::app);

	// Opening was successful.
	if (outputFile)
	{
		for (int i = 0; i < this->resultCache.size(); i++)
			outputFile << this->resultCache[i];
	}
	else
		return false;

	this->clearCache();

	return true;
}

bool ResultCache::isFileNameSet()
{
	if (this->fileName != "")
		return true;
	else
		return false;
}

void ResultCache::setFileName(std::string fileName)
{
	this->fileName = fileName;
}

void ResultCache::appendExpression(std::string expression)
{
	this->resultCache.push_back(expression);
}

void ResultCache::clearCache()
{
	this->resultCache.clear();
}