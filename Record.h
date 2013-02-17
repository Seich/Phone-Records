#pragma once
#include <map>;
#include <string>;
#include <vector>

using namespace std;

class Record {
private:
	map<int, pair<int, string>> fields;

public:
	Record();
	Record(int num_fields, int lengths[], string fields[]);
	void defineField(int position, int length);
	void defineFields(int num_fields, int lengths[]);

	void setValue(int position, string value);
	void setValues(int num_fields, string fields[]);

	friend ostream& operator<<(ostream& stream, const Record& r);

	~Record();
};

