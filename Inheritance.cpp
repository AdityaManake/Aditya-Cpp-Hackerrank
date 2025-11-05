#include<iostream>
using namespace std;
class TypeOfTriangle
{
    public:
    void Isos()
    {
    cout<<"I am an isosceles triangle"<<endl;
    }
};
class Sides:public TypeOfTriangle
{
    public:
    void Side()
    {
     Isos();
    cout<<"In an isosceles triangle two sides are equal"<<endl;
    cout<<"I am a triangle";
    }
};
int main()
{
    Sides obj;
    obj.Side();
    return 0;
}
