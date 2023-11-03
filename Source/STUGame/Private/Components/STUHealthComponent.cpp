// Shoot Them Up Game.

#include "Components/STUHealthComponent.h"
#include <GameFramework/Actor.h>
#include <Dev/STUFireDamageType.h>
#include <Dev/STUIceDamageType.h>

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponents, All, All);

USTUHealthComponent::USTUHealthComponent()
{

    PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void USTUHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
    OnHealthChange.Broadcast(Health);

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
    }
}

void USTUHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0 || IsDead()) return;
    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
    OnHealthChange.Broadcast(Health);


    if (IsDead())
    {
        OnDeath.Broadcast();
    }
}
