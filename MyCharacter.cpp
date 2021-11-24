#include "MyCharacter.h"
#include "Engine/world.h"  // removes error on playerController
#include "DamagableActor.h" 
#include "GameFramework/PlayerController.h" // UnrealEngine Documentation guide on player viewpoints
#include "Engine/world.h"


#define OUT // Udemy Academy lesson on C++ 


/** Procedural programming specifies exactly what steps need to be taken to reach a goal.The program is broken down into smaller parts to get point A to point B.
* Object oriented programming doesn't focus on just solving a specific problem. It thinks of functions as machines that can be applied and useful to multiple programs **/

/* The visibility inheritance model is used to show how base classes are related to derived classes through inheritance. */

/* Dynamic dispatch (late binding) occurs at run time and is the action of choosing a method based on the type of object the method is inkvoked on.  */

/*  A subtype inherits all features from its supertypes. When an object has mulitple direct subtypes, mulitple inheritance is used. */


// Overload a constructor!




// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// ProgrammingHustle Lesson on vectors
	// Get player viewpoint, prints in output log player coordinates, from Udemy course .
	// Refer to unreal engine documentation on FVectors for further notes. 
	FVector PlayerViewpointLocation; // a vector in 3D space has 3 components (x,y,z). A vector is a c++ struct so it has default F prefix. 
	FRotator PlayerViewpointRotation; // Implements a container for rotation info, refer to FRotator Unreal Engine documentation for further notes. 
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint( OUT PlayerViewpointLocation, OUT PlayerViewpointRotation); 
	UE_LOG(LogTemp, Warning, TEXT("Location:%s Rotation:%s"), *PlayerViewpointLocation.ToString(), *PlayerViewpointRotation.ToString()); 
}

// Called to bind functionality to input
 void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Super is important for inheriting functions from a parent class. 
	// Geeksforgeeks: super class: the class whose properties are inherited by sub class is called base class, or super class.
	Super::SetupPlayerInputComponent(PlayerInputComponent);

//	PlayerInputComponent->BindAction(TEXT("Move_Forward"), this, AMyCharacter::Move_Forward);
		// To set in unreal engine, go to edit, projectsettings, input and set axis mappings.
//}

//void AMyCharacter::Move_Forward(float AxisValue) //not finished, add other directions and jump
//{
	// move forward method needs move forward vector of actor, use Get and mulitply by axis value (I chose 1) to move player set speed, negative vector(-1) moves backwards.
//	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AMyCharacter::fireWeapon() {
	// crate damagable class

	FHitResult hit = InstantShot(); 

	ADamagableActor* hitActor = Cast<ADamagableActor>(hit.Actor); // Polymorpishm, damagable actor inherits from actor.
	if (hitActor && hitActor->isAttackable)  //Devslopes lesson, calls takeAttack function from DamagableActor class.
	{
		hitActor->takeAttack(); // actor (block) that's hit by player will be attacked and disappear.
	}
}



FHitResult AMyCharacter::InstantShot() 
{
	FVector cameraLocation;
	FRotator cameraRotation; //use to find which direction is forward
	FVector endTrace = FVector::ZeroVector; 


	APlayerController* const playerController = GetWorld()->GetFirstPlayerController();
	if (playerController) {
		playerController->GetPlayerViewPoint(cameraLocation, cameraRotation); 
		endTrace = cameraLocation + (cameraRotation.Vector() * weaponRange);  // Udemy course
		// calling .Vector will get forward  direction of rotation, multiplied by weapon range.
	}


	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(instantShot), true, GetInstigator()); //Devslopes
	FHitResult hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(hit, cameraLocation, endTrace, ECC_Visibility, traceParams);

	return hit;
}