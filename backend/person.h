#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>
using std::string;

class Person {
    private:
        int age;
        string name;
        string id;
        string sex;
        bool is_admin;
    public:
        Person(int age, string name, string id, string sex, bool is_admin): age(age), name(name), id(id), sex(sex), is_admin(is_admin) {};
        int get_age() const {
            return age;
        }
        void change_age(int new_age) {
            age = new_age;
        }
        string get_name() const {
            return name;
        }
        void change_name(string new_name) {
            name = new_name;
        }
        string get_id() const {
            return id;
        }
        void change_id(string new_id) {
            id = new_id;
        }   
        string get_sex() const {
            return sex;
        }
        void change_sex(string new_sex) {
            sex = new_sex;
        }
        bool get_is_admin() const {
            return is_admin;
        }
        void change_is_admin(bool new_is_admin) {
            is_admin = new_is_admin;
        }
        ~ Person();        
};

#endif