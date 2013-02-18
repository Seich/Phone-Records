#pragma once
#include <fstream>
#include <string>
#include "Record.h"
#include "RecordSet.h"
#include "MetaData.h"

using namespace std;

class ADTRecordFile {
protected:
	fstream file;
	fstream file_meta;
	MetaData meta_data;
	string filename;
	string filePath;
	fstream generateMetaData();

public:
	ADTRecordFile(string filename);
	void add(Record r);
	void find(int fieldIndex, Record * r);
	void update(int index, Record r);
	void remove(int index);
	int size(Record r);

	string readRecord(int index, Record r);
	~ADTRecordFile();
};