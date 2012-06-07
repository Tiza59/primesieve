//
// Copyright (c) 2012 Kim Walisch, <kim.walisch@gmail.com>.
// All rights reserved.
//
// This file is part of primesieve.
// Homepage: http://primesieve.googlecode.com
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above
//     copyright notice, this list of conditions and the following
//     disclaimer in the documentation and/or other materials provided
//     with the distribution.
//   * Neither the name of the author nor the names of its
//     contributors may be used to endorse or promote products derived
//     from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.


/// @file WheelFactorization.cpp
/// @brief Contains precomputed arrays needed for wheel factorization.
/// Wheel factorization is used to skip multiples of small primes to
/// speed up the sieve of Eratosthenes.
/// http://en.wikipedia.org/wiki/Wheel_factorization

#include "WheelFactorization.h"
#include "bits.h"

namespace soe {

/// @see WheelInit in WheelFactorization.h

const WheelInit wheel30Init[30] = {
  {1,  0}, {0,  0}, {5,  1}, {4,  1}, {3,  1}, {2,  1}, {1,  1}, {0,  1},
  {3,  2}, {2,  2}, {1,  2}, {0,  2}, {1,  3}, {0,  3}, {3,  4}, {2,  4},
  {1,  4}, {0,  4}, {1,  5}, {0,  5}, {3,  6}, {2,  6}, {1,  6}, {0,  6},
  {5,  7}, {4,  7}, {3,  7}, {2,  7}, {1,  7}, {0,  7} };

const WheelInit wheel210Init[210] = {
  {1,  0}, {0,  0}, {9,  1}, {8,  1}, {7,  1}, {6,  1}, {5,  1}, {4,  1},
  {3,  1}, {2,  1}, {1,  1}, {0,  1}, {1,  2}, {0,  2}, {3,  3}, {2,  3},
  {1,  3}, {0,  3}, {1,  4}, {0,  4}, {3,  5}, {2,  5}, {1,  5}, {0,  5},
  {5,  6}, {4,  6}, {3,  6}, {2,  6}, {1,  6}, {0,  6}, {1,  7}, {0,  7},
  {5,  8}, {4,  8}, {3,  8}, {2,  8}, {1,  8}, {0,  8}, {3,  9}, {2,  9},
  {1,  9}, {0,  9}, {1, 10}, {0, 10}, {3, 11}, {2, 11}, {1, 11}, {0, 11},
  {5, 12}, {4, 12}, {3, 12}, {2, 12}, {1, 12}, {0, 12}, {5, 13}, {4, 13},
  {3, 13}, {2, 13}, {1, 13}, {0, 13}, {1, 14}, {0, 14}, {5, 15}, {4, 15},
  {3, 15}, {2, 15}, {1, 15}, {0, 15}, {3, 16}, {2, 16}, {1, 16}, {0, 16},
  {1, 17}, {0, 17}, {5, 18}, {4, 18}, {3, 18}, {2, 18}, {1, 18}, {0, 18},
  {3, 19}, {2, 19}, {1, 19}, {0, 19}, {5, 20}, {4, 20}, {3, 20}, {2, 20},
  {1, 20}, {0, 20}, {7, 21}, {6, 21}, {5, 21}, {4, 21}, {3, 21}, {2, 21},
  {1, 21}, {0, 21}, {3, 22}, {2, 22}, {1, 22}, {0, 22}, {1, 23}, {0, 23},
  {3, 24}, {2, 24}, {1, 24}, {0, 24}, {1, 25}, {0, 25}, {3, 26}, {2, 26},
  {1, 26}, {0, 26}, {7, 27}, {6, 27}, {5, 27}, {4, 27}, {3, 27}, {2, 27},
  {1, 27}, {0, 27}, {5, 28}, {4, 28}, {3, 28}, {2, 28}, {1, 28}, {0, 28},
  {3, 29}, {2, 29}, {1, 29}, {0, 29}, {5, 30}, {4, 30}, {3, 30}, {2, 30},
  {1, 30}, {0, 30}, {1, 31}, {0, 31}, {3, 32}, {2, 32}, {1, 32}, {0, 32},
  {5, 33}, {4, 33}, {3, 33}, {2, 33}, {1, 33}, {0, 33}, {1, 34}, {0, 34},
  {5, 35}, {4, 35}, {3, 35}, {2, 35}, {1, 35}, {0, 35}, {5, 36}, {4, 36},
  {3, 36}, {2, 36}, {1, 36}, {0, 36}, {3, 37}, {2, 37}, {1, 37}, {0, 37},
  {1, 38}, {0, 38}, {3, 39}, {2, 39}, {1, 39}, {0, 39}, {5, 40}, {4, 40},
  {3, 40}, {2, 40}, {1, 40}, {0, 40}, {1, 41}, {0, 41}, {5, 42}, {4, 42},
  {3, 42}, {2, 42}, {1, 42}, {0, 42}, {3, 43}, {2, 43}, {1, 43}, {0, 43},
  {1, 44}, {0, 44}, {3, 45}, {2, 45}, {1, 45}, {0, 45}, {1, 46}, {0, 46},
  {9, 47}, {8, 47}, {7, 47}, {6, 47}, {5, 47}, {4, 47}, {3, 47}, {2, 47},
  {1, 47}, {0, 47}, };

/// The wheel30 and wheel210 arrays contain 8 wheels, one for each
/// modulo 30 residue class of sieving primes ( k = { 7, 11, 13, 17,
/// 19, 23, 29, 1 } ), e.g. the wheel related to k = 13 is:
/// index of 13 = 2 -> wheel[8 * 2] to wheel[8 * 2 + SIZE - 1]
/// @see WheelElement in WheelFactorization.h

const WheelElement wheel30[8*8] = {
  WheelElement(BIT0, 6, 1, 1), WheelElement(BIT4, 4, 1, 1), WheelElement(BIT3, 2, 0, 1),
  WheelElement(BIT7, 4, 1, 1), WheelElement(BIT6, 2, 1, 1), WheelElement(BIT2, 4, 1, 1),
  WheelElement(BIT1, 6, 1, 1), WheelElement(BIT5, 2, 1,-7), WheelElement(BIT1, 6, 2, 1),
  WheelElement(BIT3, 4, 1, 1), WheelElement(BIT7, 2, 1, 1), WheelElement(BIT5, 4, 2, 1),
  WheelElement(BIT0, 2, 0, 1), WheelElement(BIT6, 4, 2, 1), WheelElement(BIT2, 6, 2, 1),
  WheelElement(BIT4, 2, 1,-7), WheelElement(BIT2, 6, 2, 1), WheelElement(BIT7, 4, 2, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT4, 4, 2, 1), WheelElement(BIT1, 2, 1, 1),
  WheelElement(BIT0, 4, 1, 1), WheelElement(BIT6, 6, 3, 1), WheelElement(BIT3, 2, 1,-7),
  WheelElement(BIT3, 6, 3, 1), WheelElement(BIT6, 4, 3, 1), WheelElement(BIT0, 2, 1, 1),
  WheelElement(BIT1, 4, 2, 1), WheelElement(BIT4, 2, 1, 1), WheelElement(BIT5, 4, 2, 1),
  WheelElement(BIT7, 6, 4, 1), WheelElement(BIT2, 2, 1,-7), WheelElement(BIT4, 6, 4, 1),
  WheelElement(BIT2, 4, 2, 1), WheelElement(BIT6, 2, 2, 1), WheelElement(BIT0, 4, 2, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT7, 4, 3, 1), WheelElement(BIT3, 6, 4, 1),
  WheelElement(BIT1, 2, 1,-7), WheelElement(BIT5, 6, 5, 1), WheelElement(BIT1, 4, 3, 1),
  WheelElement(BIT2, 2, 1, 1), WheelElement(BIT6, 4, 3, 1), WheelElement(BIT7, 2, 2, 1),
  WheelElement(BIT3, 4, 3, 1), WheelElement(BIT4, 6, 5, 1), WheelElement(BIT0, 2, 1,-7),
  WheelElement(BIT6, 6, 6, 1), WheelElement(BIT5, 4, 4, 1), WheelElement(BIT4, 2, 2, 1),
  WheelElement(BIT3, 4, 4, 1), WheelElement(BIT2, 2, 2, 1), WheelElement(BIT1, 4, 4, 1),
  WheelElement(BIT0, 6, 5, 1), WheelElement(BIT7, 2, 2,-7), WheelElement(BIT7, 6, 1, 1),
  WheelElement(BIT0, 4, 0, 1), WheelElement(BIT1, 2, 0, 1), WheelElement(BIT2, 4, 0, 1),
  WheelElement(BIT3, 2, 0, 1), WheelElement(BIT4, 4, 0, 1), WheelElement(BIT5, 6, 0, 1),
  WheelElement(BIT6, 2, 0,-7) };

const WheelElement wheel210[48*8] = {
  WheelElement(BIT0,10, 2, 1), WheelElement(BIT3, 2, 0, 1), WheelElement(BIT7, 4, 1, 1),
  WheelElement(BIT6, 2, 1, 1), WheelElement(BIT2, 4, 1, 1), WheelElement(BIT1, 6, 1, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT0, 6, 1, 1), WheelElement(BIT4, 4, 1, 1),
  WheelElement(BIT3, 2, 0, 1), WheelElement(BIT7, 4, 1, 1), WheelElement(BIT6, 6, 2, 1),
  WheelElement(BIT1, 6, 1, 1), WheelElement(BIT5, 2, 1, 1), WheelElement(BIT0, 6, 1, 1),
  WheelElement(BIT4, 4, 1, 1), WheelElement(BIT3, 2, 0, 1), WheelElement(BIT7, 6, 2, 1),
  WheelElement(BIT2, 4, 1, 1), WheelElement(BIT1, 6, 1, 1), WheelElement(BIT5, 8, 2, 1),
  WheelElement(BIT4, 4, 1, 1), WheelElement(BIT3, 2, 0, 1), WheelElement(BIT7, 4, 1, 1),
  WheelElement(BIT6, 2, 1, 1), WheelElement(BIT2, 4, 1, 1), WheelElement(BIT1, 8, 2, 1),
  WheelElement(BIT0, 6, 1, 1), WheelElement(BIT4, 4, 1, 1), WheelElement(BIT3, 6, 1, 1),
  WheelElement(BIT6, 2, 1, 1), WheelElement(BIT2, 4, 1, 1), WheelElement(BIT1, 6, 1, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT0, 6, 1, 1), WheelElement(BIT4, 6, 1, 1),
  WheelElement(BIT7, 4, 1, 1), WheelElement(BIT6, 2, 1, 1), WheelElement(BIT2, 4, 1, 1),
  WheelElement(BIT1, 6, 1, 1), WheelElement(BIT5, 2, 1, 1), WheelElement(BIT0, 6, 1, 1),
  WheelElement(BIT4, 4, 1, 1), WheelElement(BIT3, 2, 0, 1), WheelElement(BIT7, 4, 1, 1),
  WheelElement(BIT6, 2, 1, 1), WheelElement(BIT2,10, 2, 1), WheelElement(BIT5, 2, 1,-47),
  WheelElement(BIT1,10, 3, 1), WheelElement(BIT7, 2, 1, 1), WheelElement(BIT5, 4, 2, 1),
  WheelElement(BIT0, 2, 0, 1), WheelElement(BIT6, 4, 2, 1), WheelElement(BIT2, 6, 2, 1),
  WheelElement(BIT4, 2, 1, 1), WheelElement(BIT1, 6, 2, 1), WheelElement(BIT3, 4, 1, 1),
  WheelElement(BIT7, 2, 1, 1), WheelElement(BIT5, 4, 2, 1), WheelElement(BIT0, 6, 2, 1),
  WheelElement(BIT2, 6, 2, 1), WheelElement(BIT4, 2, 1, 1), WheelElement(BIT1, 6, 2, 1),
  WheelElement(BIT3, 4, 1, 1), WheelElement(BIT7, 2, 1, 1), WheelElement(BIT5, 6, 2, 1),
  WheelElement(BIT6, 4, 2, 1), WheelElement(BIT2, 6, 2, 1), WheelElement(BIT4, 8, 3, 1),
  WheelElement(BIT3, 4, 1, 1), WheelElement(BIT7, 2, 1, 1), WheelElement(BIT5, 4, 2, 1),
  WheelElement(BIT0, 2, 0, 1), WheelElement(BIT6, 4, 2, 1), WheelElement(BIT2, 8, 3, 1),
  WheelElement(BIT1, 6, 2, 1), WheelElement(BIT3, 4, 1, 1), WheelElement(BIT7, 6, 3, 1),
  WheelElement(BIT0, 2, 0, 1), WheelElement(BIT6, 4, 2, 1), WheelElement(BIT2, 6, 2, 1),
  WheelElement(BIT4, 2, 1, 1), WheelElement(BIT1, 6, 2, 1), WheelElement(BIT3, 6, 2, 1),
  WheelElement(BIT5, 4, 2, 1), WheelElement(BIT0, 2, 0, 1), WheelElement(BIT6, 4, 2, 1),
  WheelElement(BIT2, 6, 2, 1), WheelElement(BIT4, 2, 1, 1), WheelElement(BIT1, 6, 2, 1),
  WheelElement(BIT3, 4, 1, 1), WheelElement(BIT7, 2, 1, 1), WheelElement(BIT5, 4, 2, 1),
  WheelElement(BIT0, 2, 0, 1), WheelElement(BIT6,10, 4, 1), WheelElement(BIT4, 2, 1,-47),
  WheelElement(BIT2,10, 4, 1), WheelElement(BIT5, 2, 1, 1), WheelElement(BIT4, 4, 2, 1),
  WheelElement(BIT1, 2, 1, 1), WheelElement(BIT0, 4, 1, 1), WheelElement(BIT6, 6, 3, 1),
  WheelElement(BIT3, 2, 1, 1), WheelElement(BIT2, 6, 2, 1), WheelElement(BIT7, 4, 2, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT4, 4, 2, 1), WheelElement(BIT1, 6, 2, 1),
  WheelElement(BIT6, 6, 3, 1), WheelElement(BIT3, 2, 1, 1), WheelElement(BIT2, 6, 2, 1),
  WheelElement(BIT7, 4, 2, 1), WheelElement(BIT5, 2, 1, 1), WheelElement(BIT4, 6, 3, 1),
  WheelElement(BIT0, 4, 1, 1), WheelElement(BIT6, 6, 3, 1), WheelElement(BIT3, 8, 3, 1),
  WheelElement(BIT7, 4, 2, 1), WheelElement(BIT5, 2, 1, 1), WheelElement(BIT4, 4, 2, 1),
  WheelElement(BIT1, 2, 1, 1), WheelElement(BIT0, 4, 1, 1), WheelElement(BIT6, 8, 4, 1),
  WheelElement(BIT2, 6, 2, 1), WheelElement(BIT7, 4, 2, 1), WheelElement(BIT5, 6, 3, 1),
  WheelElement(BIT1, 2, 1, 1), WheelElement(BIT0, 4, 1, 1), WheelElement(BIT6, 6, 3, 1),
  WheelElement(BIT3, 2, 1, 1), WheelElement(BIT2, 6, 2, 1), WheelElement(BIT7, 6, 3, 1),
  WheelElement(BIT4, 4, 2, 1), WheelElement(BIT1, 2, 1, 1), WheelElement(BIT0, 4, 1, 1),
  WheelElement(BIT6, 6, 3, 1), WheelElement(BIT3, 2, 1, 1), WheelElement(BIT2, 6, 2, 1),
  WheelElement(BIT7, 4, 2, 1), WheelElement(BIT5, 2, 1, 1), WheelElement(BIT4, 4, 2, 1),
  WheelElement(BIT1, 2, 1, 1), WheelElement(BIT0,10, 4, 1), WheelElement(BIT3, 2, 1,-47),
  WheelElement(BIT3,10, 6, 1), WheelElement(BIT0, 2, 1, 1), WheelElement(BIT1, 4, 2, 1),
  WheelElement(BIT4, 2, 1, 1), WheelElement(BIT5, 4, 2, 1), WheelElement(BIT7, 6, 4, 1),
  WheelElement(BIT2, 2, 1, 1), WheelElement(BIT3, 6, 3, 1), WheelElement(BIT6, 4, 3, 1),
  WheelElement(BIT0, 2, 1, 1), WheelElement(BIT1, 4, 2, 1), WheelElement(BIT4, 6, 3, 1),
  WheelElement(BIT7, 6, 4, 1), WheelElement(BIT2, 2, 1, 1), WheelElement(BIT3, 6, 3, 1),
  WheelElement(BIT6, 4, 3, 1), WheelElement(BIT0, 2, 1, 1), WheelElement(BIT1, 6, 3, 1),
  WheelElement(BIT5, 4, 2, 1), WheelElement(BIT7, 6, 4, 1), WheelElement(BIT2, 8, 4, 1),
  WheelElement(BIT6, 4, 3, 1), WheelElement(BIT0, 2, 1, 1), WheelElement(BIT1, 4, 2, 1),
  WheelElement(BIT4, 2, 1, 1), WheelElement(BIT5, 4, 2, 1), WheelElement(BIT7, 8, 5, 1),
  WheelElement(BIT3, 6, 3, 1), WheelElement(BIT6, 4, 3, 1), WheelElement(BIT0, 6, 3, 1),
  WheelElement(BIT4, 2, 1, 1), WheelElement(BIT5, 4, 2, 1), WheelElement(BIT7, 6, 4, 1),
  WheelElement(BIT2, 2, 1, 1), WheelElement(BIT3, 6, 3, 1), WheelElement(BIT6, 6, 4, 1),
  WheelElement(BIT1, 4, 2, 1), WheelElement(BIT4, 2, 1, 1), WheelElement(BIT5, 4, 2, 1),
  WheelElement(BIT7, 6, 4, 1), WheelElement(BIT2, 2, 1, 1), WheelElement(BIT3, 6, 3, 1),
  WheelElement(BIT6, 4, 3, 1), WheelElement(BIT0, 2, 1, 1), WheelElement(BIT1, 4, 2, 1),
  WheelElement(BIT4, 2, 1, 1), WheelElement(BIT5,10, 6, 1), WheelElement(BIT2, 2, 1,-47),
  WheelElement(BIT4,10, 6, 1), WheelElement(BIT6, 2, 2, 1), WheelElement(BIT0, 4, 2, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT7, 4, 3, 1), WheelElement(BIT3, 6, 4, 1),
  WheelElement(BIT1, 2, 1, 1), WheelElement(BIT4, 6, 4, 1), WheelElement(BIT2, 4, 2, 1),
  WheelElement(BIT6, 2, 2, 1), WheelElement(BIT0, 4, 2, 1), WheelElement(BIT5, 6, 4, 1),
  WheelElement(BIT3, 6, 4, 1), WheelElement(BIT1, 2, 1, 1), WheelElement(BIT4, 6, 4, 1),
  WheelElement(BIT2, 4, 2, 1), WheelElement(BIT6, 2, 2, 1), WheelElement(BIT0, 6, 3, 1),
  WheelElement(BIT7, 4, 3, 1), WheelElement(BIT3, 6, 4, 1), WheelElement(BIT1, 8, 5, 1),
  WheelElement(BIT2, 4, 2, 1), WheelElement(BIT6, 2, 2, 1), WheelElement(BIT0, 4, 2, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT7, 4, 3, 1), WheelElement(BIT3, 8, 5, 1),
  WheelElement(BIT4, 6, 4, 1), WheelElement(BIT2, 4, 2, 1), WheelElement(BIT6, 6, 4, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT7, 4, 3, 1), WheelElement(BIT3, 6, 4, 1),
  WheelElement(BIT1, 2, 1, 1), WheelElement(BIT4, 6, 4, 1), WheelElement(BIT2, 6, 4, 1),
  WheelElement(BIT0, 4, 2, 1), WheelElement(BIT5, 2, 1, 1), WheelElement(BIT7, 4, 3, 1),
  WheelElement(BIT3, 6, 4, 1), WheelElement(BIT1, 2, 1, 1), WheelElement(BIT4, 6, 4, 1),
  WheelElement(BIT2, 4, 2, 1), WheelElement(BIT6, 2, 2, 1), WheelElement(BIT0, 4, 2, 1),
  WheelElement(BIT5, 2, 1, 1), WheelElement(BIT7,10, 7, 1), WheelElement(BIT1, 2, 1,-47),
  WheelElement(BIT5,10, 8, 1), WheelElement(BIT2, 2, 1, 1), WheelElement(BIT6, 4, 3, 1),
  WheelElement(BIT7, 2, 2, 1), WheelElement(BIT3, 4, 3, 1), WheelElement(BIT4, 6, 5, 1),
  WheelElement(BIT0, 2, 1, 1), WheelElement(BIT5, 6, 5, 1), WheelElement(BIT1, 4, 3, 1),
  WheelElement(BIT2, 2, 1, 1), WheelElement(BIT6, 4, 3, 1), WheelElement(BIT7, 6, 5, 1),
  WheelElement(BIT4, 6, 5, 1), WheelElement(BIT0, 2, 1, 1), WheelElement(BIT5, 6, 5, 1),
  WheelElement(BIT1, 4, 3, 1), WheelElement(BIT2, 2, 1, 1), WheelElement(BIT6, 6, 5, 1),
  WheelElement(BIT3, 4, 3, 1), WheelElement(BIT4, 6, 5, 1), WheelElement(BIT0, 8, 6, 1),
  WheelElement(BIT1, 4, 3, 1), WheelElement(BIT2, 2, 1, 1), WheelElement(BIT6, 4, 3, 1),
  WheelElement(BIT7, 2, 2, 1), WheelElement(BIT3, 4, 3, 1), WheelElement(BIT4, 8, 6, 1),
  WheelElement(BIT5, 6, 5, 1), WheelElement(BIT1, 4, 3, 1), WheelElement(BIT2, 6, 4, 1),
  WheelElement(BIT7, 2, 2, 1), WheelElement(BIT3, 4, 3, 1), WheelElement(BIT4, 6, 5, 1),
  WheelElement(BIT0, 2, 1, 1), WheelElement(BIT5, 6, 5, 1), WheelElement(BIT1, 6, 4, 1),
  WheelElement(BIT6, 4, 3, 1), WheelElement(BIT7, 2, 2, 1), WheelElement(BIT3, 4, 3, 1),
  WheelElement(BIT4, 6, 5, 1), WheelElement(BIT0, 2, 1, 1), WheelElement(BIT5, 6, 5, 1),
  WheelElement(BIT1, 4, 3, 1), WheelElement(BIT2, 2, 1, 1), WheelElement(BIT6, 4, 3, 1),
  WheelElement(BIT7, 2, 2, 1), WheelElement(BIT3,10, 8, 1), WheelElement(BIT0, 2, 1,-47),
  WheelElement(BIT6,10,10, 1), WheelElement(BIT4, 2, 2, 1), WheelElement(BIT3, 4, 4, 1),
  WheelElement(BIT2, 2, 2, 1), WheelElement(BIT1, 4, 4, 1), WheelElement(BIT0, 6, 5, 1),
  WheelElement(BIT7, 2, 2, 1), WheelElement(BIT6, 6, 6, 1), WheelElement(BIT5, 4, 4, 1),
  WheelElement(BIT4, 2, 2, 1), WheelElement(BIT3, 4, 4, 1), WheelElement(BIT2, 6, 6, 1),
  WheelElement(BIT0, 6, 5, 1), WheelElement(BIT7, 2, 2, 1), WheelElement(BIT6, 6, 6, 1),
  WheelElement(BIT5, 4, 4, 1), WheelElement(BIT4, 2, 2, 1), WheelElement(BIT3, 6, 6, 1),
  WheelElement(BIT1, 4, 4, 1), WheelElement(BIT0, 6, 5, 1), WheelElement(BIT7, 8, 8, 1),
  WheelElement(BIT5, 4, 4, 1), WheelElement(BIT4, 2, 2, 1), WheelElement(BIT3, 4, 4, 1),
  WheelElement(BIT2, 2, 2, 1), WheelElement(BIT1, 4, 4, 1), WheelElement(BIT0, 8, 7, 1),
  WheelElement(BIT6, 6, 6, 1), WheelElement(BIT5, 4, 4, 1), WheelElement(BIT4, 6, 6, 1),
  WheelElement(BIT2, 2, 2, 1), WheelElement(BIT1, 4, 4, 1), WheelElement(BIT0, 6, 5, 1),
  WheelElement(BIT7, 2, 2, 1), WheelElement(BIT6, 6, 6, 1), WheelElement(BIT5, 6, 6, 1),
  WheelElement(BIT3, 4, 4, 1), WheelElement(BIT2, 2, 2, 1), WheelElement(BIT1, 4, 4, 1),
  WheelElement(BIT0, 6, 5, 1), WheelElement(BIT7, 2, 2, 1), WheelElement(BIT6, 6, 6, 1),
  WheelElement(BIT5, 4, 4, 1), WheelElement(BIT4, 2, 2, 1), WheelElement(BIT3, 4, 4, 1),
  WheelElement(BIT2, 2, 2, 1), WheelElement(BIT1,10, 9, 1), WheelElement(BIT7, 2, 2,-47),
  WheelElement(BIT7,10, 1, 1), WheelElement(BIT1, 2, 0, 1), WheelElement(BIT2, 4, 0, 1),
  WheelElement(BIT3, 2, 0, 1), WheelElement(BIT4, 4, 0, 1), WheelElement(BIT5, 6, 0, 1),
  WheelElement(BIT6, 2, 0, 1), WheelElement(BIT7, 6, 1, 1), WheelElement(BIT0, 4, 0, 1),
  WheelElement(BIT1, 2, 0, 1), WheelElement(BIT2, 4, 0, 1), WheelElement(BIT3, 6, 0, 1),
  WheelElement(BIT5, 6, 0, 1), WheelElement(BIT6, 2, 0, 1), WheelElement(BIT7, 6, 1, 1),
  WheelElement(BIT0, 4, 0, 1), WheelElement(BIT1, 2, 0, 1), WheelElement(BIT2, 6, 0, 1),
  WheelElement(BIT4, 4, 0, 1), WheelElement(BIT5, 6, 0, 1), WheelElement(BIT6, 8, 1, 1),
  WheelElement(BIT0, 4, 0, 1), WheelElement(BIT1, 2, 0, 1), WheelElement(BIT2, 4, 0, 1),
  WheelElement(BIT3, 2, 0, 1), WheelElement(BIT4, 4, 0, 1), WheelElement(BIT5, 8, 0, 1),
  WheelElement(BIT7, 6, 1, 1), WheelElement(BIT0, 4, 0, 1), WheelElement(BIT1, 6, 0, 1),
  WheelElement(BIT3, 2, 0, 1), WheelElement(BIT4, 4, 0, 1), WheelElement(BIT5, 6, 0, 1),
  WheelElement(BIT6, 2, 0, 1), WheelElement(BIT7, 6, 1, 1), WheelElement(BIT0, 6, 0, 1),
  WheelElement(BIT2, 4, 0, 1), WheelElement(BIT3, 2, 0, 1), WheelElement(BIT4, 4, 0, 1),
  WheelElement(BIT5, 6, 0, 1), WheelElement(BIT6, 2, 0, 1), WheelElement(BIT7, 6, 1, 1),
  WheelElement(BIT0, 4, 0, 1), WheelElement(BIT1, 2, 0, 1), WheelElement(BIT2, 4, 0, 1),
  WheelElement(BIT3, 2, 0, 1), WheelElement(BIT4,10, 0, 1), WheelElement(BIT6, 2, 0,-47) };

} // namespace soe
