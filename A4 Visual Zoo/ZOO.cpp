#include"ZOO.h"
#include<iostream>
#include<random>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//全局变量用来记录一个生命周期内成年游客和小孩的数量
int total_num_adults = 0;
int total_num_children = 0;
zoo::zoo()
{
}
zoo::~zoo()
{
}
random_device rd; //硬件生成随机数种子
FoodSeller foodseller;

AnimalFood animalfood;
ZooKeeper zookeeper;

random_device rd_h; //硬件生成随机数种子

void FoodSeller::set_amount_of_food()
{
	random_device rd_h; //硬件生成随机数种子

	mt19937 eng01(rd_h()); //利用种子生成随机数引擎
	uniform_int_distribution<int> random_foodsum_1(25000, 40000); //设置随机数范围，并为均匀分布
	int  random_foodsum_distribution_1 = random_foodsum_1(eng01);

	mt19937 eng02(rd_h()); //利用种子生成随机数引擎
	uniform_int_distribution<int> random_foodsum_2(7000, 10000); //设置随机数范围，并为均匀分布
	int random_foodsum_distribution_2 = random_foodsum_2(eng02);

	mt19937 eng03(rd_h()); //利用种子生成随机数引擎
	uniform_int_distribution<int> random_foodsum_3(7000, 10000); //设置随机数范围，并为均匀分布
	int random_foodsum_distribution_3 = random_foodsum_3(eng03);
	amount_of_food = { random_foodsum_distribution_1,random_foodsum_distribution_2,random_foodsum_distribution_3 };
}

void FoodSeller::addmoney(double income)
{
	money.addamount(income);
}

