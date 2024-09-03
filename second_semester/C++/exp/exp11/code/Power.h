template <unsigned N>
struct Power { //类模板
  template <class T>
  static T value(T x) {//函数模板
    return x* Power<N-1>::value(x);
  }
};

//可以用Power<4>::value(x)来计算x的4次方
template <>
struct Power<1> { //特化 N=1
  template <class T>
  static T value(T x) {
    return x;
  }
};

//可以用power<4>(x)来计算x的4次方
template <unsigned N, class T>
inline T power(T v){//辅助函数模板
	return Power<N>::value(v);
}

