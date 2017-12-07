//Chris Morgan
//Cisp 400 Tues/Wed
//Fox
//
#ifndef RUBBER_ARRAY_H
#define RUBBER_ARRAY_H
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
template <class T>
class RubberArray
{
	T* _Array;
	unsigned _len; //Number of items in array
	unsigned _alloc; // Number of allocated spaces
	int _Vindex; //Virtual index of first item

public:
	RubberArray(int Vindex = 0);

	RubberArray(const T*, unsigned s, int Vindex = 0);

	RubberArray(const RubberArray<T>& V);

	~RubberArray();

	RubberArray<T>& operator=(const RubberArray&);

	template<typename OS>
		friend ostream& operator<< ( ostream&, const RubberArray<OS>& R );

	template <typename OS>
		friend ostream& operator<< ( ostream&, const RubberArray<OS>* );

	T& operator[] ( int Vindex );

	const T& operator[] ( int Vindex ) const;

	RubberArray operator( ) ( int Vfirst, int Vlast ) const;

	void append(const T& item);

	void append ( const RubberArray<T>& );

	unsigned length ( ) const;

	void add ( int Vindex, const T& );

	void add ( const T& );

	void remove ( );

	void remove ( int Vindex );

	void remove ( int Vfirst, int Vlast );

  void write (ofstream& of) const;

	void read (ifstream& ifs);

};
#endif

	template <class T>
	RubberArray<T>::RubberArray(int Vindex)
:_Vindex(Vindex)
{
	_Array = NULL;
	_len = 0;
	_alloc = 0;
}

	template <class T>
	RubberArray<T>::RubberArray(const T* A, unsigned s, int Vindex)
: _Array(NULL), _len(0), _alloc(0), _Vindex(Vindex)
{
	for (unsigned i = 0; i<s; ++i)
		append(A[i]);
}

	template <class T>
	RubberArray<T>::RubberArray(const RubberArray<T>& V)
:_Array(NULL), _len(0), _alloc(0), _Vindex(V._Vindex)
{
	for (unsigned i = 0; i<V._len; ++i)
	{
		append(V._Array[i]);
	}
}

	template <class T>
RubberArray<T>::~RubberArray()
{
	delete [] _Array;
	_Array = NULL;
	_len = 0;
	_alloc = 0;
}

	template <class T>
RubberArray<T>& RubberArray<T>::operator=(const RubberArray<T>& R)
{
	if (this != &R)
	{
		if (_len != 0)
			delete [] _Array;
		_Array = NULL;
		_len = 0;
		_alloc = 0;
		_Vindex = R._Vindex;

		for (unsigned i = 0; i < R._len; ++i)
		{
			append(R._Array[i]);
		}

	}
	return *this;
}

	template <typename OS>
ostream& operator<< ( ostream& os, const RubberArray<OS>& R )
{

	cout << "Number of items in array: " << R._len << endl;
	cout << "Number of allocated spaces:" << R._alloc << endl;
	cout << "Virtual index of first item:" << R._Vindex << endl;

	if (R._len != 0)
	{
		os << R._Array[0];
		for (unsigned i = 1; i < R._len; ++i)
			os << ", " << R._Array[i];
	}
	return os;
}

	template <class OS>
ostream& operator<< (ostream& os, const RubberArray<OS>* R)
{
	os << (*R);
	return os;
}

	template <class T>
T& RubberArray<T>::operator[] (int Vindex)
{
	int Aindex = Vindex - _Vindex;

	if (Aindex < 0 || Aindex >= _len)
	{
		if (Aindex < 0)
			throw unsigned(100 + _Vindex);
		else throw unsigned(100 + _Vindex + _len);
	}

	return _Array[Aindex];
}

template <class T>
const T& RubberArray<T>::operator[] (int Vindex) const
{
	int Aindex = Vindex - _Vindex;

	if (Aindex < 0 || Aindex >= _len)
	{
		if (Aindex < 0)
			throw unsigned(200 + _Vindex);
		else throw unsigned(200 + _Vindex + _len);
	}

	return _Array[Aindex];

}