void zoo::simulation_1day(Elephant* elephantarr, Giraffe* giraffearr, Monkey* monkeyarr,
	AnimalEnclosure& animalenclosure_elephant, AnimalEnclosure& animalenclosure_giraffe, AnimalEnclosure& animalenclosure_monkey, int t)
{
	//每天生成真随机的20~40个成人游客
	/*
	srand(time(nullptr));//设置随机数种子
	int random_adult=rand()%21+20;
	int  num_of_adult_a_day = random_adult;
	*/
	for (int i = 0; i < 3; i++)
	{
		cout << "animalfood: " << foodseller.amount_of_food[i] << endl;
	}
	mt19937 eng1(rd()); //利用种子生成随机数引擎
	uniform_int_distribution<int> random_adult(20, 40); //设置随机数范围，并为均匀分布
	int  num_of_adult_a_day = random_adult(eng1);
	total_num_adults += num_of_adult_a_day;

	cout << "random_adult:" << num_of_adult_a_day << endl;

	//所有人成年游客对象构成一个对象数组
	Adult* adult = new Adult[num_of_adult_a_day];

	//为每位成年游客对象分配小孩和钱
	for (int n = 0; n < num_of_adult_a_day; n++)
	{
		cout << "adult: " << n << endl;
		//每个成人游客随机携带10~20刀
		mt19937 eng2(rd()); //利用种子生成随机数引擎
		uniform_int_distribution<int> random_money(100, 200); //设置随机数范围，并为均匀分布
		double  num_of_random_money = random_money(eng2) / 10.0;
		cout << "random_money: " << num_of_random_money << endl;

		//每个成人游客随机携带1-3个小孩
		mt19937 eng3(rd()); //利用种子生成随机数引擎
		uniform_int_distribution<int> random_child(1, 3); //设置随机数范围，并为均匀分布
		int  num_of_random_child = random_child(eng3);
		total_num_children += num_of_random_child;
		cout << "random_child: " << num_of_random_child << endl;
		int num_of_child_for_a_adult = num_of_random_child;
		Children* children = new Children[num_of_child_for_a_adult];
		adult[n].money_owned = num_of_random_money;
		adult[n].money_owned -= (1 + num_of_child_for_a_adult * 0.4);
		adult[n].money_owned /= num_of_child_for_a_adult;

		//给每个大人带的每个小孩分配动物的食物
		//如果卖家所有食物都还有，卖家的钱增加，食物减少
		if (foodseller.get_amount_of_food()[0] > 0 && foodseller.get_amount_of_food()[1] > 0 && foodseller.get_amount_of_food()[2] > 0)
		{
			for (int i = 0; i < num_of_child_for_a_adult; i++)
			{
				//调整规则，让每个小孩得到的食物总价钱一样但是各类食物数量不同且随机
				mt19937 eng4(rd()); //利用种子生成随机数引擎
				uniform_int_distribution<int> random_food_1(0, 9); //设置随机数范围，并为均匀分布
				double  random_food_distribution_1 = random_food_1(eng4) / 10.0;

				mt19937 eng5(rd()); //利用种子生成随机数引擎
				uniform_int_distribution<int> random_food_2(0, 10 - random_food_distribution_1 * 10.0 - 1); //设置随机数范围，并为均匀分布
				double random_food_distribution_2 = random_food_2(eng5) / 10.0;

				double random_food_distribution_3 = 1.0 - random_food_distribution_1 - random_food_distribution_2;

				//分配
				children[i].amount_of_food[0] = (adult[n].money_owned * random_food_distribution_1 / foodseller.getFoodPriceList()[0]);
				cout << children[i].amount_of_food[0] << " PEANUTS" << endl;
				//小贩对应的食物减少
				foodseller.amount_of_food[0] -= children[i].amount_of_food[0];
				//相应地，小贩的钱增加
				foodseller.addmoney(children[i].amount_of_food[0] * foodseller.getFoodPriceList()[0]);
				children[i].amount_of_food[1] = (adult[n].money_owned * random_food_distribution_2 / foodseller.getFoodPriceList()[1]);
				cout << children[i].amount_of_food[1] << " CARROTS " << endl;
				foodseller.amount_of_food[1] -= children[i].amount_of_food[1];
				foodseller.addmoney(children[i].amount_of_food[1] * foodseller.getFoodPriceList()[1]);
				children[i].amount_of_food[2] = (adult[n].money_owned * random_food_distribution_3 / foodseller.getFoodPriceList()[2]);
				cout << children[i].amount_of_food[2] << " BANANAS " << endl;
				foodseller.amount_of_food[2] -= children[i].amount_of_food[2];
				foodseller.addmoney(children[i].amount_of_food[2] * foodseller.getFoodPriceList()[2]);
				cout << endl;
			}
			if (foodseller.get_amount_of_food()[0] <= 0)
			{
				this->zoostate = 0;
				cout << "The zoo closed because the seller ran out of peanuts." << endl;
				return;
			}
			else if (foodseller.get_amount_of_food()[1] <= 0)
			{
				this->zoostate = 0;
				cout << "The zoo closed because the seller ran out of carrots." << endl;
				return;
			}
			else if (foodseller.get_amount_of_food()[2] <= 0)
			{
				this->zoostate = 0;
				cout << "The zoo closed because the seller ran out of bananas." << endl;
				return;
			}
			else
			{
				cout << "Begin to sell !" << endl;
			}

			//如果围栏处于关闭状态，通过判断日期的奇偶性是否相同来确定是否已经隔天以及围栏是否重新开放
			if ((!animalenclosure_elephant.isOpen()) && (t % 2) == (animalenclosure_elephant.opstate_judge_get() % 2))
				animalenclosure_elephant.open();
			if ((!animalenclosure_giraffe.isOpen()) && ((t % 2) == (animalenclosure_giraffe.opstate_judge_get() % 2)))
				animalenclosure_giraffe.open();
			if ((!animalenclosure_monkey.isOpen()) && ((t % 2) == (animalenclosure_monkey.opstate_judge_get() % 2)))
				animalenclosure_monkey.open();

			//如果围栏还开着、动物吃得下，喂食，每个动物围栏变脏，每一只动物吃的食物增加,围栏的开放天数增加
			for (int j = 0; j < num_of_child_for_a_adult; j++)
			{
				for (int i = 0; i < 1; i++)
				{
					if ((elephantarr[i].getAmountEaten() < 750) && (animalenclosure_elephant.isOpen()))
					{
						elephantarr[i].feed(children[j].amount_of_food[0]);
						foodseller.sellFood(foodseller.get_animalfood().get_amount_of_food()[0], children[j].amount_of_food[0]);
						cout << "current amountEaten of elephant " << i << " is: " << elephantarr[i].getAmountEaten() << endl;
						cout << "current dirtLevel of elephant " << i << " is: ";
						animalenclosure_elephant.addDirt(children[j].amount_of_food[0]);
					}
					else
					{
						cout << "The elephant " << i << " is full!" << endl;
					}
				}
				for (int i = 0; i < 2; i++)
				{
					if (giraffearr[i].getAmountEaten() < 500 && animalenclosure_giraffe.isOpen())
					{
						giraffearr[i].feed(children[j].amount_of_food[1]);
						foodseller.sellFood(foodseller.get_animalfood().get_amount_of_food()[1], children[j].amount_of_food[1]);
						cout << "current amountEaten of giraffe " << i << " is: " << giraffearr[i].getAmountEaten() << endl;
						cout << "current dirtLevel of giraffe " << i << " is: ";
						animalenclosure_giraffe.addDirt(children[j].amount_of_food[1]);
					}
					else
					{
						cout << "The giraffe " << i << " is full!" << endl;
					}
				}
				for (int i = 0; i < 3; i++)
				{
					if (monkeyarr[i].getAmountEaten() < 300 && animalenclosure_monkey.isOpen())
					{
						monkeyarr[i].feed(children[j].amount_of_food[2]);
						foodseller.sellFood(2, children[j].amount_of_food[2]);
						cout << "current amountEaten of monkey " << i << " is: " << monkeyarr[i].getAmountEaten() << endl;
						cout << "current dirtLevel of monkey " << i << " is: ";
						animalenclosure_monkey.addDirt(children[j].amount_of_food[2]);
					}
					else
					{
						cout << "The monkey " << i << " is full!" << endl;
					}
				}
			}
		}
	}
	//如果围栏特别脏，keep清理，每天关闭围栏
	if (animalenclosure_elephant.getDirt() >= 7000)
	{
		//关闭围栏
		animalenclosure_elephant.close();
		//围栏已经关闭，将当前日期设置为围栏再次开放的判断基准
		animalenclosure_elephant.opstate_judge_set(t);
		zookeeper.cleanEnclosure(animalenclosure_elephant);
		cout << "The animal_enclosure_elephant is so dirty! (dirtLevel>=700)\nThe zookkeep will close it for a day." << endl;
		animalenclosure_elephant.clean(); cout << "animalenclosure_elephant" << endl;
	}
	else animalenclosure_elephant.add_open_days();
	if (animalenclosure_giraffe.getDirt() >= 7000)
	{
		//关闭围栏
		animalenclosure_giraffe.close();
		//围栏已经关闭，将当前日期设置为围栏再次开放的判断基准
		animalenclosure_giraffe.opstate_judge_set(t);
		zookeeper.cleanEnclosure(animalenclosure_giraffe);
		cout << "The animal_enclosure_giraffe is so dirty! (dirtLevel>=700) \nThe zookkeep will close it for a day." << endl;
		animalenclosure_giraffe.clean(); cout << "animalenclosure_giraffe" << endl;
	}
	else animalenclosure_giraffe.add_open_days();
	if (animalenclosure_monkey.getDirt() >= 7000)
	{
		//关闭围栏
		animalenclosure_monkey.close();
		//围栏已经关闭，将当前日期设置为围栏再次开放的判断基准
		animalenclosure_monkey.opstate_judge_set(t);
		//清理围栏
		zookeeper.cleanEnclosure(animalenclosure_monkey);
		cout << "The animal_enclosure_monkey is so dirty! (dirtLevel>=700)\nThe zookkeep will close it for a day." << endl;
		animalenclosure_monkey.clean(); cout << "animalenclosure_monkey" << endl;
	}
	else animalenclosure_monkey.add_open_days();
	for (int i = 0; i < 1; i++)
	{
		elephantarr[i].setAmountEaten();
	}
	for (int i = 0; i < 2; i++)
	{
		giraffearr[i].setAmountEaten();
	}
	for (int i = 0; i < 3; i++)
	{
		monkeyarr[i].setAmountEaten();
	}
	if (zookeeper.getDaysCleaning() >= 10)
	{
		this->zoostate = 0;
		cout << "-------------------------The zoo closed because the zoo keeper had enough of cleaning and quit!-------------------------" << endl;
	}
}

