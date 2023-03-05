#include <iostream>
#include <string>
#include <bitset>

unsigned int gray_encode(unsigned int const num){
  return num ^ (num>>1);
}

unsigned int gray_decode(unsigned int gray){
  for (unsigned int bit=1U<<31; bit > 1; bit>>=1 ) {
    if (gray&bit) {
      gray ^=bit<<1;
    
    } 
  }
  return gray;
}

std::string go_binary(unsigned int value, int const digits){
  return std::bitset<32>(value).to_string().substr(32-digits,digits);
}



int main (int argc, char *argv[])
{
  std::cout<<"Number\tBinary\tGray\tDecode\n";
  std::cout<<"------\t------\t----\t------\n";
  for (unsigned int n = 0; n<32; ++n) {
    auto encg = gray_encode(n);
    auto decg = gray_decode(encg);
    std::cout<<n<<"\t"<<go_binary(n, 5)<<"\t"<<go_binary(encg, 5)<<"\t"<<decg<<"\n";
  
  }
  
  return 0;
}
