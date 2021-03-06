#ifndef MILK_CAMERA_TESTS_H
#define MILK_CAMERA_TESTS_H

#include "gtest/gtest.h"

#include "events/EventQueue.h"
#include "scene/Camera.h"
#include "scene/Actor.h"
#include "scene/Scene.h"

class CameraTests : public ::testing::Test
{
};

TEST_F(CameraTests, Ctor_Constructs)
{
    milk::EventQueue eventQueue;
    milk::Scene scene{eventQueue, 640, 360};
    ASSERT_NO_THROW(milk::Camera(scene, 640, 360));
}

TEST_F(CameraTests, Position_SetsPosition)
{
    // Arrange
    milk::EventQueue eventQueue;
    milk::Scene scene{eventQueue, 640, 360};
    milk::Camera camera{scene, 640, 360};

    // Act
    camera.position(10, 10);

    // Assert
    ASSERT_EQ(10, camera.position().x);
    ASSERT_EQ(10, camera.position().y);
}

#endif
