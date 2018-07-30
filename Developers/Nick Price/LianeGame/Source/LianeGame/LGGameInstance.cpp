

#include "LGGameInstance.h"
#include "LianeGame.h"
#include "LGUtility.h"


//------------------------------------------------------------
//------------------------------------------------------------
FSoundResult::FSoundResult() :
	bSuccess(false),
	bNew(false),
	SoundWave(nullptr)
{
}

//------------------------------------------------------------
//------------------------------------------------------------
ULGGameInstance::ULGGameInstance() :
	PersistentData()
{
}

//------------------------------------------------------------
//------------------------------------------------------------
FSoundResult ULGGameInstance::AddToSoundWaveList(TAssetPtr<USoundWave> SoundWaveAsset)
{
	FSoundResult Result;
	USoundWave** pSoundWave = PersistentData.SoundWaveList.Find(SoundWaveAsset);

	// if asset is found, retrieve the loaded sound
	if (pSoundWave)
	{
		Result.SoundWave = *pSoundWave;
	}
	// if asset is not found, load the sound
	else
	{
		bool bManageActiveHandle = true;
		UObject* ResultObj = PersistentData.StreamableManager.SynchronousLoad(SoundWaveAsset.ToStringReference());
		if (ResultObj)
		{
			Result.SoundWave = Cast<USoundWave>(ResultObj);
			if (Result.SoundWave)
			{
				Result.bNew = true;
				PersistentData.SoundWaveList.Add(SoundWaveAsset, Result.SoundWave);
			}
		}
	}

	return Result;
}

//------------------------------------------------------------
//------------------------------------------------------------
FSoundResult ULGGameInstance::GetSoundWaveFromList(TAssetPtr<USoundWave> SoundWaveAsset)
{
	FSoundResult Result;
	USoundWave** pSoundWave = PersistentData.SoundWaveList.Find(SoundWaveAsset);

	// if asset is found, retrieve the loaded sound
	if (pSoundWave)
	{
		Result.bSuccess = true;
		Result.SoundWave = *pSoundWave;
	}

	return Result;
}

//------------------------------------------------------------
//------------------------------------------------------------
LGPersistentData::LGPersistentData() :
	StreamableManager()
{
}