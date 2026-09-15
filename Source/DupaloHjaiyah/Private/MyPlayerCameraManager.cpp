#include "MyPlayerCameraManager.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"

void AMyPlayerCameraManager::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{
	if (OutVT.Target)
	{
		UCameraComponent* CamComp = OutVT.Target->FindComponentByClass<UCameraComponent>();

		if (!CamComp)
		{
			TArray<UCameraComponent*> Cameras;
			OutVT.Target->GetComponents<UCameraComponent>(Cameras);
			if (Cameras.Num() > 0)
			{
				CamComp = Cameras[0];
			}
		}

		if (CamComp)
		{
			CamComp->GetCameraView(DeltaTime, OutVT.POV);

			// Paksa rotasi kamera untuk selalu menghadap ke posisi Root Target (Boss/Pusat)
			FVector CamLoc = OutVT.POV.Location;
			FVector TargetLoc = OutVT.Target->GetActorLocation();

			// Hitung rotasi dari posisi Kamera menuju ke Boss
			FRotator LookAtRot = (TargetLoc - CamLoc).Rotation();

			// Override rotasinya
			OutVT.POV.Rotation = LookAtRot;

			return;
		}
	}

	// INI BAGIAN YANG HILANG DI KODE KAMU SEBELUMNYA:
	Super::UpdateViewTargetInternal(OutVT, DeltaTime);
}