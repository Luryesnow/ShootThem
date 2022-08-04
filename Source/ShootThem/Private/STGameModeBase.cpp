// Shoot Them Game. All Rights Reserved.

#include "STGameModeBase.h"
#include "Player/STPlayerController.h"
#include "Player/STBaseCharacter.h"

ASTGameModeBase::ASTGameModeBase()
{
    DefaultPawnClass = ASTGameModeBase::StaticClass();
    PlayerControllerClass = ASTPlayerController::StaticClass();

}