void zoo::simulation_all(Elephant* elephantarr, Giraffe* giraffearr, Monkey* monkeyarr,
	AnimalEnclosure animalenclosure_elephant, AnimalEnclosure animalenclosure_giraffe, AnimalEnclosure animalenclosure_monkey)
{
	int t = 1;
	while (this->zoostate == 1)
	{
		cout << "-------------------------------------------------DAY" << t << "-------------------------------------------------" << endl;
		zoo::simulation_1day(elephantarr, giraffearr, monkeyarr, animalenclosure_elephant, animalenclosure_giraffe, animalenclosure_monkey, t);
		cout << "The day " << t++ << " is over." << endl;
	}
	//动物园开放的天数
	cout << "The zoo is open for " << t - 1 << " days." << endl;

	//输出成年游客总数和在整个生命周期中参观动物园的儿童总数
	cout << "The total number of adult visitors is: " << total_num_adults << endl;
	cout << "The total number of children visitors is: " << total_num_children << endl;
	//卖家赚的总钱
	cout << "The total money the food seller earned is: " << foodseller.getMoney() << "dollars!" << endl;
	//动物园管理员打扫卫生的天数
	cout << "The zoo keeper cleaned the zoo for " << zookeeper.getDaysCleaning() << " days." << endl;

	//每个动物围栏关闭的天数
	cout << "The animal enclosure elephant was closed for " << t - 1 - animalenclosure_elephant.get_open_days() << " days." << endl;
	cout << "The animal enclosure giraffe was closed for " << t - 1 - animalenclosure_giraffe.get_open_days() << " days." << endl;
	cout << "The animal enclosure monkey was closed for " << t - 1 - animalenclosure_monkey.get_open_days() << " days." << endl;
}

