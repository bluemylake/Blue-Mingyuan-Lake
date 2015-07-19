#include "StringUtil.h"

StringUtil* StringUtil::mStringUtil = NULL;

StringUtil* StringUtil::sharedStrUtil(){
    if(mStringUtil == NULL) {
        mStringUtil = new StringUtil();
        if(mStringUtil && mStringUtil->init()) {
            mStringUtil->autorelease();
        }
        else {
            CC_SAFE_DELETE(mStringUtil);
            mStringUtil = NULL;
        }
    }

    return mStringUtil;
}

bool StringUtil::init(){

    return true;
}

CCArray* StringUtil::split( const char* srcStr, const char* sSep ){
    CCArray* stringList = CCArray::create();

    int size = strlen(srcStr);

    /* ������ת��ΪCocos2d-x�ַ������� */
    CCString* str = CCString::create(srcStr);

    int startIndex = 0;
    int endIndex = 0;
    endIndex = str->m_sString.find(sSep);

    CCString* spliStr = NULL;

    /* ���ݷָ�������ַ���������ӵ��б��� */
    while(endIndex > 0) {
        spliStr = CCString::create("");

        /* ��ȡ�ַ��� */
        spliStr->m_sString = str->m_sString.substr(startIndex, endIndex);

        /* ����ַ������б� */
        stringList->addObject(spliStr);

        /* ��ȡʣ�µ��ַ��� */
        str->m_sString = str->m_sString.substr(endIndex + 1, size);

		/* ������һ���ָ��������±� */
        endIndex = str->m_sString.find(sSep);
    }

    /* ʣ�µ��ַ���Ҳ��ӽ��б� */
    if(str->m_sString.compare("") != 0) {
        stringList->addObject(CCString::create(str->m_sString));
    }

    return stringList;
}
