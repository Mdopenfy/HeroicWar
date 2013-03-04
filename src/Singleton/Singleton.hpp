/////////////////////////////////////////////////////////////////////////////
//
// Singleton - modèle Singleton applicable à n'importe quelle classe.
//
/////////////////////////////////////////////////////////////////////////////

#include <cstddef>

template <typename T>
class Singleton
{
    protected:

        Singleton () { }
        ~Singleton ()  { }

    public:

        static T *getInstance ()
        {
            if (NULL == _singleton)
                _singleton = new T;
             
        return (static_cast<T*> (_singleton));
        }

        static void kill ()

        {
            if (NULL != _singleton)
            {
                delete _singleton;
                _singleton = NULL;
            }   
        }
        
        static bool exist()
        {
            return (_singleton != NULL);
        }

    private:
        
        static T *_singleton;
};
 
template <typename T>
T *Singleton<T>::_singleton = NULL;
