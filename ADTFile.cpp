#include "ADTFile.h"

ADTFile::ADTFile(string file, ios_base::openmode mode) {
	this->open(file, mode);
}

void ADTFile::open(string file, ios_base::openmode mode) {
	this->file.open(file, mode);
}

int ADTFile::read(char buffer[], size_t size) {
	return 1;
}

int ADTFile::write(char buffer[], size_t size) {
	return 1;
}

void ADTFile::flush() {
	this->file.flush();
}

bool ADTFile::seek(int offset) {
	return true;
}

bool ADTFile::isOpen() {
	return this->file.is_open();
}

bool ADTFile::isEOF() {
	return this->file.eof();
}

void ADTFile::close() {
	this->file.close();
}

ADTFile::~ADTFile() {
	this->close();
}
