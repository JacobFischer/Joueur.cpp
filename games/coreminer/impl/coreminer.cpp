// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "coreminer.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace coreminer
{

//register the game
Game_registry registration("Coreminer",
                           "397e64cb9b2f8d76a04e0f32823456fad3d0dd8902b39c6f4d3bc3d636ec2bfd",
                           std::unique_ptr<Coreminer>(new Coreminer));

std::unique_ptr<Base_ai> Coreminer::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Coreminer::generate_object(const std::string& type)
{
    if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Job")
    {
        return std::make_shared<Job_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    else if(type == "Tile")
    {
        return std::make_shared<Tile_>();
    }
    else if(type == "Unit")
    {
        return std::make_shared<Unit_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // coreminer

} // cpp_client
