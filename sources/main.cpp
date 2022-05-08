// // How to run: 
// // g++ -o my_main.o main.cpp Ambassador.cpp Ambassador.hpp Assassin.cpp Assassin.hpp Captain.cpp Captain.hpp Contessa.cpp Contessa.hpp Duke.cpp Duke.hpp Game.cpp Game.hpp Player.cpp Player.hpp

// #include <map>
// #include <string>
// #include <iostream>
// #include "Player.hpp"
// #include "Duke.hpp"
// #include "Assassin.hpp"
// #include "Ambassador.hpp"
// #include "Captain.hpp"
// #include "Contessa.hpp"
// #include "Game.hpp"
// using namespace coup;
// using namespace std;


// int main(){

//     // std::map<std::string, std::string> x;
//     // x["orel"] = "kkk";
//     // std::cout << x["orel"];
//     // x.erase("orel");
//     // std::cout << x.size();

// 	Game game_1{};

// 	Duke duke{game_1, "Moshe"};
// 	Assassin assassin{game_1, "Yossi"};
// 	Ambassador ambassador{game_1, "Meirav"};
// 	Captain captain{game_1, "Reut"};
// 	Contessa contessa{game_1, "Gilad"};

//     cout<< "Now it's " << game_1.turn() << "'s turn\n";

//     cout << "The num of active players is: " << game_1.players().size() << '\n';

// 	// for(string name : duke.get_game().players()){
// 	// 	cout << name << endl;
// 	// }

//     duke.income();
// 	assassin.income();
// 	ambassador.income();
// 	captain.income();
// 	contessa.income();
// 	// cout << "The dukes has " << duke.coins() << " coins\n";
//     duke.income();
// 	assassin.income();
// 	ambassador.income();
// 	captain.income();
// 	contessa.income();

//     duke.income();
// 	assassin.income();
// 	ambassador.income();
// 	captain.income();
// 	contessa.income();

//     duke.income();
// 	assassin.coup(duke);
// 	ambassador.income();
// 	captain.income();
// 	contessa.income();

// 	duke.income();
// 	for(string name : duke.get_game().players()){
// 		cout << name << endl;
// 	}
		
// 	return 0;
// }

