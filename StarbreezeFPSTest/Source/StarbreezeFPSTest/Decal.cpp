// Fill out your copyright notice in the Description page of Project Settings.

#include "Decal.h"
#include "ObjectPool.h"

// Sets default values
ADecal::ADecal()
	: m_fTimer( 0.0f )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if( m_fTimeToLive <= m_fTimer )
	{
		m_fTimer = 0.0f;
		AObjectPool::GetInstance()->ReturnToPool( this );
	}
	else
	{
		m_fTimer += DeltaTime;
	}
}