template <class T>
RubberArray<T> RubberArray<T>::operator()(int Vfirst, int Vlast) const
{
	int tmpFirst = Vfirst - _Vindex;
	int tmpLast = Vlast - _Vindex;
	int newSize = (tmpLast - tmpFirst) - 1;

	if (tmpFirst < 0)
	{
		throw unsigned(999); // THROW 999 IF VFIRST IS OUT OF BOUNDS
	} else if (tmpLast<0)
	{
		throw unsigned(998); // THROW 998 IF VLAST IS OUT OF BOUNDS 
	}

	if ((Vlast - Vfirst) > _len)
		throw unsigned(997);

	RubberArray<T> tmpVec;
	for (unsigned i = 0; i < newSize; ++i)
	{
		tmpVec.append(_Array[tmpFirst + i]);
	}

	return tmpVec;
}

	template <class T>
void RubberArray<T>::append(const T& item)
{
	if (_len >= _alloc)
	{
		_alloc = _alloc *2+1;
		T* temp = new T[_alloc];
		for (unsigned i = 0; i<_len; ++i)
			temp[i] = _Array[i];
		if (_len != 0)
			delete [] _Array;
		_Array = temp;
	}
	_Array[_len++] = item;

}

	template <class T>
void RubberArray<T>::append(const RubberArray<T>& V)
{
	for (unsigned i = 0; i<V._len; ++i)
		append(V._Array[i]);
}

template <class T>
unsigned RubberArray<T>::length() const
{
	return _len;
}

	template <class T>
void RubberArray<T>::add(int Vindex, const T& V)
{
	int Aindex = Vindex - _Vindex;
	if (Aindex < 0 || Aindex >= _len)
	{
		if (Aindex < 0)
			throw unsigned(100 + _Vindex);
		else throw unsigned(100 + _Vindex + _len);
	}

	_Array[Aindex] = V;
}

	template <class T>
void RubberArray<T>::add(const T& V)
{
	add (_Vindex,V);
}

	template <class T>
void RubberArray<T>::remove()
{
	remove(_Vindex +_len -1);
}  

	template <class T>
void RubberArray<T>::remove(int Vindex)
{
	int Aindex = Vindex - _Vindex;

	if (Aindex < 0 || Aindex >= _len)
	{
		throw unsigned(200);
	}

	RubberArray<T> tmp(_Vindex);
	for (unsigned i = 0; i < _len; ++i)
	{
		if (i != Aindex)
			tmp.append(_Array[i]);
	}
	*this = tmp;
}

	template <class T>
void RubberArray<T>::remove(int Vfirst, int Vlast)
{
	if (Vfirst >= _Vindex && Vlast <= _len + _Vindex)
	{
		for (int i = Vfirst; i < Vlast; ++i)
			remove(Vfirst);

	} else throw unsigned(300);
}


template <class T>
void RubberArray<T>::write (ofstream& outf) const
{
	if (outf)
	{
	outf.write(reinterpret_cast<const char*>(&_Vindex), sizeof(_Vindex) );
	outf.write(reinterpret_cast<const char*>(&_len), sizeof(_len) );
	outf.write(reinterpret_cast<const char*>(_Array),_len*sizeof(T) );
	}
}

template <class T>
void RubberArray<T>::read (ifstream& inf)
{
	if (inf)
	{
	inf.read(reinterpret_cast<char*>(&_Vindex), sizeof(_Vindex) );
	inf.read(reinterpret_cast<char*>(&_len), sizeof(_len) );
	T* temp;

	temp = new T[_len];

	inf.read(reinterpret_cast<char*>(temp), _len*sizeof(T));
	RubberArray<T> RA(temp,_len,_Vindex);
 *this = RA;
 delete [] temp;
}

}


