#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_ 
#include <iostream>

template <typename T>
class Singleton
{
public:
	static T* instance();
	void release();
protected:
	static T* _instance;
};

template<typename T>
T* Singleton<T>::_instance=NULL;

template<typename T>
T* Singleton<T>::instance()
{
	if(!_instance)
		_instance=new T;
	return _instance;
}

template<typename T>
void Singleton<T>::release()
{
	if(!_instance)
		return;
	delete _instance;
	_instance=NULL;
}

#endif
