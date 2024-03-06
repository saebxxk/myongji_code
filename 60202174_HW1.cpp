#include<iostream>
using namespace std;
class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};
Person::Person() {
	this->name = "";
	this->tel = "";
}
void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;

}




class PersonManager {
public:
	Person* p;
	int size;

	PersonManager(int n) {
		p = new Person[n];
		string name; string tel;
		size = n;

		//�ʿ��� ���� ����
		cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "���" << i + 1 << ">>";
			cin >> name >> tel;
			p[i].set(name,tel);//�̸��� ��ȭ ��ȣ�� �Է� �޾� ��ü �迭 p�� ���� �ֱ�
		}
	}

	void show() {
		cout << "��� ����� �̸��� ";
		for (int i = 0; i < 3; i++) {
			cout << p[i].getName() << ' ';//����� �̸� ���
		}
		cout << endl;

	}

	void search() {
		string name;//�˻��� �̸� �Է� �ޱ�
		cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
		cin >> name;

		for (int i = 0; i < 3; i++) {
			if (name == p[i].getName()) {//�Է°��� ��ü p�� �̸��� ��(��Ʈ�� ��)
				cout << "��ȭ��ȣ�� " << p[i].getTel() << endl; //�˻��� ��ȭ��ȣ ���
				return;
			}
		}
		cout << "���� ����Դϴ�" << endl;

	}
	~PersonManager() {
		delete[]p;//p�޸� ��ȯ
	}
};


int main() {
	PersonManager manager(3);
	manager.show();
	manager.search();

}