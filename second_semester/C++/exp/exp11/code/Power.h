template <unsigned N>
struct Power { //��ģ��
  template <class T>
  static T value(T x) {//����ģ��
    return x* Power<N-1>::value(x);
  }
};

//������Power<4>::value(x)������x��4�η�
template <>
struct Power<1> { //�ػ� N=1
  template <class T>
  static T value(T x) {
    return x;
  }
};

//������power<4>(x)������x��4�η�
template <unsigned N, class T>
inline T power(T v){//��������ģ��
	return Power<N>::value(v);
}

