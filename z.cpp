#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
        public:
                int eno;
                char ename[100];
                float salary;
        public:
                void accept_details()
                {
                        cout<<"\n Enter Employee Details";
                        cout<<"\n -------------------------------------------";
                        cout<<"\n Enter Employee Id           :  ";
                        cin>>eno;
                        cout<<"\n Enter Employee Name     :  ";
                        cin>>ename;
                        cout<<"\n Enter Salary                     :  ";
                        cin>>salary;
                }
                int search(int empno);       //Function Overloading
                int search(char *empname); //search() function is overloaded
                int search(float empsalary);
};
int main()
{
        Employee *emp;
        int cnt, i, max;
        char name[100];
        int eno;
        float sal;
        cout<<"\n Enter No. of Employee Details You Want  :  ";
        cin>>cnt;
        emp=new Employee[cnt];
        for(i=0;i<cnt;i++)
        {
                emp[i].accept_details();
        }
        max=emp[0].salary;
        for(i=0;i<cnt;i++)
        {
                if(emp[i].salary>max)
                {
                        max=emp[i].salary;
                }
        }
        for(i=0;i<cnt;i++)
        {
                if(emp[i].salary==max)
                {
                        cout<<"\n ------------------------------------------------\n";
                        cout<<"\n Maximum Salary of Employee Name is : "<<emp[i].ename;
                        cout<<"\n And Salary is : "<<emp[i].salary;
                }

        }
        return 0;
}
