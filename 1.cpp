#include <iostream>
using namespace std;

class Container {
    int size;
public:
    float* p;
    Container(int s) : size(s) {}
    const int& getsize() { return size; }
};

class Vector : public Container {
    int call_num;
public:
    explicit Vector(int l) : Container(100), call_num(0) {
        p = new float();
    }
    int len;
    int& getlen() {
        call_num++;
        return len;
    }
    ~Vector() = default;
};

int main() {
    Container c1(100);
    Vector v1(100);
    Container& r1 = v1;
    Container c2(100);
    //c2.getsize() = 20;
    cout << c2.getsize() << endl;
    Vector v2(100);
    v2.getlen() = 40;
    cout << v2.getlen() << endl;

    return 0;
}
