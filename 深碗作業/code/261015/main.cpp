#include <string>
#include <iostream>
#include <vector>
using namespace std;
class GameCharacter
{
public:
	string name;
	int hp;
	int level;
	// Constructor
	GameCharacter(string n, int h, int l)
	{
		// 將 n 存入 name
		// 將 h 存入 hp
		// 將 l 存入 level
		name = n;
		hp = h;
		level = l;
	}
	// 受到傷害
	void damage(int value)
	{
		// 1. hp 扣掉 value
		hp -= value;
	}
	// 回復生命值
	void heal(int value)
	{
		// 1. hp 加上 value
		// 2. 如果 hp 大於 100 ，將 hp 設為 100
		hp += value;
		if (hp > 100)hp = 100;
	}
	// 升級
	void levelUp()
	{
		// 1. level 加 1
		// 2. hp 回復成 100
		level++;
		hp = 100;
	}
	// 顯示角色資料
	void show()
	{
		// 顯示 name 、 hp 、 level
		cout <<"----------\n" << "名稱:" << name << " \n血量:" << hp << " \n等級:" << level <<"\n----------" << endl;
	}

};

int main() {
	/*GameCharacter p1("Tom", 100, 1);
	GameCharacter p2("Amy", 80, 2);
	p1.damage(30);
	p1.heal(10);
	p2.damage(100);
	p2.heal(20);
	p1.levelUp();
	p1.show();
	p2.show();
	return 0;*/

	int characterNum;
	string cName;
	int health=100;
	int level = 1;
	cout << "請輸入角色人數:";
	
	cin >> characterNum;
	cout << endl;
	vector<GameCharacter> player;
	for (int i = 0; i < characterNum; i++) {
		cout << "請輸入角色" << i + 1 << "名稱:";
		cin >> cName;
		cout << endl;
		cout << "請輸入角色" << i + 1 << "血量:";
		cin >> health;
		cout << endl;
		cout << "請輸入角色" << i + 1 << "等級:";
		cin >> level;
		cout << endl;
		player.push_back(GameCharacter(cName, health, level));
	}
	for (int i = 0; i < characterNum; i++) {
		player[i].show();
	}
	int menu;
	int arrow;
	int temp;
	while (true) {
		cout << "選單\n1.扣血\n2.回血\n3.升級\n4.show角色資料\n5.show全部角色\n";
		cin >> menu;
		switch (menu) {
		case 1:
			cout << "請選擇角色:";
			cin >> arrow;
			arrow--;
			cout << endl;
			cout << "請選輸入傷害:";
			cin >> temp;
			cout << endl;
			player[arrow].damage(temp);
			player[arrow].show();
			break;
		case 2:
			cout << "請選擇角色:";
			cin >> arrow;
			arrow--;
			cout << endl;
			cout << "請選輸入治療量:";
			cin >> temp;
			cout << endl;
			player[arrow].heal(temp);
			player[arrow].show();
			break;
		case 3:
			cout << "請選擇角色:";
			cin >> arrow;
			arrow--;
			cout << endl;
			
			
			player[arrow].levelUp();
			player[arrow].show();
			break;
		case 4:
			cout << "請選擇角色:";
			cin >> arrow;
			arrow--;
			cout << endl;


			player[arrow].show();
			break;
		case 5:
			for (int i = 0; i < characterNum; i++) {
				player[i].show();
			}
			break;
		default:
			break;
		}
		
	}



}

