/*

#include<iostream>
using namespace std;

class hero
{
    private:
    int health;

    public:
    char level;

    void set_health(int he)
    {
        health=he;
    }

    int get_health()
    {
        return health;
    }
};

int main(){
    hero h1;
    h1.level='A';
    h1.set_health(20);
    cout<<"The level is: "<<h1.level<<endl;
    cout<<"The health is: "<<h1.get_health()<<endl;    
return 0;
}
*/

#include<iostream>
using namespace std;

class Hero
{
    private:
    int health;
    char level;
    float percent;


    public:

    void set_health(int h)
    {
        health=h;
    }
    void set_level(char l)
    {
        level=l;
    }
    void set_percent(float p)
    {
        percent=p;
    }
    int get_health()
    {
        return health;
    }
    int get_level()
    {
        return level;
    }
    float get_percent()
    {
        return percent;
    }
};

int main(){
    Hero h1;
    h1.set_health(100);
    h1.set_level('A');
    h1.set_percent(99.9);

    cout<<"The Health is: "<<h1.get_health()<<endl;
    cout<<"The level is: "<<h1.get_level()<<endl;
    cout<<"The percent is: "<<h1.get_percent()<<endl;    
return 0;
}




























