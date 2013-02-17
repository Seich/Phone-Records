#include "ADTRecordFile.h"
#include "ADTFile.h"
#include "MetaData.h"

ADTRecordFile::ADTRecordFile(string filename) {
	filename = filename;
	filePath = "/records" + filename;
	file.open(this->filePath, fstream::in | fstream::out);
	file_meta.open(this->filePath.append("_meta"), fstream::in | fstream::out);
	
	if (!this->file_meta.file.good())	{
		this->file_meta.close();

		generateMetaData();
	}

	MetaData meta_data();
}

ADTFile ADTRecordFile::generateMetaData() {
	ADTFile file(this->filePath.append("_meta"), fstream::trunc | fstream::out);
	file.file << "sergio";

	return file;
}

void ADTRecordFile::add(Record r) {
}

RecordSet ADTRecordFile::find(int fieldIndex, string value) {
	return RecordSet();
}

void ADTRecordFile::update(int index, Record r) {
}

void ADTRecordFile::remove(int index) {
}

RecordSet ADTRecordFile::list() {
	return RecordSet();
}

ADTRecordFile::~ADTRecordFile() {
}