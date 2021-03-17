# SecureValue
SecureValue is designed against memory modification cheat tool such as GameCIH, GameKiller, GameGuardian
By applying simple variable template, you may help your application safe 

## Features
* Anti casual game cheat tools such as GameCIH, GameKiller, GameGuardian, ... 
* Code-level protection with 100% confirmed method   
* Easy to apply, just change your variables to SecureVariable<T> or SecureFixed<T> 

## Download  
```
git clone git@github.com:truefinder/securevalue.git 
```

## How to apply 
Just include two headers to your source code
```
	#include "SecureVariable.h" 
	#include "SecureFixed.h" 
```
 
### For changing values
SecureVariable is for changing values for example, HP, MP, speed, level, money, ... 
these are often changing its values, 
In this case, just apply SecureVariable 
```
	// before 
	int hp ; 
	hp = hp + 150 ; 
	
	// apply 
	SecureVariable<int> hp ; 
	hp = hp + 150 ; 
```
### For fixed values 
SecureFixed is for fixed values, like Game speed (frame per second), Stage limit time, Boss Health point, ... 
theae are often observed as fixed variables 
In this case, you are recommended to apply SecureFixed 
```
	// before 
	float fps = 80.0 ; 
	int time_limit = 3600 ;

	// apply
	SecureFixed<float> fps = 80.0; 
	SecureFixed<int> time_limit = 3600 ; 
```

## Test 
```
$ make
g++ -o main main.cpp -D_DEBUG_
$ ./main
*size of each short, int, long, float, long long, double : 2,4,8,4,8,8
<unsigned int>=======================================================
limit_time : 60
typeinfo : j, sizeof : 4
saved value (secure) : 301414822
<float>=======================================================
main_fps (50.20) : 50.2
typeinfo : f, sizeof : 4
saved value (secure) : 1.64891e+12
<int>=======================================================
monster_hp (11090) : 11090
typeinfo : i, sizeof : 4
saved value (secure) : 297365035
<int> calculation=======================================================
monster_hp (11090 - 2948) : 8142
typeinfo : i, sizeof : 4
saved value (secure) : 297360055
<float>=======================================================
move_speed (20.33) : 20.33
typeinfo : f, sizeof : 4
saved value (secure) : 1.04623e+10
<float> calculation =======================================================
move_speed (20.33+10) : 30.33
typeinfo : f, sizeof : 4
saved value (secure) : 1.36836e+10
<short>=======================================================
move (3) : 3
typeinfo : s, sizeof : 2
saved value (secure) : 17786
<short> calculation =======================================================
move_speed (3+5) : 8
typeinfo : s, sizeof : 2
saved value (secure) : 17777
<double>=======================================================
speed (1.2E-308) : 1.2e-308
typeinfo : d, sizeof : 8
saved value (secure) : 3.31263e+306
<double> calculation =======================================================
speed (1.2E-308 + 0.1E-308) : 1.3e-308
typeinfo : d, sizeof : 8
saved value (secure) : 3.36203e+306


```

