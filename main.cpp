#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>

// struct to hold student data
struct Student {
  std::string surname;
  int sid;         // student ID number
  int test1;       // test 1 grade (0 to 100)
  int test2;       // test 2 grade (0 to 100)
  int test3;       // test 3 grade (0 to 100)
  int test4;       // test 4 grade (0 to 100)
  double average;  // average of all tests (equal weight)
};

// function prototypes
int count_lines();
void read_into_array(Student array[], int n);
double averagemark(Student array[], int n);
void print_array(const Student array[], int n);

double highest_student(Student array[], int n);
void print_highest(Student array[], int n, int high);

double lowest_student(Student array[], int n);
void print_lowest(Student array[], int n, int low);

void pass(Student array[], int n);

double lowest_mark(const Student sortedlow[], int n);

int main() {
  // count the number of lines in the CSV
  int n = count_lines();
  std::cout << n << " lines read." << std::endl;
  // then create dynamic array of correct size
  Student *students = new Student[n];

  // read the CSV file into the array
  read_into_array(students, n);

  // call functions for highest and lowest
  int high = highest_student(students, n);
  print_highest(students, n, high);

  int low = lowest_student(students, n);
  print_lowest(students, n, low);

  //stores the percentage of people that passed
  pass(students, n);
  //prints the percentage std:: cout << "The student with the highest mark is " << array[high].surname << std::endl;
  // and then print for debug purposes
  print_array(students, n);
}

void pass(Student array[], int n){
  double pass_number;

  for(int i = 0; i < n; i++){
    if(array[i].average > 40){
      pass_number++;
    }
  }

  double hehe = (pass_number/n) * 100;
  std::cout << "the percantage of people that passed is " << hehe << std::endl; 

}

double lowest_student(Student array[], int n){

  double t = array[0].average;
  int k = 0;

  for(int i = 0; i < n; i++){
    if( t > array[i].average){
      t = array[i].average;
      k = i;
    }
  }

  return k; 
}

void print_lowest(Student array[], int n, int low){

  std:: cout << "The student with the lowest mark is " << array[low].surname << std::endl;
  std:: cout << "Student id: " << array[low].sid << std::endl;
  std:: cout << "Student average " << array[low].average << std::endl;

}

double highest_student(Student array[], int n){

  double x = 0;
  int h;
  bool loop = false;
  int i = 0;

  do{

    if(array[i].average > x){
      x = array[i].average;
      h = i;
    }

    if(i < n){
      loop = false;
    }
    else loop = true;

    i++;

  } while(loop == false);

  return h; 
}

void print_highest(Student array[], int n, int high){

  std:: cout << "The student with the highest mark is " << array[high].surname << std::endl;
  std:: cout << "Student id: " << array[high].sid << std::endl;
  std:: cout << "Student average " << array[high].average << std::endl;

}

int count_lines() {
  // create an input file stream
  std::ifstream input;
  // use it to open a file named 'MOCK_DATA.csv'
  input.open("MOCK_DATA.csv");
  // check if the file is not open
  if (!input.is_open()) {
    // print error message and quit if a problem occurred
    std::cerr << "Error! No input file found!\n";
    exit(1);
  }
  int n = 0;
  std::string dummy;
  // keep reading lines in file until no lines left to read
  // read into dummy string and increment count
  while (getline(input, dummy)) {
    n++;
  }
  return n;
}

void read_into_array(Student array[], int n) {
  // create an input file stream
  std::ifstream input;
  // use it to open a file named 'MOCK_DATA.csv'
  input.open("MOCK_DATA.csv");
  // check if the file is not open
  if (!input.is_open()) {
    // print error message and quit if a problem occurred
    std::cerr << "Error! No input file found!\n";
    exit(1);
  }
  std::string dummy;
  // loop through each line in file
  for (int i = 0; i < n; i++) {
    getline(input, dummy, ',');  // read until first comma
    array[i].surname = dummy;    // write to array
    getline(input, dummy, ',');  // read until next comma
    array[i].sid = std::stoi(dummy);
    getline(input, dummy, ',');  // read until next comma
    array[i].test1 = std::stoi(dummy);
    getline(input, dummy, ',');  // read until next comma
    array[i].test2 = std::stoi(dummy);
    getline(input, dummy, ',');  // read until next comma
    array[i].test3 = std::stoi(dummy);
    getline(input, dummy);  // for the n-2 element, read until
    // end of line (default)
    array[i].test4 = std::stoi(dummy);

    // call a function that would return the average
    // and store into last element
    array[i].average = averagemark(array, n);
  }
}

double averagemark(Student array[], int n){
  //input file stream
  std::ifstream input;
  input.open("MOCK_DATA.csv");

  if(!input.is_open()){
    std::cerr << "ERROR WITH OPEN FILE";
    exit(1);
  }
  
  //loop through each line and get average mark 
  for(int i = 0; i < n; i++){
    int x = ((array[i].test4 + array[i].test3 + array[i].test2 + array[i].test1) / 4);
    array[i].average = x;
  }
}

void print_array(const Student array[], int n) {
  // just loop through array and print to terminal
  for (int i = 0; i < n; i++) {
    std::cout << array[i].surname << " | " << array[i].sid << " | "
              << array[i].test1 << " | " << array[i].test2 << " | "
              << array[i].test3 << " | " << array[i].test4 << " | "
              << array[i].average << std::endl;
  }
}