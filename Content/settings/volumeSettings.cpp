#include "volumeSettings.h"

void USettingsBackendSubsystem::SetAudioVolume(FName AudioType, float NewVolume)
{
    // nyimpen atau nimpa nilai volume berdasarkan id/nama (Master, SFX, BGM)
    SavedAudioVolumes.Add(AudioType, NewVolume);
}

float USettingsBackendSubsystem::GetAudioVolume(FName AudioType)
{
    // ngecek kalau datanya ada, balikin nilainya. kalau belum ada, kasih default 1.0 (full)
    if (SavedAudioVolumes.Contains(AudioType))
    {
        return SavedAudioVolumes[AudioType];
    }
    return 1.0f; 
}