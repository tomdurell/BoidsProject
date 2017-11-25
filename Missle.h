#pragma once
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Core/ProcessUtils.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Input/Controls.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Container/Str.h>

namespace Urho3D
{
	class Node;
	class Scene;
	class RigidBody;
	class CollisionShape;
	class ResourceCache;
}

// All Urho3D classes reside in namespace Urho3D
using namespace Urho3D;

class Missle
{
	Node* pNode;
	RigidBody* pRigidBody;
	CollisionShape* pCollisionShape;
	StaticModel* pObject;


public:
	bool inFlight;
	float flightTime;
	Vector3 Force;

	//constructor
	Missle()
	{
		pNode = NULL;
		pRigidBody = NULL;
		pCollisionShape = NULL;
		pObject = NULL;
	}

	~Missle()
	{
	}

	void Initialise(ResourceCache* pRes, Scene* pScene, Node* cameraNode_)
	{
		pNode = pScene->CreateChild("missleNode");
		pNode->SetScale(2.0f);
		pObject = pNode->CreateComponent<StaticModel>();
		pObject->SetModel(pRes->GetResource<Model>("Models/Plane.mdl")); // model for the boid
		pObject->SetMaterial(pRes->GetResource<Material>("Materials/Stone.xml")); // material "skin" for the boid
		pObject->SetCastShadows(true);
		pRigidBody = pNode->CreateComponent<RigidBody>();
		pRigidBody->SetCollisionLayer(2);
		pCollisionShape = pNode->CreateComponent<CollisionShape>();
		pCollisionShape->SetTriangleMesh(pObject->GetModel(), 0);
		pRigidBody->SetPosition(cameraNode_->GetPosition());
		pRigidBody->SetLinearVelocity(cameraNode_->GetDirection().Normalized()*20.0f);
	}

};