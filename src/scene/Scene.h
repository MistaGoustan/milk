#ifndef MILK_SCENE_H
#define MILK_SCENE_H

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Camera.h"

#include "graphics/Tilemap.h"
#include "math/Rectangle.h"
#include "utilities/IdGenerator.h"

namespace milk
{
    class Actor;
    class EventQueue;

    class Scene
    {
    public:
        Scene(EventQueue& eventQueue, unsigned virtualWidth, unsigned virtualHeight);

        ~Scene();

        // Spawns a new actor in the games current scene.
        // Components are to be added immediately after spawned actor is returned.
        Actor* spawnActor(const std::string& name);

        // Attempts to destroy and actor with the given id.
        // Returns true if successful.
        bool destroyActor(int id);

        // Attempts to find an actor with the given name.
        // Returns nullptr if not actor is found.
        Actor* findActor(const std::string& name) const;

        // Returns the scenes camera.
        Camera& camera();

        // Returns the scenes tilemap.
        Tilemap& tilemap();

        // Updates the scenes internal lists after spawning and destroying actors.
        void syncActorLists();

        // Return the scene boundaries.
        Rectangle bounds() const;

        // Mark the scene and ended.
        void end();

    private:
        EventQueue& eventQueue_;

        IdGenerator idGenerator_;
        Camera camera_;
        Tilemap tilemap_;

        bool ended_;

        std::unordered_map<int, std::unique_ptr<Actor>> actorsById_;
        std::vector<std::unique_ptr<Actor>> actorsToSpawn_;
        std::vector<int> actorsToDestroy_;
    };
}

#endif
