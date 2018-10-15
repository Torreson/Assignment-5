#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class studentType {
  public:
    string getId();
    string getName();
    int getAge();
    int getGender();
    int getScore();
    string getGrade();
    studentType();
    studentType(string, string, int, int, int, string);

  private:
    string id;
    string name;
    int age;
    int gender;
    int score;
    string grade;
};

studentType::studentType() {};
studentType::studentType(string stud_id, string stud_name, int stud_age, int stud_gender, int stud_score, string stud_grade) {
  id = stud_id;
  name = stud_name;
  age = stud_age;
  gender = stud_gender;
  score = stud_score;
  grade = stud_grade;
}

string studentType::getId() {
  return id;
}

string studentType::getName() {
  return name;
}

int studentType::getAge() {
  return age;
}

int studentType::getGender() {
  return gender;
}

int studentType::getScore() {
  return score;
}

string studentType::getGrade() {
  return grade;
}

int main() {
  studentType students[5];
  int male_count = 0;
  int female_count = 0;
  int total_age = 0;
  int total_score = 0;
  const int NO_STUD = 2;

  for (int i = 0; i < NO_STUD; i++) {
    string id;
    string name;
    int age;
    int gender;
    int score;
    string grade;
    
    cout<<"Enter ID:  ";
    cin>>id;

    cout<<"Enter name:  ";
    cin>> name;

    cout<<"Enter age:  ";
    cin>> age;
    total_age += age;

    cout<<"Enter gender (1 for male, 2 for female):  ";
    cin>> gender;
    gender == 1 ? male_count++ : female_count++;

    cout<<"Enter score:  ";
    cin>> score;
    total_score += score;

    cout<<"Enter grade:  ";
    cin>> grade;
    cout<<endl<<endl;

    students[i] = studentType(id, name, age, gender, score, grade);
  }

  ofstream output;

  output.open("output.txt", ios::out);

  output<<left;
  // output<<"ID       Name   Age Gender Score Grade"<<endl;
  output<<"********************************************************"<<endl;
  output<<setw(10)<<"ID"<<setw(15)<<"Name"<<setw(8)<<"Age"<<setw(8)<<"Gender"<<setw(8)<<"Score"<<setw(8)<<"Grade"<<endl;
  for (int i = 0; i < NO_STUD; i++) {
    studentType s = students[i];
    output<<setw(10)<<s.getId();
    output<<setw(15)<<s.getName();
    output<<setw(8)<<s.getAge();
    output<<setw(8)<<(s.getGender() == 1 ? "m" : "f");
    output<<setw(8)<<s.getScore();
    output<<setw(8)<<s.getGrade();
    output<<endl;
  }
  output<<"********************************************************"<<endl;
  output<<"Average Age:  "<<(total_age / NO_STUD)<<endl;
  output<<"Average Score:  "<<(total_score / NO_STUD)<<endl;
  output<<"Male Count:  "<<male_count<<endl;
  output<<"Female Count:  "<<female_count<<endl;

  return 0;
}