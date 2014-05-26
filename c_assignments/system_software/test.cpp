#include<iostream>
#include<sstream>
#include<string>
#include<cassert>
using namespace std;

class Fraction {
public:
	int numerator, denominator;
	Fraction();
	Fraction(string constant);
	string toString();
	void parse(string in);
	void add(Fraction rightOperand);
	//void subtract(Fraction rightOperand);
	~Fraction();
};

//con/des
Fraction::Fraction(string x) {
	parse(x);
}	//constructor
Fraction::Fraction() {
	printf("constructing\n"); numerator=0; denominator=0;
}	//constructor
Fraction::~Fraction() {
	printf("destructing\n");
}	//deconstructor

//methods
void Fraction::add(Fraction r) {
	assert(r.denominator==denominator); //too lazy to implement least common multiple function for mixed fractions yet
	numerator+=r.numerator;
}
string Fraction::toString() {
	ostringstream s;
	s<<numerator<<"/"<<denominator;
	return s.str();
}
void Fraction::parse(string in) {
	istringstream i(in,istringstream::in);
	char c;
	i>>numerator>>c>>denominator;
	assert(c=='/');
}

//test cases
int main(int argc, char *argv[]) {
	Fraction x;
	string f=x.toString();
	cout<<f<<endl;
	x.parse("5/6");
	cout<<x.toString()<<endl;
	Fraction temp("3/6");
	x.add(temp);
	cout<<x.toString()<<endl;
	getchar(); return 0;
}