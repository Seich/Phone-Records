#include "Record.h"

Record::Record() {}

Record::Record(int num_fields, int lengths[], string fields[]) {
	this->defineFields(num_fields, lengths);
	this->setValues(num_fields, fields);
}

void Record::defineField(int position, int length) {
	this->fields[position] = make_pair(length, "");
}

int Record::length() {
	int l = 0;
	for(auto iter = this->fields.begin(); iter != this->fields.end(); ++iter) {
		l += iter->second.first;
	}

	return l;
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

string Record::getField(int i) {
	return this->fields[i].second;
}

void Record::parseString(string str) {
	int pos = 0;
	for (auto iter = this->fields.begin(); iter != this->fields.end() ; ++iter)	{
		iter->second.second = str.substr(pos, iter->second.first);
		pos += iter->second.first;
	}
}

Record::~Record() {
}
