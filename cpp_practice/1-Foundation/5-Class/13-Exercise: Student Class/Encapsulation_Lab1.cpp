
#include <cassert>
#include <stdexcept>
#include <string>

// TODO: Define "Student" class
class Student {
 public:
  // constructor
    Student(std::string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa){
    Validate();
}
  // accessors
    std::string Name(){
	return name_;
}
    int Grade() const{
	return grade_;
}
    float GPA() const{
	return gpa_;
}
  // mutators
    void Name(std::string name){
	name_ = name;
	Validate();
}
   void Grade(int grade){
	grade_ = grade;
	Validate();
}
   void GPA(float gpa){
	gpa_ = gpa;
	Validate();
}

 private:
  // name
    std::string name_;
  // grade
    int grade_;	 
  // GPA
    float gpa_;
    void Validate(){
	if(Grade() < 0  || Grade() > 12 || GPA() < 0.0 || GPA() > 4.0)
	    throw std::invalid_argument("argumet out of bounds");

}
};

// TODO: Test
int main() {
    Student student("khaled gabr", 10, 4.0);
    assert(student.Name() == "khaled gabr");
    assert(student.Grade() == 10);
    assert(student.GPA() == 4.0);

    bool caught{false};
    try{
       student.Grade(20);
}
    catch (...){

        caught = true;
}
    assert(caught);



}

