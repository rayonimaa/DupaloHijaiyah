#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SettingsBackendSubsystem.generated.h"

UCLASS()
class USettingsBackendSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    // fungsi buat nyimpen nilai dari slider UI
    UFUNCTION(BlueprintCallable, Category = "Settings|Audio")
    void SetAudioVolume(FName AudioType, float NewVolume);

    // fungsi buat narik nilai ke slider pas menu dibuka
    UFUNCTION(BlueprintPure, Category = "Settings|Audio")
    float GetAudioVolume(FName AudioType);

private:
    // ini map buat nyimpen datanya dengan aman
    UPROPERTY()
    TMap<FName, float> SavedAudioVolumes;
};