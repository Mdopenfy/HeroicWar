/////////////////////////////////////////////////////////////////////////////
//
// UniqueObject - une classe ? instance unique.
//
/////////////////////////////////////////////////////////////////////////////

#include "Singleton.hpp"

class UniqueObject : public Singleton<UniqueObject>
{
    friend class Singleton<UniqueObject>;

    private:
        UniqueObject () : _value (0) { }
        ~UniqueObject () { }
                              
    public:
        void setValue (int val) { _value = val; }
        int getValue () { return _value; }
                                                                               
    private:
        int _value;
};
