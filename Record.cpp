#include "Record.h"

Record::Record() {}

Record::Record(int num_fields, int lengths[], string fields[]) {
	this->defineFields(num_fields, lengths);
	this->setValues(num_fields, fields);
}

void Record::defineField(int position, int length) {
	this->fields[position] = make_pair(length, "");
}

void Record::defineFields(int num_fields, int lengths[]) {
	for (int i = 0; i < num_fields; i++) {
		this->defineField(i, lengths[i]);
	}
}

void Record::setValue(int position, string value) {
	int size = this->fields[position].first;
	value.resize(size, ' ');
	this->fields[position].second = value;
}

void Record::setValues(int num_fields, string fields[]) {
	for (int i = 0; i < num_fields; i++) {
		this->setValue(i, fields[i]);
	}
}

ostream& operator<<(ostream& stream, const Record& r) {
	for (auto iter = r.fields.begin(); iter != r.fields.end() ; ++iter)	{
		stream << iter->second.second;
	}

	return stream;
}

Record::~Record() {
}
