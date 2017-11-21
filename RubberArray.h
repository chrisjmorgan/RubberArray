//Chris Morgan
//Cisp 400 Tues/Wed
//Fox
//
#include <iostream>
#include <fstream>
#include <cstd>
#ifndef RUBBER_ARRAY_H
#define RUBBER_ARRAY_H

template <class T>
class RubberArray
{
  T* _Array;
  unsigned _len; //Number of items in array
  unsigned _alloc; // Number of allocated spaces
  int _vindex; //Virtual index of first item

  public:
  RubberArray(int = 0);

  RubberArray(const T*, unsigned s, int Vindex);

  ~RubberArray();

  RubberArray<T>& operator=(const RubberArray&);

  template<typename OS>
  friend ostream& operator<< ( ostream&, const RubberArray<OS>& );

  template <typename OS>
  friend ostream& operator<< ( ostream&, const RubberArray<OS>* );

  T& operator[] ( int Vindex );

  const T& operator[] ( int Vindex ) const;

  RubberArray operator( ) ( int Vfirst, int Vlast )const;

  void append(const T& item);

  void append ( const RubberArray& );

  unsigned length ( ) const;

  void add ( int Vindex, const T& );

  void add ( const T& );

  void remove ( );

  void remove ( int Vindex );

  void remove ( int Vfirst, int Vlast );

};
#endif

  template <class T>
RubberArray<T>::RubberArray(int vindex)
  :_vindex(vindex)
{
  _Array = NULL;
  _len = 0;
  _alloc = 0;
}

  template <class T>
RubberArray<T>& RubberArray<T>::operator=(const RubberArray<T>& R)
{
  if (this != &R)

}

//template <typename OS>
//friend ostream& operator<< ( ostream&, const RubberArray<OS>& );

RubberArray<T>::RubberArray(const T* A, unsigned s, int Vindex)
  : _Array(NULL), _len(0), _alloc(0), _vindex(Vindex)
{
  for (unsigned i = 0; i<s; ++i)
    append(A[i]);
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
void RubberArray<T>::append(const T& item)
{
  if (_len >= _alloc)
  {
    _alloc = _alloc *2+1;
  }
  ++_len;
  cout << item << "" << _len

}
template <class T>
void RubberArray<T>::write (ofstream& inf) const
{
  if (inf)
  {
    outf.write(reinterpret_cast<const char*>(&_vindex), sizeof(_vindex) );
    outf.write(reinterpret_cast<const char*>(&_len), sizeof(_lin) );
    outf.write(reinterpret_cast<const char*>(_Array),_len*sizeof(T) );
  }
}

template <class T>
void RubberArray<T>::read (ofstream& inf)
{
  if (inf)
  {
    inf.read(reinterpret_cast<const char*>(&_vindex), sizeof(_vindex) );
    inf.read(reinterpret_cast<const char*>(&_len), sizeof(_lin) );
     T* temp = new T[_len];
    inf.read(reinterpret_cast<char*>(temp), _len*sizeof(T));
    RubberArray<T> RA(temp,_len,_vindex);
    *this = RA;
    delete [] temp;
  }

}
