// Academy

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define delimeter "\n--------------------------------------------------------------------------------------------------------------------"

#define HUMAN_TAKE_PARAMETRS const std::string& first_name, const std::string& last_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS first_name, last_name, age
//#define inheritance



class Human
{
    std::string First_Name;
    std::string Last_Name;  
    unsigned int age;

public:
    const std::string& get_first_name() const
    {
        return First_Name;
    }
    const std::string& get_last_name() const
    {
        return Last_Name;
    }
    const unsigned int& get_age()const
    {
        return age;
    }
    void set_first_name(const std::string& First_Name)
    {
        this->First_Name = First_Name;
    }
    void set_last_name(const std::string& Lust_Name)
    {
        this->Last_Name = Lust_Name;
    }
    void set_age(unsigned int age)
    {
        this->age = age;
    }
    virtual void info() const
    {
        cout << First_Name << " " << Last_Name << " Age: " << age<<endl;
    }

    //Constructors;
    Human(HUMAN_TAKE_PARAMETRS)
    {
        set_first_name(first_name);
        set_last_name(last_name);
        set_age(age);
        cout << "HConstructor:\t" << this << endl;
    }
    virtual ~Human()
    {
        cout << "HDestructor:\t" << this<< endl;
    };
};

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendence
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendence
class Student : public Human
{
    std::string speciality;
    std::string group;
    double rating;
    double attendence;
public:
    const std::string& get_speciality() const
    {
        return speciality;
    }
    const std::string& get_group() const
    {
        return group;
    }
    const double& get_rating()const
    {
        return rating;
    }
    const double& get_attedence()const
    {
        return attendence;
    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality = speciality;
    }
    void set_group(const std::string& group)
    {
        this->group = group;
    }
    void set_rating(double rating) 
    {
        this->rating = rating;
    }
    void set_attendence(double attendence) 
    {
        this->attendence = attendence;
    }
    void info() const
    {
        Human::info();
        cout << speciality << " " << group << " Rating: " << rating <<" Attendence: "<< attendence << endl;
    }
    //Constructors
    Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS):Human(HUMAN_GIVE_PARAMETRS)
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendence(attendence);
        cout << "SConstructor:\t" << this << endl;
    }
    ~Student()
    {
        cout << "SDesstructor:\t" << this << endl;
    };
};
#define TEACHER_TAKE_PARAMETRS const std::string& speciality, const unsigned int& expirience, const std::string& skill
#define TEACHER_GIVE_PARAMETRS speciality, expirience, skill
class Teacher : public Human
{
    unsigned int expirience;
    std::string skill;
    std::string speciality;
public:
    const std::string& get_speciality() const
    {
        return speciality;
    }
    const unsigned int& get_expirience()const
    {
        return expirience;
    }
    const std::string& get_skill() const
    {
        return skill;
    }
    void set_expirience(const unsigned int& expirience)
    {
        this->expirience = expirience;
    }
    void set_skill(const std::string& skill)
    {
        this->skill = skill;
    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality = speciality;
    }
    void info() const
    {
        Human::info();
        cout << speciality << " Expirience: " << expirience << " Skill: " << skill <<  endl;
    }
    //  Countr/Destr
    Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
    {
        set_speciality(speciality);
        set_expirience(expirience);
        set_skill(skill);
        cout << "TConstructor:\t" << this << endl;
    }
    
    ~Teacher()
    {
        cout << "TDesstructor:\t" << this << endl;
    };

};
class Graduate : public Student
{
    std::string topic;
public:
    const std::string& get_topic()
    {
        return topic;
}
    void set_topic(const std::string& topic)
    {
        this->topic = topic;
    }
    void info() const
    {
        Student::info();
        cout << topic << endl;
    }

    //   constr/destr
    Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, const std::string& topic):Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
    {
        set_topic(topic);
        cout << "GConstructor:\t" << this << endl;
    };
    ~Graduate() 
    {
        cout << "GDesstructor:\t" << this << endl;
    };

};

int main()
{
    setlocale(LC_ALL,"rus");
#ifdef inheritance
    /*Human human("Тупенко", "Василий", 18);
    human.info();*/
    Student stud("Pinkman", "Jasie", 25, "Chemistry", "WW_220", 95, 99);
    stud.info();
    Teacher one("Strogova", "Tatiana", 50, "Math", 25, "Senior");
    one.info();
    Graduate grad("Shreder", "Hank", 40, "Criminalictic", "OBN", 90, 70, "How to catch Hisenberg");
    grad.info();
#endif
    Human* group[] =
    {
        new Student("Pinkman", "Jasie", 25, "Chemistry", "WW_220", 95, 99),
        new Teacher("Strogova", "Tatiana", 50, "Math", 25, "Senior"),
        new Graduate("Shreder", "Hank", 40, "Criminalictic", "OBN", 90, 70, "How to catch Hisenberg"),
        new Student("Vercetti","Tomas",30, "Theft","Vice",98,100),
        new Teacher("Diaz","Ricardo",50,"waepons distribution",50,"Senior")
    };
    cout << delimeter << endl;
    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
       
        group[i]->info();
        cout << delimeter << endl;
    }
    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {

        delete group[i];
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
