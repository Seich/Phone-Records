#pragma once
#include <fstream>
#include <vector>
using namespace std;

class MetaData {
protected:
	string filename;

public:
	vector<int> avail_list;
	MetaData();
	MetaData(string filename, fstream * f);
	void setStream(fstream * f);
	void addAvailSpot(int index);
	~MetaData();
};

