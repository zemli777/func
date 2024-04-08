#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
class wood
{
protected:
    struct point {
        string data; //информационное поле 
        point* left; //адрес левого поддерева
        point* right; //адрес правого поддерева
        point* parent; //адрес родителя (предка)
    };

   
public:
    wood() {};
    ~wood() {};
    point* First1; // корень
    point* First2;
    point* First3;
    point Pointer;
   virtual double value(point* First, int i) =0;
    double FindExtremMax(point* point, int i, int j);
    double FindExtremMin(point* point, int i, int j);

};
class wood1 : public wood {
public:
    double value(point* First, int i) override;
    void TransformToWood(string s);
    void PrintWood();

};
class wood2 : public wood {
public:
    double value(point* First, int i) override;
    void TransformToWood(string s);
    void PrintWood();
};
class wood3 : public wood {
public:
    double value(point* First, int i) override;
    void TransformToWood(string s);
    void PrintWood();
};