Money::Money(double dollars)
{
}
Money::~Money()
{
}
void Money::add(double dollars)
{
}

double Money::getAmount() const
{
	return amount;
}

Money Money::operator+(const Money& other) const
{
	return Money();
}

Money Money::operator-(const Money& other) const
{
	return Money();
}

void Money::addamount(double income)
{
	amount = amount + income;
}

AnimalFood::AnimalFood(Type type, int amount)
{
}
vector<int> AnimalFood::get_amount_of_food() const
{
	return amount_of_food;
}
/*
void AnimalFood::add(int amount)
{
}

int AnimalFood::getAmount() const
{
	return 0;
}

AnimalFood::Type AnimalFood::getType() const
{
	return Type();
}

AnimalFood AnimalFood::operator+(const AnimalFood& other) const
{
	return AnimalFood();
}

AnimalFood AnimalFood::operator-(const AnimalFood& other) const
{
	return AnimalFood();
}
*/
AnimalEnclosure::AnimalEnclosure() :openStatus(1), dirtLevel(50), time(1)
{
	openDays = 0;
}

bool AnimalEnclosure::isOpen() const
{
	return openStatus;
}

void AnimalEnclosure::open()
{
	openStatus = 1;
}

void  AnimalEnclosure::close()
{
	openStatus = 0;
}

void AnimalEnclosure::opstate_judge_set(int timesample)
{
	time = timesample;
}

