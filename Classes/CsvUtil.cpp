#include "CsvUtil.h"
#include "FileLoadUtil.h"
#include "StringUtil.h"

CsvUtil* CsvUtil::mCsvUtil = NULL;

CsvUtil* CsvUtil::sharedCsvUtil(){
    if(mCsvUtil == NULL) {
        mCsvUtil = new CsvUtil();
        if(mCsvUtil && mCsvUtil->init()) {
            mCsvUtil->autorelease();
        }
        else {
            CC_SAFE_DELETE(mCsvUtil);
            mCsvUtil = NULL;
        }
    }

    return mCsvUtil;
}

bool CsvUtil::init(){

    /* ��ʼ����Ա���� */
    mCsvDict = CCDictionary::create();
    mCsvDict->retain();
	mCsvUtil->retain();
    
    return true;
}

void CsvUtil::loadFile( const char* sPath ){

    /* 
        ���һ��csv�ļ����ַ�������б�ÿ���Ӷ���Ϊһ���ַ����顣
        ����д���ܱȽϺü��䣺CCArray<CCArray>
    */
    CCArray* csvStrList = CCArray::create();

    /* ��ȡÿһ�е����ݣ����浽�ַ������飬��ӵ��б��� */
    /* ��ȡ���ݣ����б��浽�б��� */
    CCArray* linesList = FileLoadUtil::sharedFileLoadUtil()->getDataLines(sPath);

    /* ��ÿһ�е��ַ�����ֳ����������ŷָ��� */
    CCObject* obj;
    CCString* tString = NULL;
    CCARRAY_FOREACH(linesList, obj) {
        /* ȡ��һ���ַ��� */
        tString = (CCString *) obj;

        if(tString) {
            /* 
                ��һ�е��ַ��������ŷָ���Ȼ���ŵ��б��С�
                ���仰˵��csvStrList����Ϊһ����ά��񣬼�¼�������ļ��к��е��ַ���
            */
            CCArray* tArr = StringUtil::sharedStrUtil()->split(tString->getCString(), ",");
            csvStrList->addObject(tArr);
        }
    }

    /* ����б��ֵ��� */
    mCsvDict->setObject(csvStrList, sPath);
}

void CsvUtil::releaseFile( const char* sPath ){
	mCsvDict->removeObjectForKey(sPath);
}

const char* CsvUtil::get( int iRow, int iCol, const char* csvFilePath ) {
    /* ȡ�������ļ��Ķ�ά��� */
    CCObject* csvObj = mCsvDict->objectForKey(csvFilePath);

    /* ��������ļ������ݲ����ڣ�����������ļ� */
    if(csvObj == NULL) {
        loadFile(csvFilePath);
    }
    CCArray* csvStrList = (CCArray *) mCsvDict->objectForKey(csvFilePath);

    CCSize size = getFileRowColNum(csvFilePath);

    /* �������� */
    int iRowNum = size.width;
    int iColNum = size.height;

    /* �±�Խ�� */
    if(iRow >= iRowNum || iCol >= iColNum) {
        return "";
    }

    /* ��ȡ��iRow������ */
    CCObject* rowObj = csvStrList->objectAtIndex(iRow);

    if(rowObj != NULL) {
        CCArray* rowArr = (CCArray *) rowObj;

        /* ��ȡ��iCol������ */
        CCObject* colObj = rowArr->objectAtIndex(iCol);

        if(colObj != NULL) {
            CCString* colStr = (CCString *) colObj;
            return colStr->getCString();
        }
    }

    return "";
}

const CCSize CsvUtil::getFileRowColNum( const char* csvFilePath )
{

    /* ȡ�������ļ��Ķ�ά��� */
    CCObject* csvObj = mCsvDict->objectForKey(csvFilePath);

    /* ��������ļ������ݲ����ڣ�����������ļ� */
    if(csvObj == NULL) {
        loadFile(csvFilePath);
    }

    CCArray* csvStrList = (CCArray *) mCsvDict->objectForKey(csvFilePath);

    /* �������� */
    int iRowNum = csvStrList->count();
    int iColNum = 0;
    if(iRowNum > 0) {
        /* ��ȡ��0������ */
        CCObject* rowObj = csvStrList->objectAtIndex(0);

        if(rowObj != NULL) {
            CCArray* rowArr = (CCArray *) rowObj;

            /* �������� */
            iColNum = rowArr->count();
        }
    }
    CCSize size = CCSize(iRowNum, iColNum);
    return size;
}

const int CsvUtil::getInt( int iRow, int iCol, const char* csvFilePath ) {
	const char* chData = get(iRow, iCol, csvFilePath);

	return atoi(chData);
}

const float CsvUtil::getFloat( int iRow, int iCol, const char* csvFilePath ) {
	const char* chData = get(iRow, iCol, csvFilePath);

	return atof(chData);
}

const int CsvUtil::findValueInWithLine( const char* chValue, int iValueCol, const char* csvFilePath ) {
    CCSize csvSize = getFileRowColNum(csvFilePath);

    int iLine = -1;
    for(int i = 0; i < csvSize.width; i++) {
        const char* ID = get(i, iValueCol, csvFilePath);
        CCString* IDStr = CCString::createWithFormat(ID);
        if(IDStr->m_sString.compare(chValue) == 0) {
            iLine = i;
            break;
        }
    }

    return iLine;
}