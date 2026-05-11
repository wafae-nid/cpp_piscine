

template<typename T>
Array<T>::Array(): array(NULL), length(0)
{

}

template<typename T>
Array<T>::Array(unsigned int n)
{
    length = n;
    array = new T[n];
    for(unsigned int i = 0; i<n ;i++)
    {
        array[i] = T();
    }
}

template<typename T>
Array<T>::Array(const Array& copy)
{
    length = copy.length;
    array = new T[length];
    for(unsigned int i = 0; i <length ; i++)
    {
        array[i]= copy.array[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if(this != &copy)
    {
        delete[]array;
        length = copy.length;
        array = new T[length];
        for(unsigned int i = 0; i <length ; i++)
        {
            array[i]= copy.array[i];
        }
    }
    return(*this);
}

template<typename T>

Array<T>::~Array()
{
    delete[]array;
}

template<typename T>
const char* Array<T>::IndexIsOutOfBounds::what()const throw()
{
    return "index is out of bounds";
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if(index >= length)
        throw(IndexIsOutOfBounds());
    return(array[index]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int index)const
{
    if(index >= length)
        throw(IndexIsOutOfBounds());
    return(array[index]);
}
template<typename T>
unsigned int Array<T>::size(void)const
{
    return(length);
}
