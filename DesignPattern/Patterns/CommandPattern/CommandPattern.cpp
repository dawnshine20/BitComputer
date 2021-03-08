#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 요구사항, 요청사항을 객체로 캡슐화하여 다양한 종류를 넣을 수 있다.
// 또한 작업취소(undo)기능도 가능하다.
class Command {
public:
	virtual void execute(void) = 0;
	virtual ~Command(void) {};
};
//재료 추가 명령
class Ingredient : public Command {
public:
	Ingredient(string amount, string ingredient) {
		_ingredient = ingredient;
		_amount = amount;
	}
	void execute(void) {
		cout << " *Add " << _amount << " of " << _ingredient << endl;
	}
	~Ingredient(void)
	{
		delete(this);
	};
private:
	string _ingredient;
	string _amount;
};
//요리 명령
class Step : public Command {
public:
	Step(string action, string time) {
		_action = action;
		_time = time;
	}
	void execute(void) {
		cout << " *" << _action << " for " << _time << endl;
	}
	~Step(void)
	{
		delete(this);
	};
private:
	string _time;
	string _action;
};
class CmdStack {
public:
	void add(Command* c) {
		commands.push_back(c);
	}
	void createRecipe(void) {
		for (vector<Command*>::size_type x = 0; x < commands.size(); x++) {
			commands[x]->execute();
		}
	}
	void undo(void) {
		if (commands.size() >= 1)
			commands.pop_back();
		else
			cout << "Can't undo" << endl;
	}
private:
	vector<Command*> commands;
};
int main(void) {
	CmdStack list;
	//Create ingredients	
	Ingredient* first = new Ingredient("2 tablespoons", "vegetable oil");
	Ingredient* second = new Ingredient("3 cups", "rice");
	Ingredient* third = new Ingredient("1 bottle", "Ketchup");
	Ingredient* fourth = new Ingredient("4 ounces", "peas");
	Ingredient* fifth = new Ingredient("1 teaspoon", "soy sauce");
	//Create Step
	Step* step = new Step("Stir-fry", "3-4 minutes");
	//Create Recipe
	cout << "Recipe for simple Fried Rice" << endl;
	printf("\n");
	list.add(first);
	list.add(second);
	list.add(step);
	list.add(third);
	list.undo();
	list.add(fourth);
	list.add(fifth);
	list.createRecipe();
	cout << "Enjoy!" << endl;
	return 0;
}