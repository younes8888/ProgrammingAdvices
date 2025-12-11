#include <iostream>

int MySum(int a, int b)
{
  int s = 0;
  s = a + b;
  return s;
}

int main()
{
  int arr1[5] = {200, 100, 50, 25, 30};
  int a, b, c;

  a = 10;
  b = 20;
  a++;
  ++b;
  c = a + b;

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  for (int i = 1; i <= 5; i++)
  {
    std::cout << i << std::endl;
    a = a + a * i;
  }
  c = MySum(a, b);

  std::cout << c;
  return 0;
}