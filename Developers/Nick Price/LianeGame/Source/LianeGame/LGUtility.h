// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

namespace LGUtility
{
	void LGSay(const FString& string);
	void LGSayLong(const FString& string);
	void LGSay(const FString& string, const float time);
	void LGWarning(const FString& string);

	void PlaySoundComponent(TMap<FName, UAudioComponent*>& SoundComponentList, const FName& SoundName);
	void PlaySoundFireAndForget(UWorld* World,
		TMap<FName, USoundWave*>& FireAndForgetSoundList,
		const FName& SoundName,
		const FVector& Location,
		USoundAttenuation* SoundAttenuation);
}