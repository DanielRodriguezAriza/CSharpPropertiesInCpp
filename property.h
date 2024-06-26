#ifndef DRA_PROPERTY_H
#define DRA_PROPERTY_H

template<typename T>
void DefaultPropertySetter(T &value, T newValue)
{
    value = newValue;
}

template<typename T, void(*Setter)(T &value, T newValue) = DefaultPropertySetter<T>>
class Property
{
public:
    Property()
    :value{}
    {}
    
    Property(T const &val)
    :value{val}
    {}
    
    T const &operator=(T const &val)
    {
        Setter(value, val);
        return value;
    }
    
    operator T() const
    {
        return value;
    }
    
private:
    T value;
};

#endif
