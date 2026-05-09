
// #include "Intern.hpp"
//#include <iostream>

//    class Student {
//       public:
//       int age;
//       int grade;
//    };

// int main()
// {
//    Student wafae;
//    int Student::*ptr = &Student::age;// we do tis cause ptr isnt pointing to actual memory but to the offset inside the class where the age is it age is just a description no real memory yet 
//    // Student::age blueprint: “every Student has an age”
//    //wafae.age  actual value inside one Student
//    //&Student::age rule to locate age inside any Student
//    // &s.age real memory address of that specific object
//    // wafae.*ptr = 10 tochange it .* is The .* operator applies a pointer-to-member to an object, allowing access to a member whose location is described by the pointer.
//    // if it were 
//    //Student *s;
//    //s=&w; then we can access it by s->*ptr 
// }  


// class Student {
//    public:
//       int age;
//       int grade;
//       float gpa;

//       void printAge() {
//          std::cout << age << std::endl;
//       }

//       void addGrade(int x) {
//          grade += x;
//       }
// };
// int main()
// {
//    Student wafae;
//    //int Student::*ptr = &Student::age;
//    // wafae.*ptr = 10;
//    // // std::cout << wafae.age << "\n";
//    // std::cout << wafae.*ptr;
//    Student *s;
//    s = &wafae;
//    wafae.age = 28;
//    // int Student::*ptr =&Student::grade;
//    // s->*ptr = 18;
//    // std::cout << s->*ptr;
//    // float Student::*ptr = &Student::gpa;
//    // wafae.*ptr = 3.5;
//    // std::cout << wafae.*ptr <<"\n";
//    // wafae.*ptr+=0.3;
//    // std::cout << wafae.*ptr <<"\n";
//    void (Student::*ptr)()= &Student::printAge;
//    //wafae.*ptr ; Because .* does NOT automatically execute anything.
//    //It only selects the member function. function reference (not executed)
//    (wafae.*ptr)();// function actually being executed;


// }
// int main()
// {
//    Student s;
//    int Student::*ptr = &Student::grade;
//    s.*ptr = 5;
//    void (Student::*ptr1)(int x) = &Student::addGrade;
//    (s.*ptr1)(10);
//    std::cout << s.*ptr;

// }
#include <iostream>

class Student {
public:
    int age;
    int grade = 0;
    float gpa;

    void setAge(int a) {
        age = a;
    }

    int getAge(int x) {
       age = x;
        return age;
    }

    int addGrade(int x) {
      

        grade += x;
        return grade;
    }

    float improveGpa(float bonus) {
        gpa += bonus;
        return gpa;
    }

    bool isPassed() {
        return grade >= 10;
    }
};
int main()
{
   int (Student::*ptr[])(int x) ={
      &Student::getAge, &Student::addGrade
   };

   Student s;

   for(int i = 0;i<2;i++)
   {
      std::cout << (s.*(ptr[i]))(10) <<"\n" ;
   }  
}