#include <iostream>
#include <algorithm>
#include "ADTRecordFile.h"
#include "MetaData.h"

#define BUF_SIZE 1024

ADTRecordFile::ADTRecordFile(string filename) {
	filename = filename;
	filePath = "records/" + filename;
	file.open(this->filePath, fstream::in | fstream::out);
	file_meta.open(this->filePath + "_meta", fstream::in | fstream::out | fstream::app);
	
	if (!this->file_meta.good())	{
		this->file_meta.close();
		this->meta_data = MetaData(this->filePath + "_meta", &generateMetaData());
	} else {
		this->meta_data = MetaData(this->filePath + "_meta", &file_meta);
		this->file_meta.close();
	}
}

fstream ADTRecordFile::generateMetaData() {
	cout << "Creating: " << this->filePath + "_meta" << endl;
	fstream file_meta(this->filePath + "_meta", fstream::trunc | fstream::out);
	//TODO: look for empty spots in the record file?
	file_meta.flush();
	file_meta.close();

	return file_meta;
}

string ADTRecordFile::readRecord(int index, Record r) {
	char buffer[BUF_SIZE];
	string str;

	this->file.seekg(index * r.length(), ios_base::beg);
	this->file.read(buffer, r.length());

	for (int i = 0; i < r.length(); i++) {
		str += buffer[i];
	}

	return str;
}

void ADTRecordFile::add(Record r) {
	if (!this->meta_data.avail_list.empty()) {
		this->update(this->meta_data.avail_list.back(), r);
		this->meta_data.avail_list.pop_back();
	} else {
		this->file.seekp(0, ios_base::end);
		this->file << r;
		this->file.flush();
	}
}

void ADTRecordFile::find(int fieldIndex, Record * r) {
	for(int i = 0; i < this->size(*r); i++) {
		string str = this->readRecord(i, *r);
		if (string::npos != str.find(r->getField(0))) {
			r->parseString(str);
			break;
		}
	}
}

int ADTRecordFile::size(Record r) {
	this->file.seekg(0, fstream::end);
	int size = this->file.tellg();
	return size / r.length();
}

void ADTRecordFile::update(int index, Record r) {
	this->file.seekg(index * r.length(), ios_base::beg);
	this->file << r;
	this->file.flush();
}

void ADTRecordFile::remove(int index) {
	meta_data.addAvailSpot(index);
}

ADTRecordFile::~ADTRecordFile() {
	this->file.close();
	this->file_meta.close();
}