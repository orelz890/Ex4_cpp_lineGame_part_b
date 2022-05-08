
#include "doctest.h"
#include <string>
#include <algorithm>

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"


using namespace std;
using namespace coup;


TEST_CASE("Good tests"){
    Game g{};

    Ambassador ambassador{g, "amb"};
    Assassin assassin{g, "ass"};
    Contessa contessa{g, "con"};
    Captain captain{g, "cap"};
    Duke duke{g, "duk"};

    CHECK_NOTHROW(ambassador.income());    
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(contessa.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(duke.income());
    CHECK(ambassador.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(contessa.coins() == 1);
    CHECK(captain.coins() == 1);
    CHECK(duke.coins() == 1);

    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK(ambassador.coins() == 3);
    CHECK(assassin.coins() == 3);
    CHECK(contessa.coins() == 3);
    CHECK(captain.coins() == 3);
    CHECK(duke.coins() == 3);

    CHECK_NOTHROW(ambassador.transfer(duke, ambassador));
    CHECK(ambassador.coins() == 4);
    CHECK(duke.coins() == 2);
    CHECK_NOTHROW(assassin.coup(duke));
    CHECK_NOTHROW(contessa.block(assassin));
    CHECK_NOTHROW(contessa.income());
    CHECK(contessa.coins() == 4);

    CHECK_NOTHROW(captain.steal(contessa));
    CHECK_NOTHROW(ambassador.block(captain));
    CHECK(captain.coins() == 3);
    CHECK(ambassador.coins() == 4);

    CHECK_NOTHROW(duke.tax());
    CHECK(duke.coins() == 5);

}

TEST_CASE("Bad tests"){

    SUBCASE("Illegal block"){
        Game g{};

        Duke duke{g, "duk"};
        Assassin assassin{g, "ass"};
        Contessa contessa{g, "con"};
        Ambassador ambassador{g, "amb"};
        Captain captain{g, "cap"};

        
        CHECK_NOTHROW(duke.income());
        CHECK_THROWS(ambassador.block(duke));
        CHECK_THROWS(captain.block(duke));
        CHECK_THROWS(contessa.block(duke));

        assassin.income();
        assassin.income();
        assassin.income();

        CHECK_NOTHROW(assassin.coup(duke));
        CHECK_THROWS(ambassador.block(assassin));
        CHECK_THROWS(captain.block(assassin));
        CHECK_THROWS(duke.block(assassin));

        CHECK_NOTHROW(contessa.block(assassin));
        CHECK_NOTHROW(contessa.foreign_aid());

        CHECK_THROWS(ambassador.block(contessa));
        CHECK_THROWS(contessa.block(contessa));
        CHECK_THROWS(captain.block(contessa));

        CHECK_NOTHROW(ambassador.transfer(duke, ambassador));
        CHECK_THROWS(contessa.block(ambassador));
        CHECK_THROWS(captain.block(ambassador));
        CHECK_THROWS(duke.block(ambassador));

        CHECK_NOTHROW(captain.steal(assassin));
        CHECK_THROWS(contessa.block(captain));
        CHECK_THROWS(duke.block(captain));

        CHECK_NOTHROW(duke.tax());
        CHECK_THROWS(ambassador.block(duke));
        CHECK_THROWS(contessa.block(duke));
        CHECK_THROWS(captain.block(duke));
        

    }

    SUBCASE("Not your turn!"){
        Game g{};

        Duke duke{g, "duk"};
        Assassin assassin{g, "ass"};
        Contessa contessa{g, "con"};
        Ambassador ambassador{g, "amb"};
        Captain captain{g, "cap"};
        
        CHECK_THROWS(assassin.income());
        CHECK_THROWS(assassin.foreign_aid());
        CHECK_THROWS(assassin.coup(ambassador));
        CHECK_THROWS(ambassador.income());
        CHECK_THROWS(ambassador.foreign_aid());
        CHECK_THROWS(ambassador.coup(assassin));
        CHECK_THROWS(captain.income());
        CHECK_THROWS(captain.foreign_aid());
        CHECK_THROWS(captain.coup(ambassador));
        CHECK_THROWS(contessa.income());
        CHECK_THROWS(contessa.foreign_aid());
        CHECK_THROWS(contessa.coup(ambassador));
    }


}
