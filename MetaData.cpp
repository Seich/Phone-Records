#include "MetaData.h"

MetaData::MetaData() {}

MetaData::MetaData(string filename, fstream * f) {
	this->filename = filename;
	this->setStream(f);
}

void MetaData::setStream(fstream * f) {
	if (f->peek() == std::ifstream::traits_type::eof()) {
		return;
	}

	while(f->good()) {
		char avail[255];
		f->getline(avail, 255);
		avail_list.push_back(atoi(avail));
	}
}

void MetaData::addAvailSpot(int index) {
	if (std::find(this->avail_list.begin(), this->avail_list.end(), index) == this->avail_list.end()) {
		this->avail_list.push_back(index);
	}
}

MetaData::~MetaData() {
	fstream file(this->filename, fstream::trunc | fstream::out);

	if (!this->avail_list.empty()) {
		for (auto i = this->avail_list.begin(); i != this->avail_list.end(); ++i) {
			file << *i << '\n';
		}
	}

	file.flush();
	file.close();
}