

#include "DamagableActor.h"

// Sets default values
ADamagableActor::ADamagableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it. Default message from Unreal Engine
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADamagableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamagableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADamagableActor::takeAttack()
{
	onTakeAttack();
}
