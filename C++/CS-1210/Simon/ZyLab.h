// To setup the assignment to work in ZyLab - not modifiable by students
// Necessary to compile simon.cpp
// Provided by Cedarville University professors

#ifndef IN_ZYLAB
void system (std::string s) { system(s.c_str()); }
void sleep  (int i)         { sleep ((uint) i);  }
#else
void system (std::string s) {                    }
void sleep  (int i)         {                    }
#endif
