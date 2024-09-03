#pragma once
#include<iostream>
using namespace std;

template <class T>
class Edge
{
   public:
      virtual ~Edge() {};
      virtual int vertex1() const = 0;
      virtual int vertex2() const = 0;
      virtual T weight() const = 0;
};

