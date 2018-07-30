
#include "LGActor.h"
#include "LianeGame.h"
#include "LGUtility.h"
#include "LianeGameGameMode.h"


ALGActor::ALGActor()
{
	PrimaryActorTick.bCanEverTick = true;

	LGOwner = nullptr;
	StaticMeshComponent = nullptr;
}

void ALGActor::BeginPlay()
{
	Super::BeginPlay();
	for (auto It = SoundComponentAssetList.CreateConstIterator(); It; ++It)
	{
		CreateSoundComponent(It->Key, It->Value);
	}

	for (auto It = FireAndForgetSoundAssetList.CreateConstIterator(); It; ++It)
	{
		CreateFireAndForgetSound(It->Key, It->Value);
	}
}

void ALGActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALGActor::SetLGOwner(AActor* LGOwner_ext)
{
	LGOwner = LGOwner_ext;
}

void ALGActor::UnSetLGOwner()
{
	LGOwner = nullptr;
}

AActor* ALGActor::GetLGOwner()
{
	return LGOwner;
}

void ALGActor::PlaySoundComponent(const FName& SoundName)
{
	LGUtility::PlaySoundComponent(SoundComponentList, SoundName);
}

void ALGActor::PlaySoundFireAndForget(const FName& SoundName)
{
	LGUtility::PlaySoundFireAndForget(this->GetWorld(),
		FireAndForgetSoundList,
		SoundName,
		GetActorLocation(),
		SoundAttenuation);
}

UAudioComponent* ALGActor::CreateSoundComponent(FName SoundName, TAssetPtr<USoundWave> SoundWaveAsset)
{

	FSoundResult Result;
	ULGGameInstance* LGGameInstance = Cast<ULGGameInstance>(GetGameInstance());
	if (LGGameInstance)
	{
		Result = LGGameInstance->AddToSoundWaveList(SoundWaveAsset);
	}

	UAudioComponent* SoundComp = NewObject<UAudioComponent>(this, UAudioComponent::StaticClass());

	if (Result.SoundWave && SoundComp)
	{
		SoundComp->SetSound(Result.SoundWave);
		SoundComp->SetupAttachment(RootComponent);
		SoundComp->SetRelativeLocation(FVector(0.0f));
		SoundComp->bAutoActivate = false;
		//SoundComp->AdjustAttenuation(SoundAttenuation->Attenuation);
		SoundComp->RegisterComponent(); // must occur after audio component is properly set up

		SoundComponentList.Add(SoundName, SoundComp);
	}

	if (!Result.bNew)
	{
		// LGUtility::LGSay("Asset of " + SoundName.ToString() + " is not new.");
	}

	return SoundComp;
}

USoundWave* ALGActor::CreateFireAndForgetSound(FName SoundName, TAssetPtr<USoundWave> SoundWaveAsset)
{
	FSoundResult Result;
	ULGGameInstance* LGGameInstance = Cast<ULGGameInstance>(GetGameInstance());
	if (LGGameInstance)
	{
		Result = LGGameInstance->AddToSoundWaveList(SoundWaveAsset);
	}

	if (Result.SoundWave)
	{
		FireAndForgetSoundList.Add(SoundName, Result.SoundWave);
	}

	if (!Result.bNew)
	{
		// LGUtility::LGSay("Asset of " + SoundName.ToString() + " is not new.");
	}

	return Result.SoundWave;
}

UStaticMeshComponent*& ALGActor::GetStaticMeshComponent()
{
	return StaticMeshComponent;
}