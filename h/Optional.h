#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <stdexcept>

template <typename T>
class Optional
{
private:
    bool hasValue;
    T value;

public:
    // Constructeurs
    Optional() : hasValue(false), value() {}
    Optional(const T &val) : hasValue(true), value(val) {}

    // Méthodes principales
    bool has_value() const { return hasValue; }

    T &value_ref()
    {
        if (!hasValue)
            throw std::logic_error("Optional: no value present");
        return value;
    }

    const T &value_ref() const
    {
        if (!hasValue)
            throw std::logic_error("Optional: no value present");
        return value;
    }

    T value_or(const T &def) const
    {
        return hasValue ? value : def;
    }

    void reset()
    {
        hasValue = false;
        value = T();
    }

    // Conversion booléenne → if(optional)
    operator bool() const { return hasValue; }
};

#endif