#pragma once

#define ANSWER_00 <functional>

#define ANSWER_10 std::function
#define ANSWER_11 bool
#define ANSWER_12 T&
#define ANSWER_13 T
#define ANSWER_14 void

#define ANSWER_20 [&value](int a) { return a < value; }
#define ANSWER_21 [](std::string& str) { str += " " + str;}
#define ANSWER_22 []() { static unsigned int c = 0u; return c++;}
// OU ALORS avec mutable [c = 0u] () mutable { return c++; }
// mutable pour pouvoir modifier les valeurs capturé par valeur