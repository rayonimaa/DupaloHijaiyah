#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AudioBackend.generated.h"

UCLASS()
class DUPALOHJAIYAH_API UAudioBackend : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase &Collection) override;

	// Music volume setting
	UPROPERTY(BlueprintReadWrite, Category = "Audio Settings")
	float MusicVolume;

	// Sound Effects volume setting
	UPROPERTY(BlueprintReadWrite, Category = "Audio Settings")
	float SFXVolume;
};