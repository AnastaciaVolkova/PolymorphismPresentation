// virt_segf_error.cpp
// Show segmentation fault when casting from parent to child is done by force
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
    void SetName(string&& name){name_ = name;};
    string GetName(){return name_;};
};

class Dog: public Animal
{
protected:
    string master_name_;
public:
    void SetMasterName(string&& master_name){master_name_ = master_name;};
    string GetMasterName(){return master_name_;};
};

int main()
{
    Dog* dog = reinterpret_cast<Dog*>(new Animal());    
    Dog* real_dog = new Dog();
    
    dog->SetName("Dog");
    dog->SetMasterName("Master");
    cout << dog->GetName() << endl;
    cout << dog->GetMasterName() << endl;
    delete dog;
    delete real_dog;
    return 0;
}
