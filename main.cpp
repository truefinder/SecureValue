
/**
  * Example for secure variable and fixed 
  * Its purpose is to protect native app games from casual hack with memory cheat app 
  * such as GameCHI, Game Hacker, GameKiller, GameGuardian, ... 
  *
  * to dear developer :  
  * 	hp, mp, speed, ... are variable value ( updating value ) 
  * 	-> apply SecureVariable
  *
  * 	fps, time-up, game clear condition are fixed value ( not updated ) 
  * 	-> apply SecureFixed 
  * 
  */

#include "SecureVariable.h" 
#include "SecureFixed.h" 

using namespace std ;

int main (void)
{

	// test fixed value 
	SecureFixed<unsigned int> limit_time ;
	SecureFixed<float> main_fps ; 

	// test variable value 
	SecureVariable<int> monster_hp ;
	SecureVariable<float> move_speed ; 


	cout<< "sizeof int, long, float, long long, double : "  ; 
	cout<< sizeof(int) << "," << sizeof(long) <<"," << sizeof(float) << "," << sizeof(long long) << "," << sizeof(double) << endl ; 

	limit_time = 60 ; 
	cout << "Correct? limit_time : " << limit_time << endl ;
	limit_time.DebugPrint(); 

	main_fps = 50.20 ; 
	cout << "Correct? main_fps (50.20) : " << main_fps << endl ; 
	main_fps.DebugPrint() ; 
	cout << "*GetSavedValue() :" << main_fps.GetSavedValue() << endl ; 

	monster_hp = -1090 ; 
	cout << "Correct? monster_hp (-1090) : " << monster_hp << endl ; 
	monster_hp.DebugPrint() ; 
	monster_hp = monster_hp - 2948 ; 
	cout << "Correct? monster_hp (-1090 - 2948) : " << monster_hp << endl ; 
	monster_hp.DebugPrint() ; 

	move_speed = 20.33 ;
	cout << "Correct? move_speed (20.33) : " << move_speed << endl ; 
	move_speed.DebugPrint() ; 
	move_speed = move_speed + 10  ; 
	cout << "Correct? move_speed (20.33+10) : " << move_speed << endl ; 
	move_speed.DebugPrint() ; 

	cout << "2 byte, 8byte test " << endl ; 
	SecureVariable<short> move ; 
	move = 3 ;
	cout << "Correct? move (3) : " << move << endl ; 
	move.DebugPrint() ; 
	cout << "*GetSavedValue() :" << move.GetSavedValue() << endl ; 

	move = move + 5  ; 
	cout << "Correct? move_speed (3+5) : " << move << endl ; 
	move.DebugPrint() ; 

	SecureVariable<double> speed; 
	speed = 1.2E-308 ;
	cout << "Correct? speed (1.2E-308) : " << speed << endl ; 
	speed.DebugPrint() ; 
	speed = speed + 0.1E-308  ; 
	cout << "Correct? speed (1.2E-308 + 0.1E-308) : " << speed << endl ; 
	speed.DebugPrint() ; 


	

	return 0 ; 
}

