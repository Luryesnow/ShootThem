// Shoot Them Game. All Rights Reserved.


#include "Player/STBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASTBaseCharacter::ASTBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void ASTBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASTBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	{
        PlayerInputComponent->BindAxis("MoveForward", this, &ASTBaseCharacter::MoveForward);
        PlayerInputComponent->BindAxis("MoveRight", this, &ASTBaseCharacter::MoveRight);
        PlayerInputComponent->BindAxis("LookUp", this, &ASTBaseCharacter::AddControllerPitchInput);
        PlayerInputComponent->BindAxis("TurnAround", this, &ASTBaseCharacter::AddControllerYawInput);
        PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASTBaseCharacter::Jump);

        PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASTBaseCharacter::OnStartRunning);
        PlayerInputComponent->BindAction("Run", IE_Released, this, &ASTBaseCharacter::OnStopRunning);

 
    }


}

void ASTBaseCharacter::MoveForward(float Amount)
{
    IsMovingForward = Amount > 0.0f;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ASTBaseCharacter::OnStartRunning()
{
    WantsToRun = true;
}

void ASTBaseCharacter::OnStopRunning()
{
    WantsToRun = false;
}


bool ASTBaseCharacter::IsRunning() const

{
    return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}

