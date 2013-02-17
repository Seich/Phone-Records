#pragma once
#include "Record.h"
#include "ADTFile.h"
#include "RecordSet.h"
#include "MetaData.h"
#include <string>

using namespace std;

class ADTRecordFile {
protected:
	ADTFile file;
	ADTFile file_meta;
	MetaData meta_data;
	string filename;
	string filePath;

public:
	ADTRecordFile(string filename);
	void add(Record r);
	ADTFile generateMetaData();
	RecordSet find(int fieldIndex, string value);
	void update(int index, Record r);
	void remove(int index);
	RecordSet list();
	~ADTRecordFile();
};