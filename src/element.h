#ifndef element_h
#define element_h

#include <string>
#include <vector>
using namespace std;

enum dataType{INT,FLOAT,VARCHAR};

class element {
public:
	bool lazyDelete = false;
	dataType dType;
	int length;
	union  {
		int intData;
		float floatData;
		char varchar[64];
	}innerElement;

	element() {};
	element(int intData) {
		memset(&innerElement, 0, sizeof(innerElement));
		dType = INT;
		length = sizeof(int);
		innerElement.intData = intData;
	};
	element(float floatData) {
		memset(&innerElement, 0, sizeof(innerElement));
		dType = FLOAT;
		length = sizeof(float);
		innerElement.floatData = floatData;
	};
	element(char* charData,int varCharLength) {
		memset(&innerElement, 0, sizeof(innerElement));
		dType = VARCHAR;
		length = varCharLength;
		memcpy_s(innerElement.varchar, sizeof(innerElement), charData, varCharLength);
	};
};

class data {
public:
	dataType dType;
	char dataName[32];
	bool unique;
	bool isPrimaryKey;

	data() {};
	data(dataType dType, char* dName, bool unique, bool isPrimaryKey) :
		dType(dType), unique(unique), isPrimaryKey(isPrimaryKey) {
		memset(dataName, 0, sizeof(dataName));
		strcpy_s(dataName, dName);
	};
};

class tableInfo {
public:
	char tableName[64];
	int colNum;
	vector <class data>dataInfos;

	tableInfo() {};
	tableInfo(char* tName, vector<class data>dataInfos) :
		dataInfos(dataInfos) {
		memset(tableName, 0, sizeof(tableName));
		strcpy_s(tableName, tName);
		colNum = dataInfos.size();
	};
};

#endif