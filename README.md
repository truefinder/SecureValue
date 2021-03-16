# SecureValue
Let's protect our native app games from casual cheat tools 

## Purpose 
* Anti casual game cheat tools such as GameCIH, GameKiller, GameGuardian, ... 
* Code-level protection with 100% confirmed method   
* Easy to apply, just change your int to SecureVariable<int> or SecureFixed<int> 

## How to apply 
### updated value to SecureVariable
Heath point, Magic point, Speed, level, money, ... these are often variables, 
Then, apply SecureVariable 

	// before 
	int hp ; 
	hp = hp + 150 ; 
	
	// after (much safer)
	SecureVariable<int> hp ; 
	hp = hp + 150 ; 

### fixed value to SecureFixed 
Game speed (frame per second), Stage limit time, Boss Health point, ... are fixed variables ( not changed) 
In this case, you are recommended to apply SecureFixed 

	// before 
	float fps = 80.0 ; 
	int time_limit = 3600 ;

	// after
	SecureFixed<float> fps = 80.0; 
	SecureFixed<int> time_limit = 3600 ; 

###	Output 

	sizeof int, long, float, long long, double : 4,4,4,8,8
	Correct? limit_time : 60
	sizeof : 4
	saved value (secure) : 301414822
	Correct? main_fps (50.20) : 50.2
	sizeof : 4
	saved value (secure) : 1.64891e+12
	Correct? monster_hp (-1090) : -1090
	sizeof : 4
	saved value (secure) : -110801613
	Correct? monster_hp (-1090 - 2948) : -4038
	sizeof : 4
	saved value (secure) : -110803273
	Correct? move_speed (20.33) : 20.33
	sizeof : 4
	saved value (secure) : 47125.4
	Correct? move_speed (20.33+10) : 30.33
	sizeof : 4
	saved value (secure) : 59413.4
	2 byte, 8byte test
	Correct? move (3) : 3
	sizeof : 2
	saved value (secure) : -18802
	Correct? move_speed (3+5) : 8
	sizeof : 2
	saved value (secure) : -18811
	Correct? speed (1.2E-308) : 1.2e-308
	sizeof : 8
	saved value (secure) : 3.31263e+306
	Correct? speed (1.2E-308 + 0.1E-308) : 1.3e-308
	sizeof : 8
	saved value (secure) : 3.36203e+306

