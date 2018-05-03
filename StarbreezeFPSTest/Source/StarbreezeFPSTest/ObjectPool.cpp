// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectPool.h"
#include <algorithm>
#include <cassert>

AObjectPool* AObjectPool::m_pInstance;

// Sets default values
AObjectPool::AObjectPool()
	: m_lLiveList()
	, m_lDeadList()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 
}

// Called when the game starts or when spawned
void AObjectPool::BeginPlay()
{
	Super::BeginPlay();

	assert( nullptr == m_pInstance );
	m_pInstance = this;

	//Init all decals instances and disabled them
	FVector v3Position( 0.0f, 0.0f, 0.0f );
	FRotator v3Rotation( 0.0f, 0.0f, 0.0f );

	for( int i = 0; i < m_iSize; i++ )
	{
		ADecal* pDecalInstance = GetWorld()->SpawnActor<ADecal>( m_cDecalClass, v3Position, v3Rotation );
		ToggleInstanceEnabled( pDecalInstance, false );
		m_lDeadList.push_front( pDecalInstance );
	}
}

// Called every frame
void AObjectPool::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

/* Return an object from pool it there any available, null otherwise */
ADecal * AObjectPool::GetObjFromPool()
{
	ADecal* pRetVal = nullptr;

	if( !m_lDeadList.empty() )
	{
		pRetVal = Cast<ADecal>( m_lDeadList.front() );
		m_lDeadList.pop_front();
		m_lLiveList.push_front( pRetVal );
		ToggleInstanceEnabled( pRetVal, true );
	}

	

	return pRetVal;

}

/* Will return to pool the given ADecal
  Assert to check if decal we are returning is actually in the live list*/

void AObjectPool::ReturnToPool( ADecal* pValue )
{
	auto ElemIt = std::find( m_lLiveList.begin(), m_lLiveList.end(), pValue );
	assert( m_lLiveList.end() != ElemIt ); //if the iterator found is == to list end, then we didn't find the decal in the live List 
	ToggleInstanceEnabled( pValue, false );
//	m_lLiveList.splice( ElemIt, m_lDeadList );
	m_lDeadList.splice( m_lDeadList.begin(), m_lLiveList, ElemIt );

}

/* Toggle the state of the given Decal Actor to make it active / de-activated in the scene
*/
void AObjectPool::ToggleInstanceEnabled( ADecal* pInstance, bool bIsEnabled )
{
	assert( nullptr != pInstance );

	pInstance->SetActorHiddenInGame( !bIsEnabled );
	pInstance->SetActorEnableCollision( bIsEnabled );
	pInstance->SetActorTickEnabled( bIsEnabled );
}

