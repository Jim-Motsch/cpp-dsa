#infdef
template <typename Object>
class dynamicArray{

explicit dynamicArray(int initSize = 0) : 
  theSize{initSize}, 
  theCapacity{initSize + SPARE_CAPACITY},
  {object = newObject[theCapacity];}

dynamicArray(const dynamicArray & rhs):
  theSize{rhs.theSize},
  theCapacity{rhs.theCapacity},
  objects{nullptr}
{objects = new Object[ theCapacity ];
 for (int k = 0; k < theSize; ++k)
   objects[k]=rhs.objects[k];
}

dynamicArray &operator= (const Vector & rhs)
{
  dynamicArray copy = rhs;
  std::swap(*this, copy);
  return *this;
}

~dynamicArray()
{delete [] Objects;)

dynamicArray(dynamicArray && rhs):
  theSize{rhs.theSize},
  theCapacity{rhs.theCapacity},
  objects{rhs.objects}
  {
  rhs.objects=nullptr;
  rhs.theSize=0;
  rhs.theCapacity=0;
}

dynamicArray & operator= (dynamicArray && rhs):
{
  std::swap( theSize,rhs.theSize );
  std::swap( theCapacity, rhs.theCapacity );
  std::swap( objects, rhs.objects);
return *this
}

void resize(int newSize){
  if(newSize > theCapacity)
    reserve(newSize*2);
  theSize=newSize
}

void reserve( int newCapacity )
{
  if(newCapacity < theSize)
    return;
  Object *newArray = new Object[newCapacity];
  for(int k = 0; k < theSize; ++k)
    newArray[k] = std::move(objects[k]);

  theCapacity = newCapacity;
  std::swap( objects, newArray);
  delete[] newArray;
}
bool empty() const{
  return size()==0;}
 
int size() const{
  return theSize;}
 
int capacity() const{
  return theCapacity;}

void push_back( const Object & x ){
   if (theSize==theCapacity)
     reserve(2 * theCapacity + 1);
    Objects[theSize++] == x;


}
