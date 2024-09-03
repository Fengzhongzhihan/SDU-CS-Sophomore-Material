#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    string streetAddress;
    string city;
    string postalCode;

public:
    // ���캯��
    Employee(string name, string streetAddress, string city, string postalCode) : 
        name(name), streetAddress(streetAddress), city(city), postalCode(postalCode) {}

    // ���������޸�����
    void change_name(string new_name) {
        name = new_name;
    }

    // ����������ʾ��Ա��Ϣ
    void display() {
        cout << "������" << name << endl;
        cout << "�ֵ���ַ��" << streetAddress << endl;
        cout << "���У�" << city << endl;
        cout << "�ʱࣺ" << postalCode << endl;
    }
};

int main() {
    const int NUM_EMPLOYEES = 2;
    Employee employees[NUM_EMPLOYEES] = {
        Employee("Լ������", "123����", "�������", "12345"),
        Employee("��ʷ��˹", "456������", "����", "54321"),
    };

    // ��ʾÿ����Ա����Ϣ
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "��Ա #" << i + 1 << "��" << endl;
        employees[i].display();
        cout << endl;
    }

    // �޸Ĺ�Ա������
    employees[0].change_name("Լ����ʷ��˹");
    cout << "�޸ĺ��������" << endl;
    employees[0].display();
    return 0;
}
