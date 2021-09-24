#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define NUMBER_OF_QUESTION 3

struct answer {
  string name;
  bool isTrue;
};

struct question {
  string title;
  answer answers[3];
};
struct paper {
  string subjectsName;
  question questions[NUMBER_OF_QUESTION];
};

void validateUserChoice(int, int &);
void makeQuation(paper &, int, string, string, bool, string, bool, string,
                 bool);

int main() {
  paper p;
  p.subjectsName = "common test";
  cout << "\n$$$$$$$$$$$$" << p.subjectsName << "$$$$$$$$$$$$\n" << endl;

  makeQuation(p, 1, "bigest animal in the earth", "camel", false, "elephant",
              true, "cat", false);
  makeQuation(p, 2, "what is a not a os", "linux", false, "windows", false,
              "vs code", true);
  makeQuation(p, 3, "what is a not a programming language", "css", true, "java",
              false, "c++", false);

  for (int i = 0; i < NUMBER_OF_QUESTION; i++) {
    int userChoice;
    int corectAnswer;

    cout << i + 1 << "." << p.questions[i].title << endl;

    for (int j = 0; j < 3; j++) {
      cout << "     " << j + 1 << ". ";
      cout << p.questions[i].answers[j].name << endl;
      if (p.questions[i].answers[j].isTrue) {
        corectAnswer = j;
      }
    };
    validateUserChoice(3,
                       userChoice);  // get input and set value to
                                     // userChoice variable(as a reference)

    // --------------------------------------print_result_section---------------------------
    if (userChoice == (corectAnswer + 1)) {
      cout << "########################" << endl;
      cout << "your answer is corect" << endl;
      cout << "######################## \n" << endl;
    } else {
      cout << "########################" << endl;
      cout << "your answer is false" << endl;
      cout << "correct answer is " << p.questions[i].answers[corectAnswer].name
           << endl;
      cout << "######################## \n" << endl;
    }
    // --------------------------------------end_of_print_result_section---------------------------
  };
};

void validateUserChoice(int maxOfRange, int &userChoice) {
  while (true) {
    cout << "\n enter your choice := ";
    cin >> userChoice;
    if (userChoice > 0 && userChoice <= maxOfRange) break;
    cout << "\n (Enter Valid Input)" << endl;
  }
}

void makeQuation(paper &p, int questionNumber, string title, string answer1,
                 bool is1true, string answer2, bool is2true, string answer3,
                 bool is3true) {
  p.questions[questionNumber - 1].title = title;
  p.questions[questionNumber - 1].answers[0].name = answer1;
  p.questions[questionNumber - 1].answers[0].isTrue = is1true;
  p.questions[questionNumber - 1].answers[1].name = answer2;
  p.questions[questionNumber - 1].answers[1].isTrue = is2true;
  p.questions[questionNumber - 1].answers[2].name = answer3;
  p.questions[questionNumber - 1].answers[2].isTrue = is3true;
}