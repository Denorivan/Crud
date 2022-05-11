#include <iostream>
#include <string>
#include <Windows.h> //для работы с нужными функциями системы
#include <ctime>
#include "stdlib.h"
 
using namespace std;
//структура ФИО
struct Initial 
{
    string surname,
           name,
           patronymic;
};
//структура возраста
struct Age
{
    int a;
};
//структура индекса
struct Index
{
    int b;
};
//структура данных
struct Data
{
    Initial _initial;
    Age _age;
    Index _index;
};
int ID ()
{
   srand(time(NULL));
   int c = rand()%9999+100000;
   return c;
}

void DataEntry (Data* (&d), int &n)
{
    setlocale(LC_ALL,"rus");
    cout<<"Введите количество пользователей: ";
    cin>>n;
    d = new Data[n]; 
    for(int i=0; i<n; i++)
    {
         cout<<"Введите Вашу фамилию ";
        cin>>d[i]._initial.surname;
         cout<<"Введите Ваше имя ";
        cin>>d[i]._initial.name;
        cout<<"Введите Ваше отчество ";
        cin>>d[i]._initial.patronymic;

        cout<<"Введите возраст: ";
        cin>>d[i]._age.a;

        cout<<"Ваш ID: "<< ID() <<endl;

        cout<<"_____________________________________"<<endl;

    }
}
void Print (Data* d, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"Данные № "<< i + 1 <<":"<<endl;
        cout<<"ФИО: "<<d[i]._initial.surname<<" "<<d[i]._initial.name<<" "<<d[i]._initial.patronymic<<endl;
        cout<<"Возраст: "<<d[i]._age.a<<endl;
        cout<<"Ваш ID: "<<ID()<<endl;
        cout<<"_____________________________________"<<endl;
    }
}
void DataChange(Data* (&d), int n)
{
     for(int i = 0; i < n; i++)
    {
        cout<<"Данные № "<< i + 1 <<":"<<endl;
        cout<<"ФИО: "<<d[i]._initial.surname<<" "<<d[i]._initial.name<<" "<<d[i]._initial.patronymic<<endl;
        cout<<"Возраст: "<<d[i]._age.a<<endl;
        cout<<"Ваш ID: "<<ID()<<endl;
        cout<<"_____________________________________"<<endl;
    }  
    int _n;
    cout<<"Введите номер элемента, который хотите изменить (от 1 до "<< n << "):";
    cin>>_n;
    _n--;
    system("cls");

    if(_n >= 0 && _n < n)
    {
        cout<<"Введите Вашу фамилию ";
        cin>>d[_n]._initial.surname;
        cout<<"Введите Ваше имя ";
        cin>>d[_n]._initial.name;
        cout<<"Введите Ваше отчество ";
        cin>>d[_n]._initial.patronymic;
        
        cout<<"Введите возраст: ";
        cin>>d[_n]._age.a;

        system ("pause");
        cout<<"Данные изменены!"<<endl;
    }
    else
    cout<<"Номер введен не верно!"<<endl;
}
Copy(Data* (d_n), Data* (d_o), int n)
{
    for(int i=0; i<n; i++)
    {
        d_n[i]=d_o[i];
    }
}
void DeleteData(Data* (&d), int& n)
{
      for(int i = 0; i < n; i++)
    {
        cout<<"Данные № "<< i + 1 <<":"<<endl;
        cout<<"ФИО: "<<d[i]._initial.surname<<" "<<d[i]._initial.name<<" "<<d[i]._initial.patronymic<<endl;
        cout<<"Возраст: "<<d[i]._age.a<<endl;
        cout<<"Ваш ID: "<<ID()<<endl;
        cout<<"_____________________________________"<<endl;
    } 
    int _n;
    cout<<"Введите номер элемента, который хотите изменить (от 1 до "<< n << "):";
    cin>>_n;
    _n--;
    system("cls");
    if(_n >= 0 && _n < n)
    {
        Data* cop = new Data[n];
        Copy(buf, d, n)
        --n;
        d = new Data[n];
        int q=0;
        for(int i=0; i<=n; i++)
        {
            if (i!=_n)
            {
              d[q]=cop[i];
              ++q;
            }
        }


    }


        cout<<"Данные удалены!"<<endl;
}
int stateMenu;
void Menu()
{
    cout<<"Выберите действие: "<<endl
    <<"(0) Выход из программы "<<endl
    <<"(1) Ввод данных "<<endl
    <<"(2) Вывод "<<endl
    <<"(3) Изменение "<<endl
    <<"(4) Удаление "<<endl
    <<"Ваш выбор: ";
    cin>> stateMenu;
}  

void main()
{
    setlocale(LC_ALL,"rus");
    Menu();
    //инициализация данных
     int amountOfData = 0;

    //массив данных
    Data* d = new Data[amountOfData]; 

    while (stateMenu)
    { 
        if(stateMenu==0)
        {
            exit(0);
        }
        switch(stateMenu)
        {
            case 1:
            system("cls");
            DataEntry(d,amountOfData);
            system("pause");
            system("cls");
            Menu();
            break;
            //////////////////////////////////////////////
            case 2:
            system ("cls");
            if(amountOfData !=0)
            {
                Print(d, amountOfData);
            } 
            else
                cout<<"Данные пусты! "<<endl;
            system ("pause");
            system ("cls");
            Menu();
            break;
            //////////////////////////////////////////////
            case 3:
            system ("cls");
            if(amountOfData !=0)
            {
                 DataChange(d, amountOfData);
            } 
            else
                cout<<"Данные пусты! "<<endl;
            system ("pause");
            system ("cls");
            Menu();
            break;
            ////////////////////////////////////////////////
            case 4:
            system ("cls");
            if(amountOfData !=0)
            {
                 DeleteData(d, amountOfData);
            }
            else
                cout<<"Данные пусты! "<<endl;
            system ("pause");
            system ("cls");
            Menu();
            break;
            /////////////////////////////////////////////////
            default:
                 cout<<"Неверно введен номер действия!"<<endl;
                 system ("pause");
                 system ("cls");
                 Menu();
                 break;
            
       } 
    }
}