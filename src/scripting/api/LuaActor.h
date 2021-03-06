#ifndef MILK_LUA_ACTOR_H
#define MILK_LUA_ACTOR_H

#include <string>

namespace milk
{
    class Actor;

    namespace lua
    {
        namespace actor
        {
            std::string name(Actor& actor);

            void setAsCameraTarget(Actor& actor);

            void move(Actor& actor, float x, float y);

            void setAnimation(Actor& actor, const std::string& name);

            void flipX(Actor& actor);

            void flipY(Actor& actor);
        }
    }
}


#endif
