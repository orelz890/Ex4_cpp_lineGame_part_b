
#include "Contessa.hpp"
#include <iostream>

namespace coup{

    
    Contessa::Contessa(Game &game, std::string name):Player(game, name){
        this->my_role  = "Contessa"; 
        game.add_player(name);
    }

    void Contessa::block(Player& player){
        if (strcmp(player.role().c_str(),"Assassin") != 0)
        {
            throw std::runtime_error("Contessa can only block Assassins!\n");
        }
        std::cout << "in bbbb\n";
        fflush(stdout);
        if (this->my_game->get_is_killed(player.last_action[1]).empty())
        {
            throw std::runtime_error(this->role() + " Can't block " + player.role() + " from this kind of action..\n");
        }
        std::string temp;
        this->my_game->set_kill_list(player.last_action[1],temp);
    }

}
