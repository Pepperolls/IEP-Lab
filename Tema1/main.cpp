using namespace std;
#include <iostream>

class Meat
{
private:
    string meatType;

public:
    Meat(string meatType) : meatType(meatType) {}

    static Meat *getMeat(string meatType)
    {
        return new Meat(meatType);
    }

    void toString()
    {
        cout << meatType << '\n';
    }
};

class Cheese
{
private:
    string cheeseType;
    int ageInYears;

public:
    Cheese(string cheeseType, int ageInYears) : cheeseType(cheeseType), ageInYears(ageInYears) {}

    static Cheese *getCheese(string cheeseType, int ageInYears)
    {
        return new Cheese(cheeseType, ageInYears);
    }

    void toString()
    {
        cout << cheeseType << " - " << ageInYears << " years old" << '\n';
    }
};

class Vegetable
{
private:
    string vegetableType;

public:
    Vegetable(string vegetableType) : vegetableType(vegetableType) {}

    static Vegetable *getVegetable(string vegetableType)
    {
        return new Vegetable(vegetableType);
    }

    void toString()
    {
        cout << vegetableType << '\n';
    }
};

class Sandwich
{
private:
    Meat *meat;
    Cheese *cheese;
    Vegetable *vegetable;

public:
    Sandwich(string meatType, string cheeseType, int ageInYears, string vegetableType)
    {
        this->meat = Meat::getMeat(meatType);
        this->cheese = Cheese::getCheese(cheeseType, ageInYears);
        this->vegetable = Vegetable::getVegetable(vegetableType);
    }

    ~Sandwich()
    {
        delete meat;
        delete cheese;
        delete vegetable;
    }

    void toString()
    {
        cout << "Your sandwich contains:\n";
        this->meat->toString();
        this->cheese->toString();
        this->vegetable->toString();
    }
};

class Uncopyable
{
protected:           // allow construction
    Uncopyable() {}  // and destruction of
    ~Uncopyable() {} // derived objects...
private:
    Uncopyable(const Uncopyable &); // ...but prevent copying
    Uncopyable &operator=(const Uncopyable &);
};

class SandwichEater : private Uncopyable
{
private:
    string name;
    int age;

public:
    SandwichEater(string name, int age) : name(name), age(age) {}

    void toString()
    {
        cout << name << " is " << age << " years old and likes sandwiches.\n";
    }
};

int main(int, char **)
{
    //Point 4
    Meat myMeat("Bacon");
    myMeat.toString();

    Sandwich testSandwich("Ham", "Cheddar", 10, "Cucumber");
    testSandwich.toString();

    //Point 5
    Meat myChickenBreast("Chicken breast");
    Meat mySecondChickenBreast("Random text");
    mySecondChickenBreast = myChickenBreast;
    mySecondChickenBreast.toString();

    Meat myCopiedMeat(myMeat);
    myCopiedMeat.toString();

    //Point 6
    SandwichEater firstEater("Ionut Lenghel", 30);
    firstEater.toString();
    // SandwichEater secondEater(firstEater);
}
