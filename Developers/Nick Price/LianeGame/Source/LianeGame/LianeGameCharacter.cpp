#include "LianeGameCharacter.h"


void ALianeGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bIsInsideAnyLight = false;

	TArray<AActor*> PointLights;
	UGameplayStatics::GetAllActorsOfClass(this, APointLight::StaticClass(), PointLights);
	for (int32 i = 0; i < PointLights.Num(); i++)
	{
		APointLight* Light = Cast<APointLight>(PointLights[i]);
		if (Light)
		{
			FVector EyesLocation;
			FRotator EyesRotation;
			GetActorEyesViewPoint(EyesLocation, EyesRotation);

			float Distance = (Light->GetActorLocation() - EyesLocation).Size();
			if (Distance < Light->PointLightComponent->AttenuationRadius)
			{
				FCollisionQueryParams QueryParams;
				QueryParams.AddIgnoredActor(this);
				QueryParams.bTraceComplex = true;

				FHitResult Hit;
				if (!GetWorld()->LineTraceSingleByChannel(Hit,EyesLocation,Light->GetActorLocation(),ECC_Visibility,QueryParams))
				{
					//We are visible to the light
					bIsInsideAnyLight = true;
					break;
				}	
			}
		}
	}
}
