#include <iostream>
#include "ADTRecordFile.h"
#include "Record.h"
using namespace std;

int main() {
	ADTRecordFile rf("clients");

	Record phoneRecord;

	phoneRecord.defineField(0, 8); 
	phoneRecord.defineField(1, 2);
	phoneRecord.defineField(2, 13);

	phoneRecord.setValue(0, "98853820");
	phoneRecord.setValue(1, "AT");
	phoneRecord.setValue(2, "12345678901234");

	Record phoneRecord2;

	int lengths[] = {8, 2, 13};
	string fields[] = {"98853820", "AT", "12345678901234"};	

	phoneRecord2.defineFields(3, lengths); 
	phoneRecord2.setValues(3, fields);

	Record phoneRecord3(3, lengths, fields);

	cout << phoneRecord3 << endl << phoneRecord2 << endl << phoneRecord << endl;

	system("pause");
	return 0;
}