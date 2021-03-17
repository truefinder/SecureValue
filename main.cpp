
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

	// test variable value 


	cout<< "*size of each short, int, long, float, long long, double : "  ; 
	cout<< sizeof (short) << "," << sizeof(int) << "," << sizeof(long) <<"," << sizeof(float) << "," << sizeof(long long) << "," << sizeof(double) << endl ; 

	cout << "<unsigned int>================================================" << endl ;
	SecureFixed<unsigned int> limit_time ;
	limit_time = 60 ; 
	cout << "limit_time : " << limit_time << endl ;
	limit_time.DebugPrint(); 

	cout << "<float>=======================================================" << endl ;
	SecureFixed<float> main_fps ; 
	main_fps = 50.20 ; 
	cout << "main_fps (50.20) : " << main_fps << endl ; 
	main_fps.DebugPrint() ; 

	cout << "<int>==============--=========================================" << endl ;
	SecureVariable<int> monster_hp ;
	monster_hp = 11090 ; 
	cout << "monster_hp (11090) : " << monster_hp << endl ; 
	monster_hp.DebugPrint() ; 
	cout << "<int> calculation=============================================" << endl ;
	monster_hp = monster_hp - 2948 ; 
	cout << "monster_hp (11090 - 2948) : " << monster_hp << endl ; 
	monster_hp.DebugPrint() ; 

	cout << "<float>=======================================================" << endl ;
	SecureVariable<float> move_speed ; 
	move_speed = 20.33 ;
	cout << "move_speed (20.33) : " << move_speed << endl ; 
	move_speed.DebugPrint() ; 
	cout << "<float> calculation ==========================================" << endl ;
	move_speed = move_speed + 10  ; 
	cout << "move_speed (20.33+10) : " << move_speed << endl ; 
	move_speed.DebugPrint() ; 


	cout << "<short>=======================================================" << endl ;
	SecureVariable<short> move ; 
	move = 3 ;
	cout << "move (3) : " << move << endl ; 
	move.DebugPrint() ; 

	cout << "<short> calculation ==========================================" << endl ;
	move = move + 5  ; 
	cout << "move_speed (3+5) : " << move << endl ; 
	move.DebugPrint() ; 

	cout << "<double>======================================================" << endl ;
	SecureVariable<double> speed; 
	speed = 1.2E-308 ;
	cout << "speed (1.2E-308) : " << speed << endl ; 
	speed.DebugPrint() ; 
	cout << "<double> calculation =========================================" << endl ;
	speed = speed + 0.1E-308  ; 
	cout << "speed (1.2E-308 + 0.1E-308) : " << speed << endl ; 
	speed.DebugPrint() ; 


	return 0 ; 
}

