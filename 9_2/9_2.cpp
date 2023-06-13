#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	void cut_frac(int& numerator_, int& denominator_) {
		int num = 0;
		if (numerator_ < 0)
		{
			numerator_ *= -1;
			num++;
		}
		int nod = NOD(numerator_, denominator_);  

		numerator_ /= nod;
		denominator_ /= nod;
		if (num) numerator_ *= -1;
	}
	int NOD(int numerator_, int denominator_) { 
		while (numerator_ > 0 && denominator_ > 0) {
			if (numerator_ > denominator_) {
				numerator_ %= denominator_;
			}
			else {
				denominator_ %= numerator_;
			}
		}

		return numerator_ + denominator_;
	}
public:
	friend std::ostream& operator<<(std::ostream& os, const Fraction a)
	{
		os << a.numerator_ << "/" << a.denominator_;
		return os;
	}
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction operator+ (Fraction other) 
	{ 
		return Fraction(numerator_ * other.denominator_ + denominator_ * other.numerator_, denominator_ * other.denominator_); 
	}
	Fraction operator- (Fraction other) 
	{ 
		return Fraction(numerator_, denominator_) + Fraction(-other.numerator_, other.denominator_); 
	}
	Fraction operator* (Fraction other) 
	{ 
		return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_); 
	}
	Fraction operator/ (Fraction other) 
	{ 
		return Fraction(numerator_, denominator_) * Fraction(other.denominator_, other.numerator_); 
	}
	Fraction& operator++ () 
	{ 
		numerator_ += denominator_; 
		return *this; 
	}
	Fraction operator++ (int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator--() 
	{ 
		numerator_-= denominator_;
		return *this; 
	}
	Fraction operator--(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	

	void Print() {
		cut_frac(numerator_, denominator_);
		std::cout << numerator_ << (denominator_ < 0 ? "" : "/") << denominator_ << "\n";
	}
	
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, d;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> b;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> c;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> d;
	Fraction f1(a, b);
	Fraction f2(c, d);
	std::cout << f1 << " + " << f2 << " = ";
	Fraction sum_f_f = f1 + f2;
	sum_f_f.Print();
	std::cout << f1 << " - " << f2 << " = ";
	Fraction sub_f_f = f1 - f2;
	sub_f_f.Print();
	std::cout << f1 << " * " << f2 << " = ";
	Fraction multi_f_f = f1 * f2;
	multi_f_f.Print();
	std::cout << f1 << " / " << f2 << " = ";
	Fraction div_f_f = f1 / f2;
	div_f_f.Print();
	std::cout << "++" << f1 << " * " << f2 << " = ";
	Fraction sum_pre = ++f1 * f2;
	sum_pre.Print();
	std::cout << "Значение дроби 1 = " << f1 << std::endl;
	std::cout << f1 << "--" << " * " << f2 << " = ";
	Fraction sub_post = f1-- * f2;
	sub_post.Print();
	std::cout << "Значение дроби 1 = " << f1 << std::endl;
	return 0;
}