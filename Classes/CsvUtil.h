
#ifndef __CSV_H__
#define __CSV_H__

#include "cocos2d.h"

using namespace cocos2d;

class CsvUtil : public CCObject {
public:
    /* ��ȡ���߶��� */
    static CsvUtil* sharedCsvUtil();

    bool init();

    /* ���������ļ� */
    void loadFile(const char* sPath);

    /* �ͷ������ļ� */
    void releaseFile(const char* sPath);

    /* ��ȡĳ��ĳ�е�ֵ */
    const char* get(int iRow, int iCol, const char* csvFilePath);

	/* ��ȡĳ��ĳ�е�ֵ������ת��Ϊ���� */
	const int getInt(int iRow, int iCol, const char* csvFilePath);

	/* ��ȡĳ��ĳ�е�ֵ������ת��Ϊ������ */
	const float getFloat(int iRow, int iCol, const char* csvFilePath);

    /* ��ȡ�����ļ����ݵ��к������� */
    const CCSize getFileRowColNum(const char* csvFilePath);

    /* ����ĳ���е�ֵ�����Ҹ�ֵ���ڵ��� */
    const int findValueInWithLine(const char* chValue, int iValueCol, const char* csvFilePath);
private:
    /* ���߶��� */
    static CsvUtil* mCsvUtil;

    /* 
        ���mCsvStrList-filePath���ֵ䡣
        ����дע�ͱȽϺü��䣺CCDictionary<CCArray<CCArray>, const char*>
    */
    CCDictionary* mCsvDict;
};

#endif