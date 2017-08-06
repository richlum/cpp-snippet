#include <iostream>

class Fraction{
  private:
    int m_numerator;
    int m_denominator;
  public:
    Fraction(int numerator=0,int denominator=1):
      m_numerator(numerator), m_denominator(denominator){

      }
    // friend grants access to private members of this class 
    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1){
      out << f1.m_numerator << "/" << f1.m_denominator;
      return out;
    }
};

int main(int argc, char** argv){
  Fraction &&rref = Fraction(3,5);
  std::cout << rref << std::endl;
  return 0;
}