/* Implement the shared Pointer concept */


#include <iostream>

using namespace std;

template <class T>
class sharedPtr {
    public:
        int * _refCnt;
        T * ptr;
        
        sharedPtr(T * ptr) {
            this->ptr = ptr;
            _refCnt = new int;
            *_refCnt = 1;
        }
        
        /*Copy */
        sharedPtr(sharedPtr &s)
        {
            cout << "Copy COnstructor :" << endl;
            cout << "s._refCnt = " << s._refCnt << endl;
            cout << "*s._refCnt = " << *s._refCnt << endl;
            
            (*s._refCnt)++;
            this->_refCnt = s._refCnt;
            this->ptr = s.ptr;
            cout << "s._refCnt = " << s._refCnt << endl;
            cout << "*s._refCnt = " << *s._refCnt << endl;
            
            cout << "*this->_refCnt = " << this->_refCnt << endl;
            cout << "*this->_refCnt = " << *this->_refCnt << endl;
            
        }
        
        ~sharedPtr() {
            cout << "Destructor called & _refCnt is " << *_refCnt << endl;
            
            if (*_refCnt == 1)
                delete ptr;
                
            (*_refCnt)--;
        }
};

int main() {
    int *N = new int;
    int *M = new int;
    sharedPtr<int> s1(N);
    sharedPtr<int> s2(M);
    cout << "s2 refcnt=" << *s2._refCnt << endl;
        
    sharedPtr<int> s3(s2);
    
    cout << "s1 refcnt=" << *s1._refCnt << endl;
    cout << "s2 refcnt=" << *s2._refCnt << endl;
    cout << "s3 refcnt=" << *s3._refCnt << endl;
    
    
    return 0;
}
