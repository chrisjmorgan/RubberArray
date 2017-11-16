//Chris Morgan
//Cisp 400 Tues/Wed
//Fox
//
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
  RubberArray& operator(const RubberArray&);

  void append(const T& item);
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


