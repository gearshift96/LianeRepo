// Fill out your copyright notice in the Description page of Project Settings.


#include "LGUtility.h"
#include "LianeGame.h"
#include "LGGameInstance.h"


namespace LGUtility
{
	void LGSay(const FString & string)
	{
		LGSay(string, 5.0f);
	}
	void LGSayLong(const FString & string)
	{
		LGSay(string, 600.0f);
	}
	void LGSay(const FString & string, const float time)
	{
		GEngine->AddOnScreenDebugMessage(-1, time, FColor::Cyan, string);
	}
	void LGWarning(const FString & string)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, string);
	}
	void PlaySoundComponent(TMap<FName, UAudioComponent*>& SoundComponentList, const FName & SoundName)
	{
		bool Found = false;
		if (SoundComponentList.Contains(SoundName))
		{
			UAudioComponent* SoundComp = SoundComponentList[SoundName];

			// allow sound pile-up
			if (SoundComp)
			{
				Found = true;
				LGUtility::LGSay(SoundName.ToString());
				SoundComp->Play(0.0f);
			}
		}

		if (!Found)
		{
			LGUtility::LGWarning("sound not found.");
		}
	}
	//------------------------------------------------------------
	// FIXME: play sound at location may crash the game
	//------------------------------------------------------------
	void PlaySoundFireAndForget(UWorld* World, TMap<FName, USoundWave*>& FireAndForgetSoundList, const FName& SoundName, const FVector& Location, USoundAttenuation* SoundAttenuation)
	{
		bool Found = false;
		if (FireAndForgetSoundList.Contains(SoundName))
		{
			USoundWave* SoundWave = FireAndForgetSoundList[SoundName];

			// allow sound pile-up
			if (SoundWave)
			{
				Found = true;
				LGUtility::LGSay(SoundName.ToString());

				// FIXME: ATTENUATION CAUSES THE GAME TO CRASH RANDOMLY
				//UGameplayStatics::PlaySoundAtLocation(World,
				//    SoundWave,
				//    Location,
				//    FRotator::ZeroRotator,
				//    1.0f,
				//    1.0f,
				//    0.0f,
				//    SoundAttenuation);

				UGameplayStatics::PlaySound2D(World, SoundWave);
			}
		}

		if (!Found)
		{
			LGUtility::LGWarning("sound not found.");
		}
	}
}