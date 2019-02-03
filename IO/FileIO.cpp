#include "FileIO.h"

FileIO::FileIO(const std::string_view filePath) :
m_file(filePath.data())
{
	assert(typeid(filePath) == typeid(std::string_view) && !filePath.empty() && "Filepath cannot be an empty value");
}

unsigned int FileIO::Read()
{
	unsigned int value;

	std::ifstream inFile;
	inFile.open(m_file);
	if (inFile.fail())
	{
		GUNN_CORE_ERROR("Error opening file: {0}", m_file.c_str());
	}

	inFile >> value;

	inFile.close();

	return value;
}

void FileIO::Write(unsigned int highScore)
{
	std::ofstream outFile;
	outFile.open(m_file);
	if (outFile.fail())
	{
		GUNN_CORE_ERROR("Error writing to file: {0}", m_file.c_str());
	}

	outFile << highScore;

	outFile.close();
}