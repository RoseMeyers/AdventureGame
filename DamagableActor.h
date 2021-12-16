

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamagableActor.generated.h"

UCLASS()
class PROJECT3003_API ADamagableActor : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ADamagableActor();

	//ufunction are useful because they can be called from c++ code and blueprints
	// blueprints are part of a visual scripting system in Unreal Engine that helps develop logic without code. They provide a quick way to create prototypes
	UFUNCTION(BlueprintImplementableEvent, Category = "Attack")
		void onTakeAttack(); 

	// parameters in uproperty are property specifiers. edit anywhere and category will group variables in different property windows. 
	UPROPERTY(EditAnywhere, Category = "Attack")
	bool isAttackable{ true };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void takeAttack();
};
