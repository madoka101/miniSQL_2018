#include "BufferManger.h"
#include <iostream>

using namespace std;
int main(void) {
	bufferManager bfm;
	string thisTable = "testTable";
	bfm.newTableBuffer(thisTable);

	if ( bfm.getTableInfo(thisTable)== false)
		cout << "fail to load table info" << endl;
	cout << "rowSize is "<< bfm.tableBufferMap[thisTable]->rowSize << endl;
	cout << "table Info::" << bfm.tableBufferMap[thisTable]->tableName <<"|| colNum::"<< bfm.tableBufferMap[thisTable]->tInfo.colNum << endl;

	bfm.loadTable(thisTable);

	element a1(16);
	element a2(13.5F);
	element a3("insertVARCHAR4", sizeof("insertVARCHAR"));
	char insertBuff[256];
	memset(insertBuff, 0, 256);
	memcpy(insertBuff, &a1, sizeof(element));
	memcpy(insertBuff+sizeof(element), &a2, sizeof(element));
	memcpy(insertBuff+2*sizeof(element), &a3, sizeof(element));

	//bfm.insertIntoTable(thisTable,insertBuff);
	//bfm.deleteFromTable(thisTable,4096 + bfm.tableBufferMap[thisTable]->pagePool[1]->usedLength - 256);
	//bfm.writeBackTable(thisTable);
	char*tmp=bfm.queryTable(thisTable, 5540);
	printf("%s", tmp);
}