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
sizeof int, long, float, long long, double : 4,8,4,8,8
Correct? limit_time : 60
sizeof : 4
saved value (secure) : 301414822
Correct? main_fps (50.20) : 50.2
sizeof : 4
saved value (secure) : 1.64891e+12
*GetSavedValue() :1.64891e+12
Correct? monster_hp (-1090) : -1090
sizeof : 4
saved value (secure) : -259338143
Correct? monster_hp (-1090 - 2948) : -4038
sizeof : 4
saved value (secure) : -259335195
Correct? move_speed (20.33) : 20.33
sizeof : 4
saved value (secure) : 1.80801e+09
Correct? move_speed (20.33+10) : 30.33
sizeof : 4
saved value (secure) : 1.13692e+09
2 byte, 8byte test 
Correct? move (3) : 3
sizeof : 2
saved value (secure) : 11228
*GetSavedValue() :11228
Correct? move_speed (3+5) : 8
sizeof : 2
saved value (secure) : 11223
Correct? speed (1.2E-308) : 1.2e-308
sizeof : 8
saved value (secure) : 3.31263e+306
Correct? speed (1.2E-308 + 0.1E-308) : 1.3e-308
sizeof : 8
saved value (secure) : 3.36203e+306


```

