#ifndef ZOO_H
#define ZOO_H
#include <vector>
#include <random>
using namespace std;

class Money {
public:
	Money(double dollars = 0.0);
	~Money();
	void add(double dollars);
	double getAmount() const;
	Money operator+(const Money& other) const;
	Money operator-(const Money& other) const;
	void addamount(double);
private:
	double amount = 0;
};

class AnimalFood {
public:
	enum Type { PEANUTS, CARROTS, BANANAS };
	AnimalFood(Type type = PEANUTS, int amount = 0);
	vector<int> get_amount_of_food() const;
protected:
	Type type = PEANUTS;
	vector<int>amount_of_food = { 10000,7000,4000 };
};

class AnimalEnclosure {
public:
	AnimalEnclosure();
	bool isOpen() const;
	void open();
	void close();
	void opstate_judge_set(int);
	//围栏关闭的那一天
	int time;
	int opstate_judge_get();
	void addDirt(int amount);
	int getDirt() const;
	void clean();
	void add_open_days();
	int get_open_days();
private:
	bool openStatus;
	int dirtLevel;
	//开放的天数
	int openDays;
};

class Animal {
public:
	Animal();
	virtual ~Animal() {}//看课本
	int getWeight() const;
	int getAmountEaten()const;
	virtual void feed(double) = 0;//纯虚函数->抽象类
	virtual void makeNoise() const = 0;//纯虚函数->抽象类
private:
	int weight = 0;
	int amountEaten = 0;
};

class Elephant : public Animal {
public:
	Elephant(int weight = 0, int amountEaten = 0, int trunkLength = 0);//如果在这里初始化默认参数，就不需要再声明和定义一个无参数的默认构造函数
	void feed(double);
	void makeNoise() const;
	int getAmountEaten()const;
	void setAmountEaten();
private:
	int trunkLength = 0;
	int weight = 0;
	double amountEaten = 0;
};

class Giraffe : public Animal {
public:
	Giraffe(int weight = 0, int amountEaten = 0, int neckLength = 0);
	void feed(double);
	void makeNoise() const;
	int getAmountEaten()const;
	void setAmountEaten();
private:
	int neckLength = 0;
	int weight = 0;
	int amountEaten = 0;
};

class Monkey : public Animal {
public:
	Monkey(int weight = 0, int amountEaten = 0, int armLength = 0);
	void feed(double);
	void makeNoise() const;
	int getAmountEaten()const;
	void setAmountEaten();
private:
	int armLength = 0;
	int weight = 0;
	int amountEaten = 0;
};

class Person {
public:
	Person(const std::string& name = "", int age = 0);
	virtual ~Person() {}
	virtual string getName() const = 0;//纯虚函数getName使得person成为抽象类
	int getAge() const;
protected:
	string name = " ";
	int age = 0;
};

class ZooKeeper : public Person {
public:
	ZooKeeper(const std::string& name = "", int age = 0);
	void cleanEnclosure(AnimalEnclosure& enclosure);
	int getDaysCleaning() const;
	void addDaysCleaning();
	string getName() const;
private:
	int daysCleaning = 0;
};

class FoodSeller : public Person
{
public:
	FoodSeller(const string& name = "", int age = 0);
	void sellFood(int, int);
	void setFoodPrice(AnimalFood::Type type, double price);
	vector<double> getFoodPriceList() const;
	AnimalFood get_animalfood();
	vector<int> get_amount_of_food();
	AnimalFood getFood(AnimalFood::Type type) const;
	double getMoney() const;
	string getName() const;
	void set_amount_of_food();
	vector<int>amount_of_food = { 0,0,0 };
	void addmoney(double);
private:

	AnimalFood animalfood;
	vector<double> priceList = { 0.20,0.30,0.50 };
	Money money;
};

class Visitor : public Person
{
public:
	string getName()const override;
	int pass_ID = 0;
private:
	string Name = " ";
};

class Adult : public Visitor
{
public:
	string getName();
	double money_owned = 0.0;
private:
	string Name = " ";
};

class Children : public Visitor, public AnimalFood
{
public:
	string getName();
	Type* get_type_of_food_child_has();
	Type animalfood_child_has[3] = {};
	double amount_of_food[3] = {};
private:
	string Name = " ";
};

class zoo {
public:
	zoo();
	~zoo();
	bool zoostate = 1;
	void simulation_1day(Elephant*, Giraffe*, Monkey*, AnimalEnclosure&, AnimalEnclosure&, AnimalEnclosure&, int);
	void simulation_all(Elephant* elephantarr, Giraffe* giraffearr, Monkey* monkeyarr,
		AnimalEnclosure animalenclosure_elephant, AnimalEnclosure animalenclosure_giraffe, AnimalEnclosure animalenclosure_monkey);
};
#endif