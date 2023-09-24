#include <iostream>
#incude "ValueGenerator.h"

int main()
{
    ValueGenerator<unsigned long> UL;
    ValueGenerator<long long> LL;
    ValueGenerator<char> CH;
  
    long int it = 0;
    for (UL.Reset(); UL.CurVal() < UL.MaxVal(); UL.NextVal())
    {
        ++it;
        std::cout << "UL Iter : " << it << " | Num : " << aUL.CurVal() << std::endl;
    }
    for (LL.Reset(); LL.CurVal() < LL.MaxVal(); LL.NextVal())
    {
      ++it;
      std::cout << "LL Iter : " << it << " | Num : " << LL.CurVal() << std::endl;
    }
    return 0;
}
