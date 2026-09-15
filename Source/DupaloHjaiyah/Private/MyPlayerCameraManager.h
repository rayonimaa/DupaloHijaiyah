#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "MyPlayerCameraManager.generated.h"

UCLASS()
class DUPALOHJAIYAH_API AMyPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

protected:
	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;
};