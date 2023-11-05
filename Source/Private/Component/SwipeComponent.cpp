#include "Component/SwipeComponent.h"


USwipeComponent::USwipeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USwipeComponent::BeginPlay()
{
	Super::BeginPlay();
	
	BindTouch(IE_Pressed, this, &USwipeComponent::TouchPressed);
	BindTouch(IE_Repeat, this, &USwipeComponent::TouchMove);
	BindTouch(IE_Released, this, &USwipeComponent::TouchReleased);
}

void USwipeComponent::TouchPressed(ETouchIndex::Type FingerIndex, FVector Location)
{
	TouchPressedLocation = Location;
}

void USwipeComponent::TouchMove(ETouchIndex::Type FingerIndex, FVector Location)
{
	FVector2D TouchDelta
	(
		Location.X - TouchPressedLocation.X,
		Location.Y - TouchPressedLocation.Y
	);

	if(TouchDelta.Size() > MinSwipeDistance && !bSwiped)
	{
		if(abs(TouchDelta.X) >= abs(TouchDelta.Y))
		{
			TouchDelta.X > 0 ? OnSwipeRight.Broadcast(FingerIndex, Location) : OnSwipeLeft.Broadcast(FingerIndex, Location); 
		}
		else
		{
			TouchDelta.Y > 0 ? OnSwipeUp.Broadcast(FingerIndex, Location) : OnSwipeDown.Broadcast(FingerIndex, Location);
		}
		bSwiped = true;
	}
	
}

void USwipeComponent::TouchReleased(ETouchIndex::Type FingerIndex, FVector Location)
{
	bSwiped = false;
}

