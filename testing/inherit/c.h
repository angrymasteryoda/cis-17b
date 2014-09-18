#ifndef C_H
#define C_H

class C : public B
{
public:
    C( int x, int y ) : B( x, y ){}
    void ccc(){
        cout << something << "\\" << other << endl;
    }
};

#endif // C_H
