// C++ program to demonstrate how a virtual function
// is used in a real life scenario


#include "bits/stdc++.h"
class Employee {
public:
    virtual void raiseSalary()
    {
        // common raise salary code
    }
 
    virtual void promote()
    {
        // common promote code
    }
};
 
class Manager : public Employee {
    virtual void raiseSalary()
    {
        // Manager specific raise salary code, may contain
        // increment of manager specific incentives
        std::cout << "Salary Manager " << amount + 20 << std::endl;
    }
 
    virtual void promote()
    {
        // Manager specific promote
    }
private:
    int amount = {150};
};

class Engineer : public Employee {
  void raiseSalary()
  {
    std::cout << "Salary Engineer " << amount + 50 << std::endl;
  }  
  void promote()
  {
      
  }
private: 
  int amount = {100};
};


 
// Similarly, there may be other types of employees
 
// We need a very simple function
// to increment the salary of all employees
// Note that emp[] is an array of pointers
// and actual pointed objects can
// be any type of employees.
// This function should ideally
// be in a class like Organization,
// we have made it global to keep things simple
void globalRaiseSalary(Employee* emp[], int n)
{
    for (int i = 0; i < n; i++) {
        // Polymorphic Call: Calls raiseSalary()
        // according to the actual object, not
        // according to the type of pointer
        emp[i]->raiseSalary();
    }
}

void globalRaiseSalaryVec(std::vector<std::unique_ptr<Employee>> emp)
{
    for (auto &pers:emp) {
        // Polymorphic Call: Calls raiseSalary()
        // according to the actual object, not
        // according to the type of pointer
        pers->raiseSalary();
    }
}
int main()
{
    std::vector<std::unique_ptr<Employee>> emp; 
    emp.push_back(std::unique_ptr<Employee>(new Manager()));
    emp.push_back(std::unique_ptr<Employee>(new Engineer()));
    emp.push_back(std::unique_ptr<Employee>(new Manager()));    
    globalRaiseSalaryVec(std::move(emp));
    int num;
    std::cin >> num;
    /*
    Employee** emp = new Employee*[3];
    
    emp[0] = new Manager;
    emp[1] = new Engineer;
    emp[2] = new Engineer;
    
    globalRaiseSalary(emp,3);
    int num;
    std::cin >> num;
    */
    return 0;
}
