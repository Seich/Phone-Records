#pragma once
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class ADTFile {
public:
	fstream file;

	ADTFile();
	ADTFile(string file, ios_base::openmode mode);
	void open(string file, ios_base::openmode mode);
	void close();
	int read(char buffer[], size_t size);
	int write(char buffer[], size_t size);
	void flush();
	bool seek(int offset);
	bool isOpen();
	bool isEOF();
	~ADTFile();
};