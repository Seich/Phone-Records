#include <iostream>
#include "ADTRecordFile.h"
#include "Record.h"
using namespace std;

int main() {
	ADTRecordFile rf("phones");

	Record phoneRecord;

	phoneRecord.defineField(0, 8); 
	phoneRecord.defineField(1, 2);
	phoneRecord.defineField(2, 13);

	phoneRecord.setValue(1, "AT");

	Record phoneRecord2;

	int lengths[] = {8, 2, 13};
	string fields[] = {"98853820", "AT", "12345678901234"};	

	phoneRecord2.defineFields(3, lengths); 
	phoneRecord2.setValues(3, fields);

	Record phoneRecord3(3, lengths, fields);

	//rf.update(0, phoneRecord);
	//rf.remove(4);

	rf.find(1, &phoneRecord);

	cout << phoneRecord;

	system("pause");
	return 0;
}