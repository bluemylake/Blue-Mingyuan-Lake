/*
    �ļ�����    FileLoadUtil.h
    �衡����    �ı��ļ���ȡ����
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)

    �������ڣ�   2012.11.22
*/
#ifndef __FILE_LOAD_UTIL_H__
#define __FILE_LOAD_UTIL_H__

#include "cocos2d.h"

using namespace cocos2d;

class FileLoadUtil : public CCObject {
public:
    static FileLoadUtil* sharedFileLoadUtil();

    bool init();

    /* ��ȡ�ļ�ÿһ�е����ݣ����д�ŵ��б��� */
    CCArray* getDataLines(const char* sFilePath);

private:
    static FileLoadUtil* mFileLoadUtil;
};

#endif
