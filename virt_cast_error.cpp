// virt_cast_error.cpp
// Show cast error (Parent to child)
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Animal
{
protected:
    string name_;

public:
    void SetName(string &&name) { name_ = name; };
    string GetName() { return name_; };
};

class Dog : public Animal
{
protected:
    string master_name_;

public:
    void SetMasterName(string &&master_name) { master_name_ = master_name; };
    string GetMasterName() { return master_name_; };
};

int main()
{
    Dog *dog = new Animal();
    Dog *real_dog = new Dog();

    dog->SetName("Dog");
    cout << dog->GetName() << endl;
    delete dog;
    delete real_dog;
    return 0;
}
