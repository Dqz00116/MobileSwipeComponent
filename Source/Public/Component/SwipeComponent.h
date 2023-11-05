#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "SwipeComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SKIMMINGSTONES_API USwipeComponent : public UInputComponent
{
	GENERATED_BODY()

public:
	
	USwipeComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinSwipeDistance { 10.f };

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSwipeUp, ETouchIndex::Type, FingerIndex, FVector, Location);
	UPROPERTY(BlueprintAssignable)
	FOnSwipeUp OnSwipeUp;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSwipeDown, ETouchIndex::Type, FingerIndex, FVector, Location);
	UPROPERTY(BlueprintAssignable)
	FOnSwipeDown OnSwipeDown;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSwipeLeft, ETouchIndex::Type, FingerIndex, FVector, Location);
	UPROPERTY(BlueprintAssignable)
	FOnSwipeLeft	OnSwipeLeft;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSwipeRight, ETouchIndex::Type, FingerIndex, FVector, Location);
	UPROPERTY(BlueprintAssignable)
	FOnSwipeRight	OnSwipeRight;

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void TouchPressed(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION()
	void TouchMove(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION()
	void TouchReleased(ETouchIndex::Type FingerIndex, FVector Location);

private:
	
	FVector TouchPressedLocation {FVector::ZeroVector};

	bool bSwiped {false};
	
};
