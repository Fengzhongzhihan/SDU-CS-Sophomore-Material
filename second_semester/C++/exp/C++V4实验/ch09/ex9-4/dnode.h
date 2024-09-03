//dnode.h
#ifndef DOUBLY_LINKED_NODE_CLASS
#define DOUBLY_LINKED_NODE_CLASS

template <class T>
class DNode
{
    private:
		// circular links to the left and right
        DNode<T> *left;  //��ָ��
        DNode<T> *right;  //��ָ��
    public: 
		T data;  //�������
        
		// ���캯��
        DNode(void); 
        DNode (const T& item);
        
        
        // �����޸��㷨
        void insertRight(DNode<T> *p);
        void insertLeft(DNode<T> *p);
        DNode<T> *deleteNode(void);
        
        
        // ��ȡ�����Ҳ����ڽ��ĵ�ַ
        DNode<T> *nextNodeRight(void) const;
        DNode<T> *nextNodeLeft(void) const;
};

// ���캯������һ���ս�㣬����ʼ�����ݳ�Ա����������ͷ���
template <class T>
DNode<T>::DNode(void)
{
	// ��ʼ����㣬ʹָ֮������
    left = right = this;
}

// ���캯��������һ���ս�㲢��ʼ�����ݳ�Ա
template <class T>
DNode<T>::DNode(const T& item)
{
	// ʹ���ָ��ָ��������ʼ�����ݳ�Ա
    left = right = this;
    data = item;
}

// �ڵ�ǰ�����Ҳ����һ�����p
template <class T>
void DNode<T>::insertRight(DNode<T> *p)
{
	// ��p���ҽ������
    p->right = right;
	right->left = p;
	
	// ����ǰ������ӵ�p�������
    p->left = this;
    right = p;
}

//�ڵ�ǰ����������һ�����p
template <class T>
void DNode<T>::insertLeft(DNode<T> *p)
{
	// ��p����������
    p->left = left;
    left->right = p;
    
	//����ǰ������ӵ�p�����Ҳ�
    p->right = this;
    left = p;
}

// �Ͽ���ǰ�������������ӣ������ص�ǰ����ַ
template <class T>
DNode<T> *DNode<T>::deleteNode(void)
{
	// ʹ��ǰ������������ӵ���ǰ�����Ҳ���
    left->right = right;
    
	// ʹ��ǰ�����Ҳ������ӵ���ǰ���������
    right->left = left;
    
    // ���ص�ǰ����ַ
    return this;
}

// ����ָ���ҽ���ָ��
template <class T>
DNode<T> *DNode<T>::nextNodeRight(void) const
{
    return right;
}

// ����ָ�������ָ��
template <class T>
DNode<T> *DNode<T>::nextNodeLeft(void) const
{
    return left;
}

#endif	// DOUBLY_LINKED_NODE_CLASS
