#include "AudioBackend.h"

void UAudioBackend::Initialize(FSubsystemCollectionBase &Collection)
{
	Super::Initialize(Collection);

	MusicVolume = 100.0f;
	SFXVolume = 1.0f;
}