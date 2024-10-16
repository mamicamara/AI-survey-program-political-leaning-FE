#include <iostream>
#include <vector>
using namespace std;

class Response {
private:
	string response;

public:
	Response( string r) {
		response = r;
	}
	string getResponse() {
		return response;
	}
};
class Question {
private:
	
	string question;
	Response* answers[4];
	
public:
	Question(string q, string a1, string a2, string a3, string a4) {
		question = q;
		answers[0] = new Response(a1);
		answers[1] = new Response(a2);
		answers[2] = new Response(a3);
		answers[3] = new Response(a4);
	}
	int ask() {
		int response;
		cout << question << endl;
		for (int i = 0; i < 4; i++) {
			cout << (i + 1) << ". " << answers[i]->getResponse() << endl;
		}
		cout << "Enter choice: ";
		cin >> response;
		return response;
	}

};


class Survey {	
public:
	vector<Question*> questions;

	void take() {
		for (int i = 0; i < questions.size(); i++) {
			questions[i]->ask();
		}
		cout << "What is your political party: " << endl;
		string party;
		cin >> party;
		cout << "Thank you. Your response was recorded" << endl;
	}

	void addQuestion(Question* q) {
		questions.push_back(q);
	}
};

int main() {
	Question* q1 = new Question(
		"What should the government do to help the poor ?",
		"Make it easier to apply for assistance.",
		"Allow parents to use education funds for charter schools.",
		"Create welfare to work programs.",
		"Nothing"

	);

	Question* q2 = new Question(
		"What should the government do to help the poor ?",
		"Make it easier to apply for assistance.",
		"Allow parents to use education funds for charter schools.",
		"Create welfare to work programs.",
		"Nothing"

	);

	Question* q3 = new Question(
		"What should the government do to help the poor ?",
		"Make it easier to apply for assistance.",
		"Allow parents to use education funds for charter schools.",
		"Create welfare to work programs.",
		"Nothing"

	);
	

	Survey *survey = new Survey();
	survey->addQuestion(q1);
	survey->addQuestion(q2);
	survey->addQuestion(q3);

	survey->take();

	return 0;
}