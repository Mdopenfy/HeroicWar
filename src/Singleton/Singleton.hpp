/////////////////////////////////////////////////////////////////////////////
//
// Singleton - modèle Singleton applicable à n'importe quelle classe.
//
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

template <typename T>
class Singleton
{
    protected:

        Singleton () { }
        ~Singleton ()  { std::cout << "destroying singleton." << std::endl; }

    public:

        static T *getInstance ()
        {
            if (NULL == _singleton)
            {
                std::cout << "creating singleton." << std::endl;
                _singleton = new T;
            }
            else
            {
                std::cout << "singleton already created!" << std::endl;
            }
             
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
        
    private:
        
        static T *_singleton;
};
 
template <typename T>
T *Singleton<T>::_singleton = NULL;