int AnimalEnclosure::opstate_judge_get()
{
	return time;
}

void AnimalEnclosure::addDirt(int amount)
{
	dirtLevel += amount;
	cout << dirtLevel << endl;
}

int AnimalEnclosure::getDirt() const
{
	return dirtLevel;
}

void AnimalEnclosure::clean()
{
	cout << "clean!";
	dirtLevel = 0;
}

void AnimalEnclosure::add_open_days()
{
	openDays++;
	cout << "openDay_now: " << this->openDays << endl;
}

int AnimalEnclosure::get_open_days()
{
	return openDays;
}

Animal::Animal() :weight(10), amountEaten(10)
{
}

int Animal::getWeight() const
{
	return 0;
}

int Animal::getAmountEaten() const
{
	return amountEaten;
}

Elephant::Elephant(int weight, int amountEaten, int trunkLength) :trunkLength(trunkLength), amountEaten(amountEaten), weight(weight)
{
}

void Elephant::feed(double amount_of_food)
{
	cout << "feed elephant!" << endl;
	amountEaten += amount_of_food;
}

void Elephant::makeNoise() const
{
}

int Elephant::getAmountEaten() const
{
	return amountEaten;
}

void Elephant::setAmountEaten()
{
	amountEaten = 0;
}

Giraffe::Giraffe(int weight, int amountEaten, int neckLength) :neckLength(neckLength), amountEaten(amountEaten), weight(weight)
{
}

void Giraffe::feed(double amount_of_food)
{
	cout << "feed giraffe!" << endl;
	amountEaten += amount_of_food;
}

void Giraffe::makeNoise() const
{
}

int Giraffe::getAmountEaten() const
{
	return amountEaten;
}

void Giraffe::setAmountEaten()
{
	amountEaten = 0;
}

Monkey::Monkey(int weight, int amountEaten, int armLength) :armLength(armLength), amountEaten(amountEaten), weight(weight)
{
}

void Monkey::feed(double amount_of_food)
{
	cout << "feed monkey!" << endl;
	amountEaten += amount_of_food;
}

void Monkey::makeNoise() const
{
}

int Monkey::getAmountEaten() const
{
	return amountEaten;
}

void Monkey::setAmountEaten()
{
	amountEaten = 0;
}

Person::Person(const string& name, int age)
{
}

string Person::getName() const
{
	return Person::name;
}

int Person::getAge() const
{
	return 0;
}

ZooKeeper::ZooKeeper(const string& name, int age)
{
}

void ZooKeeper::cleanEnclosure(AnimalEnclosure& enclosure)
{
	daysCleaning++;
	cout << "the zookeeper has worked for " << daysCleaning << " day!" << endl;
	enclosure.clean();
}

int ZooKeeper::getDaysCleaning() const
{
	return daysCleaning;
}

string ZooKeeper::getName() const
{
	return string();
}

void ZooKeeper::addDaysCleaning()
{
	daysCleaning++;
}

FoodSeller::FoodSeller(const std::string& name, int age)
{
	this->set_amount_of_food();
}

void FoodSeller::sellFood(int foodindex, int amount)
{
}

void FoodSeller::setFoodPrice(AnimalFood::Type type, double price)
{
}

vector<double> FoodSeller::getFoodPriceList()const
{
	return priceList;
}

AnimalFood FoodSeller::get_animalfood()
{
	return animalfood;
}

vector<int> FoodSeller::get_amount_of_food()
{
	return amount_of_food;
}

AnimalFood FoodSeller::getFood(AnimalFood::Type type) const
{
	return AnimalFood();
}

double FoodSeller::getMoney() const
{
	return money.getAmount();
}

string FoodSeller::getName() const
{
	return string();
}

string Adult::getName()
{
	return Adult::Name;
}

string Children::getName()
{
	return string();
}

AnimalFood::Type* Children::get_type_of_food_child_has()
{
	return animalfood_child_has;
}

string Visitor::getName() const
{
	return string();
}