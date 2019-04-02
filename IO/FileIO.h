#pragma once

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
	std::string mFile;
};