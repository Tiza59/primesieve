/// @example cancel_callback.cpp
/// Cancel callback of primes by throwing a cancel_callback()
/// exception. Note that multi-threaded callback can currently not
/// be canceled.

#include <primesieve.hpp>
#include <stdint.h>
#include <iostream>

int i = 0;

void callback(uint64_t prime)
{
  if (++i == 1000000)
  {
    std::cout << "10^6th prime = " << prime << std::endl;
    throw cancel_callback();
  }
}

int main()
{
  try
  {
    primesieve::callback_primes(0, 1000000000, callback);
  }
  catch (cancel_callback&) { }
  return 0;
}
