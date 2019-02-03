#pragma once

#include <cassert>
#include <fstream>
#include <string>
#include "Log/Log.h"

class FileIO
{
public:
	FileIO()=default;
	FileIO(const std::string_view filePath);

	unsigned int Read();
	void Write(unsigned int highScore);

private:
	FileIO(const FileIO& obj)=delete;
	FileIO& operator=(const FileIO&)=delete;

	std::string m_file;
};