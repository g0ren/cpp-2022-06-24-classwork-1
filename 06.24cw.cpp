#include <iostream>
using namespace std;

class TextAbstract {
public:
	virtual string write()=0;
	virtual ~TextAbstract() {
	}
};

class SimpleText: public TextAbstract {
	string text;
public:
	SimpleText(string text) {
		this->text = text;
	}
	string write() override {
		return this->text;
	}
};

class DecoratedText: public TextAbstract {
protected:
	TextAbstract *atext;
public:
	DecoratedText(TextAbstract *atext) {
		this->atext = atext;
	}
	virtual string write()=0;
};

class Italic: public DecoratedText {
public:
	Italic(TextAbstract *atext) :
			DecoratedText(atext) {
	}
	string write() override {
		return "<i>" + this->atext->write() + "</i>";
	}
};

class Bold: public DecoratedText {
public:
	Bold(TextAbstract *atext) :
			DecoratedText(atext) {
	}
	string write() override {
		return "<b>" + this->atext->write() + "</b>";
	}
};

int main() {
	cout << Italic(new Bold(new SimpleText("Hello, world!"))).write() << endl;
	return 0;
}
