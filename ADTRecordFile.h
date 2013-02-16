#pragma once
#include "Record.h"
#include "RecordSet.h"
#include <string>

using namespace std;

class ADTRecordFile {
public:
	ADTRecordFile(string filename);
	bool add(Record r);
	RecordSet find(int fieldIndex, string value);
	bool update(int index, Record r);
	bool remove(int index);
	RecordSet list();
	~ADTRecordFile();
};