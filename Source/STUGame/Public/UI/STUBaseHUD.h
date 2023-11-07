// Shoot Them Up Game.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STUBaseHUD.generated.h"

/**
 *
 */
UCLASS()
class STUGAME_API ASTUBaseHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

private:
    void DrawCrossHair();
};
