/*
    �ļ�����    StringUtil.h
    �衡����    �ַ���������
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)

    �������ڣ�   2012.11.22
*/
#ifndef __STRING_UTIL_H__
#define __STRING_UTIL_H__

#include "cocos2d.h"

using namespace cocos2d;

class StringUtil : public CCObject {
public:
    static StringUtil* sharedStrUtil();

    bool init();

    /** �÷ָ����ָ��ַ����������ŵ�һ���б��У��б��еĶ���ΪCCString */
    CCArray* split(const char* srcStr, const char* sSep);

private:
    static StringUtil* mStringUtil;
};

#endif