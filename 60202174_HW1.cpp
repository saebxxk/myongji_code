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

		//필요한 변수 선언
		cout << "이름과 전화 번호를 입력해 주세요" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "사람" << i + 1 << ">>";
			cin >> name >> tel;
			p[i].set(name,tel);//이름과 전화 번호를 입력 받아 객체 배열 p에 값을 넣기
		}
	}

	void show() {
		cout << "모든 사람의 이름은 ";
		for (int i = 0; i < 3; i++) {
			cout << p[i].getName() << ' ';//사람의 이름 출력
		}
		cout << endl;

	}

	void search() {
		string name;//검색할 이름 입력 받기
		cout << "전화번호 검색합니다. 이름을 입력하세요>>";
		cin >> name;

		for (int i = 0; i < 3; i++) {
			if (name == p[i].getName()) {//입력값과 객체 p의 이름값 비교(스트링 비교)
				cout << "전화번호는 " << p[i].getTel() << endl; //검색된 전화번호 출력
				return;
			}
		}
		cout << "없는 사람입니다" << endl;

	}
	~PersonManager() {
		delete[]p;//p메모리 반환
	}
};


int main() {
	PersonManager manager(3);
	manager.show();
	manager.search();

}